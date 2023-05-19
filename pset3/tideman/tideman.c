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
}
pair;

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

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidate_count;i++){
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
    for(int i=0;i<candidate_count;i++){
        for(int j=0;j<candidate_count;j++){

            if(i<j){
                preferences[ranks[i]][ranks[j]]++;
            }
            else if(i==j){
                preferences[ranks[i]][ranks[j]]=0;
            }
        }

    }

/*print preferencies
    for(int i=0;i<candidate_count;i++){
         for(int j=0;j<candidate_count;j++){

            //preferences[ranks[i]][ranks[j]];
            printf("%i : %i = %i \n",ranks[i],ranks[j],preferences[ranks[i]][ranks[j]]);
         }

    }*/
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for(int i=0;i<candidate_count;i++){
         for(int j=0;j<candidate_count;j++){

            if(preferences[i][j] > preferences[j][i]){

                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
                printf("count: %i \n",pair_count);

            }

         }

    }

    /*for(int i=0;i<pair_count;i++){

        printf("%i wins over %i \n",pairs[i].winner,pairs[i].loser);

    }*/
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair auxpair;
    for(int i=0;i<pair_count;i++){
         for(int j=i;j<pair_count;j++){

            int margin1 = 0;
            int margin2 = 0;

            for(int x = 0;x<candidate_count;x++){
                margin1+=preferences[i][x];
                margin2+=preferences[j][x];
            }

            if (margin1 <  margin2){

                auxpair = pairs[i];
                pairs[i]=pairs[j];
                pairs[j]=auxpair;

            }
         }
    }

    /*printf("Sorted \n");
    for(int i=0;i<pair_count;i++){

        printf("%i wins over %i \n",pairs[i].winner,pairs[i].loser);

    }*/

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i=0;i<pair_count;i++){

        locked[pairs[i].loser][pairs[i].winner]=true;

    }

    /*printf("Locked \n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i locked by %i: %d\n",i,j,locked[i][j]);
        }
    }*/

    return;
}

// Print the winner of the election
void print_winner(void)
{

 printf("\n");
    for (int i = 0; i < candidate_count; i++)
    {
        int total_locked=0;
        for (int j = 0; j < candidate_count; j++)
        {
            if(!locked[i][j]){
                total_locked++;
            }
        }
        if(total_locked==candidate_count){

            printf("Winner: %s \n",candidates[i]);

        }
    }

    return;
}

