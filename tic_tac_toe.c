#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
int board[25] = {
    :,:,:,:,:,
    :,0,-,X,:,
    :,X,-,-,:,
    :,-,-,-,:,
    :,:,:,:,:,

}
*/

enum {empty, noughts, crosses, border};
enum {humanwin, compwin, draw};


const int convertto25[9] = {
    6,7,8,11,12,13,16,17,18
};

void initialiseboard(int *board) {
    int index = 0;

    for (index=0; index <25; ++index) {
        board[index] = border;
    }

    for (index=0; index <9; ++index) {
        board[convertto25[index]] = empty;
    }
}

void printboard(const int *board) {
    int index = 0;
    char pcechars[] = "OX|-";
    printf("\nBoard:\n");

    for (index=0; index <9; ++index) {
        if (index!=0 && index%3==0) {
            printf("\n\n");
        }
        printf("%4c", pcechars[board[convertto25[index]]]);
    }
    printf("\n");
}

int hasempty(const int *board) {
    int index = 0;
    for(index = 0; index <9; ++index) {
        if(board[convertto25[index]] == empty) return 1;

    }
    return 0;
}

void makemove(int *board, const int sq, const side) {
    board[sq] = side;

}

int gethumanmove( const int *board) {
    //returns 6 as move if move top left corner
    char userinput[4];
    int moveOk = 0;
    int move = -1;

    while (moveOk == 0) {

        printf("Please enter a move from 1 to 9:");
        fgets(userinput, 3, stdin);
        fflush(stdin); //gets rid of input stream after first 3 input

        //checking invalid inputs, should be one number and enter key (\n)
        if(strlen(userinput) != 2) {
            printf("Invalid string length answer\n");
            continue;

        }
        //if invalid format
        if (sscanf(userinput, "%d", &move) != 1) {
            move = -1;
            printf("Invalid sscanf()\n");
            continue;
        }
        //if input not between 1 and 9
        if (move <1 || move > 9) {
            move = -1;
            printf("Invalid number on the board\n");
            continue;
        }

        move--; //zero indexing

        if (board[convertto25[move]] != empty) {
            move = -1;
            printf("Square not available\n");
            continue;
        }
        moveOk = 1; //breaks the while loop
    }
    printf("Making move....%d\n", (move+1));
    return convertto25[move];
}

void RunGame () {

    int GameOver = 0;
    int side = noughts;
    int Lastmovemade = 0;
    int board[25];

    initialiseboard(&board[0]);
    printboard(&board[0]);

    //while game is not over, game will continue
    while(!GameOver) {
        if(side=noughts) {
            gethumanmove(&board[0]);
        } else{
            printboard(&board[0]);
        }
    }
}

int main (){

    srand(time(NULL));
    RunGame();

    return 0;
}