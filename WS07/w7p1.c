/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/******************************************************************************
<assessment name example: Workshop - #7 (Part-1)>
Full Name: MD Faiaz
Student ID#: 164899213
Email : mfaiaz@myseneca.ca
Section : NBB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#include <stdio.h>

#define MAX_LIVES 10
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MULTIPLE 5

struct PlayerInfo {
    char character_symbol;
    int character_lives;      
    int treasure_count;
    int positions[MAX_PATH_LENGTH];
};

struct GameInfo {
    int max_moves;      
    int path_length;
    int bombs[ MAX_PATH_LENGTH ];
    int treasure[ MAX_PATH_LENGTH ];
};

int main() {
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
   
   
    struct PlayerInfo player; // creating a new player
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    // PLAYER SYMBOL:
    printf("Enter a single character to represent the player: ");
    scanf("%c", &player.character_symbol);
    // PLAYER LIVES:
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.character_lives);
        if (player.character_lives < 1 || player.character_lives > MAX_LIVES) {
            printf("     Must be between 1 and %d!\n", MAX_LIVES);
        }
    } while (player.character_lives < 1 || player.character_lives > MAX_LIVES);
    printf("Player configuration set-up is complete\n\n");
   
   
    struct GameInfo game; // creating a new game
    printf("GAME Configuration\n");
    printf("------------------\n");
   
    // GAME PATH LENGTH
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.path_length);
        if (game.path_length < MIN_PATH_LENGTH || game.path_length > MAX_PATH_LENGTH || game.path_length % MULTIPLE != 0) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (game.path_length < MIN_PATH_LENGTH || game.path_length > MAX_PATH_LENGTH || game.path_length%MULTIPLE != 0);
   
    // NUMBER OF MOVES
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.max_moves);
        if (game.max_moves < player.character_lives || game.max_moves > (int)(0.75 * game.path_length)) {
            printf("    Value must be between %d and %d\n", player.character_lives, (int)(0.75 * game.path_length));
        }
    } while (game.max_moves < player.character_lives || game.max_moves > (int)(0.75 * game.path_length));
    printf("\n");
   
    // BOMB ARRANGEMENT
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    int bomb_position = 0;
    int b,i,j;
    for ( i = 0; i < game.path_length; i += MULTIPLE) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for( j = 0; j < MULTIPLE; ++j) {
            scanf("%d", &b);
            game.bombs[bomb_position] = b;
            ++bomb_position;
        }
    }
    printf("BOMB placement set\n\n");
   
    // TREASURE ARRANGEMENT
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    int treasure_position = 0;
    int t;
    for ( i = 0; i < game.path_length; i += MULTIPLE) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for( j = 0; j < MULTIPLE; ++j) {
            scanf("%d", &t);
            game.treasure[treasure_position] = t;
            ++treasure_position;
        }  
    }
    printf("TREASURE placement set\n\n");
   
    // GAME CONFIG:
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character_symbol);
    printf("   Lives      : %d\n", player.character_lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
   
    printf("Game:\n");
    printf("   Path Length: %d\n", game.path_length);
    printf("   Bombs      : ");
    for ( i = 0; i < game.path_length; ++i) {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for ( i = 0; i < game.path_length; ++i) {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
   
    return 0;
}


