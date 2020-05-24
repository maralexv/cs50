#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Set max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;
// Define array of candidates
candidate CANDIDATES[MAX];
// Number of candidates
int CANDIDATE_COUNT;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    // Populate array of candidates
    CANDIDATE_COUNT = argc - 1;
    if (CANDIDATE_COUNT > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        CANDIDATES[i].name = argv[i + 1];
        CANDIDATES[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        if (CANDIDATES[i].name == name)
        {
            CANDIDATES[i].votes++;
            return false;
        }
    }
    return true;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int k = 0;
    candidate winners[] = {CANDIDATES[0].name, CANDIDATES[0].votes};
    // Find the candidateb with highest number of votes
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        if (CANDIDATES[i + 1].votes > CANDIDATES[i].votes)
        {
            winners[k].name = CANDIDATES[i + 1].name;
            winners[k].votes = CANDIDATES[i + 1].votes;
        }
    }
    // Check if ay other candidate has the same nukber of votes as the winner
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        if (CANDIDATES[i + 1].votes == winners[k].votes)
        {
            k++;
            winners[k].name = CANDIDATES[i + 1].name;
            winners[k].votes = CANDIDATES[i+1].votes;
        }
    }
    // Pront the winner (or winners)
    int winners_count = sizeof(winners) / sizeof(winners[0]);
    for (int i = 0; i < winners_count; i++)
    {
        printf("%s\n", winners[i].name);
    }
    return;
}
