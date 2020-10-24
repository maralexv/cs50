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
        if (strcmp(CANDIDATES[i].name, name) == 0)
        {
            CANDIDATES[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int k = 0;
    // Find the highest vote
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        if (CANDIDATES[i].votes > k)
        {
            k = CANDIDATES[i].votes;
        }
    }
    // If the highest vote = 0, no votes were casted
    if (k == 0)
    {
        printf("No valid votes casted!\n");
        return;
    }
    // Print all the winners
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        if (CANDIDATES[i].votes == k)
        {
            printf("%s\n", CANDIDATES[i].name);
        }
    }
    return;
}
