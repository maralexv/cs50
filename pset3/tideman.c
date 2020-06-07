#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
int isinlosers(int num);
int isinwinners(int num);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    // print preferences
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
            if (j == candidate_count - 1)
            {
                printf("\n");
            }
        }
    }
    printf("\n");

    add_pairs();
    sort_pairs();
    lock_pairs();

    // print locked after
    printf("locked after\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", locked[i][j]);
            if (j == candidate_count - 1)
            {
                printf("\n");
            }
        }
    }
    printf("\n");

    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if ((preferences[i][j] != 0 || preferences[j][i] != 0) && preferences[i][j] != preferences[j][i])
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
            }
        }
    }
    // print pairs
    printf("%d pairs:\n", pair_count);
    for (int i=0; i<pair_count; i++)
    {
        printf("[%i]w: %d, [%i]l: %d\n", i, pairs[i].winner, i, pairs[i].loser);
    }
    printf("\n");
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j+1].winner][pairs[j+1].loser])
            {
                // swap if greater is at the rear position
                pair swapper = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = swapper;
            }
        }
    }
    // print pairs
    printf("pairs sorted:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("[%i]w: %d, [%i]l: %d\n", i, pairs[i].winner, i, pairs[i].loser);
    }
    printf("\n");
    return;
}

int isinlosers(int num)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (pairs[i].loser == num)
        {
            return 1;
        }
    }
    return 0;
}

int isinwinners(int num)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (pairs[i].winner == num)
        {
            return 1;
        }
    }
    return 0;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    locked[pairs[0].winner][pairs[0].loser] = true;
    locked[pairs[1].winner][pairs[1].loser] = true;
    for (int i = 2; i < pair_count; i++)
    {
        // If pairs[i].winner is not in locked losers AND pairs[i].loser is no in locked winners
        if (isinlosers(pairs[i].winner) == 0 && isinwinners(pairs[i].loser) == 0)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

int iswinnerinlosers(int winner)
{
    for (int j = 0; j < pair_count; j++)
    {
        if (locked[j][winner] == 1)
        {
            return 1;
        }
    }
    return 0;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // If pair belongs to locked AND winner is not among locked losers
        if (locked[pairs[i].winner][pairs[i].loser] == 1 && iswinnerinlosers(pairs[i].winner) == 0)
        {
            printf("%s\n", candidates[pairs[i].winner]);
        }
    }
    return;
}
