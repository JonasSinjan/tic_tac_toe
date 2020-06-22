#include <stdio.h>

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
    printf("\nBoard:\n");

    for (index=0; index <9; ++index) {
        if (index!=0 && index%3==0) {
            printf("\n");
        }
        printf("%4d", board[convertto25[index]]);
    }
    printf("\n");
}

int main (){
    int board[25]; 
    initialiseboard(&board[0]); //always point to the first element in the array?
    printboard(&board[0]);
    board[convertto25[3]] = crosses;
    printboard(&board[0]);

    return 0;
}