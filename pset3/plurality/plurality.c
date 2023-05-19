#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
      string name;
      int votes;
}
candidate;

int find_candidate(string vote,candidate candidates[],int size);
int max_votes(candidate candidates[],int size);


int main(int argc, string argv[])
{
    candidate candidates[argc-1];
    int qtd_winners=0;
    int max_vote=0;
    //printf("%i\n",argc-1);

    int numbers_votes = get_int("Number of votes\n");

    for(int i=1; i < argc;i++){
        candidates[i-1].name = argv[i];
        candidates[i-1].votes = 0;
    }


    for (int i = 0; i < numbers_votes; i++)
    {
          string vote = get_string("Vote: ");

          int candidate_found = find_candidate(vote,candidates,argc-1);

          if(candidate_found >=0){
            candidates[candidate_found].votes++;
          }
    }

    max_vote = max_votes(candidates,argc-1);

     for(int i = 0; i < argc-1;i++){
         printf("%s votes: %i\n",candidates[i].name,candidates[i].votes);
         if(candidates[i].votes == max_vote){
             qtd_winners++;
         }
     }

     printf("number winners: %i\n",qtd_winners);

    candidate winners[qtd_winners];
    int id_winners= 0;

    for(int i = 0; i < argc-1;i++){
         printf("%s votes: %i\n",candidates[i].name,candidates[i].votes);
         if(candidates[i].votes == max_vote){
            winners[id_winners] = candidates[i];
            id_winners++;
         }
     }


    if(id_winners>1){
             printf("Empate entre: \n");
         } else {
             printf("Vencedor: \n");
         }

     for(int i = 0; i < id_winners;i++){

          printf("%s com %i votos\n",winners[i].name,winners[i].votes);

     }

}


int max_votes(candidate candidates[],int size){

    int aux_max_votes = candidates[0].votes;

    for(int i=1;i<size;i++){

        if(candidates[i].votes > aux_max_votes){
            aux_max_votes = candidates[i].votes;
        }

    }

    return aux_max_votes;

}

int find_candidate(string vote,candidate candidates[],int size){

    for(int i = 0; i < size;i++){
              if (strcmp(candidates[i].name, vote) == 0)
              {
               return i;
              }
          }
          return -1;
}

