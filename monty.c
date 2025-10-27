#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <string.h>  

int main(void){
    int door[3] = {0,0,0}; //Array representing the doors 
    int rounds=1000000;    //Number of rounds of simulation
    int playerPick=0;      //The player's original choice of doors
    int hostPick=0;        //The door the host picks to remove from play
    int winHold=0;         //Number of wins when the player holds
    int lossHold=0;        //Number of losses when the play holds
    int winMove=0;         //Number of wins when the player moves
    int lossMove=0;        //Number of losses when the player moves

    srand(time(NULL));
   
    for(int a=0; a<rounds; a++){        //The main simulation loop
        memset(door, 0, sizeof(door));  //Reset the doors
        door[rand()%3]=1;               //Place prize
        playerPick=rand()%3;            //Player door pick

        // Scenario #1 - player holds
        if(door[playerPick]) //Player guessed correctly
            winHold++;       //Count this as a win
        else                 //Otherwise
            lossHold++;      //It's a loss

        // Host opens a door (not player's pick, not the prize)
        for(int i=0; i<3; i++){
            if(i != playerPick && door[i] == 0){
                hostPick = i;
                break;
            }
        }

        // Scenario #2 - player switches to remaining door
        int switchPick = -1;
        for(int i=0; i<3; i++){
            if(i != playerPick && i != hostPick){
                switchPick = i;
                break;
            }
        }
        
        if(door[switchPick])
            winMove++;
        else
            lossMove++;
    }
    
    printf("\nWhen the guest holds:\n"); 
    printf("Wins: %d (%.1f%%), Loses: %d (%.1f%%)\n", 
           winHold, (winHold*100.0)/rounds, lossHold, (lossHold*100.0)/rounds);
    printf("\nWhen the guest switches:\n"); 
    printf("Wins: %d (%.1f%%), Loses: %d (%.1f%%)\n", 
           winMove, (winMove*100.0)/rounds, lossMove, (lossMove*100.0)/rounds);

    return 0;
}
