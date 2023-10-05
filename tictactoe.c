//
// Created by emre on 05.10.2023.
//


#include <stdio.h>

#define ERR_MSG_WRONG_PLAYER "\nYou cannot enter anything but '1' and '2'\n>>"
#define ERR_MSG_OUT_OF_BOUNDARIES "\nThis indices are pointing out of boundaries of game area\nPlease, type something that points in game area\n\n"
#define ERR_MSG_OVERWRITE "\nA player put a character here before, so choose another indices\n\n"

char gameboard[3][4] = {{' ', ' ', ' ','\0'}, {' ', ' ', ' ','\0'}, {' ', ' ', ' ','\0'}};

char playerCheck(char trueval,char falseval,char* errmsg){

    char val;

    scanf(" %c",&val);

    if(val == trueval){

        return 1;

    };

    if(val == falseval){

        return 0;

    };

    if(val != falseval && val != trueval){

        printf(errmsg);

        return playerCheck(trueval,falseval,errmsg);

    };

};

void showGameboard(){

    printf("┌───┬───┬───┐\n");

    for(char i = 0;i<3;i++){
        for(char j = 0;j<3;j++){

            printf("│ %c ",gameboard[i][j]);

        };
        printf("│\n");
        if(i<2) printf("├───┼───┼───┤\n");

    };

    printf("└───┴───┴───┘\n");

};

char situationCheck(char round,char whoPlayed){

    if(round < 3) return 0;

    for(char i = 0;i<3;i++){

        if(gameboard[i][0] == whoPlayed && gameboard[i][1] == whoPlayed && gameboard[i][2] == whoPlayed) return whoPlayed;
        if(gameboard[0][i] == whoPlayed && gameboard[1][i] == whoPlayed && gameboard[2][i] == whoPlayed) return whoPlayed;
        if(gameboard[0][i] == whoPlayed && gameboard[1][i] == whoPlayed && gameboard[2][i] == whoPlayed) return whoPlayed;

    };

    if(gameboard[0][0] == whoPlayed && gameboard[1][1] == whoPlayed && gameboard[2][2] == whoPlayed) return whoPlayed;
    if(gameboard[0][2] == whoPlayed && gameboard[1][1] == whoPlayed && gameboard[2][0] == whoPlayed) return whoPlayed;

    return 0;

};

char play(char whoseTurn,char round){

    if(round == 9) return 1;

    //Player1 = 'X'
    //Player2 = 'O'

    printf("It's time to play for Player%c\nWhere do you want to put %c (write in indices => (r,c))\n>>",whoseTurn == 'X' ? '1' : '2',whoseTurn);

    char r,c;

    scanf(" (%c,%c)",&r,&c);

    if((r<'1' || r>'3') || (c<'1' || c>'3')){

        printf(ERR_MSG_OUT_OF_BOUNDARIES);

        return play(whoseTurn,round);

    };

    r -= '1';
    c -= '1';

    if(gameboard[r][c] == 'X' || gameboard[r][c] == 'O'){

        printf(ERR_MSG_OVERWRITE);

        return play(whoseTurn,round);

    };

//    printf("/1/\n%c\n//\n",whoseTurn);

    gameboard[r][c] = whoseTurn;

//    printf("/2/\n%c\n//\n",gameboard[r][c]);

    showGameboard();

    if(situationCheck(round,whoseTurn)){

        printf("\n%c has won the game\n",whoseTurn);

        return 1;

    };

    return play(whoseTurn == 'X' ? 'O' : 'X',++round);

};

int main(int argc,char** argv){

    char winnerIs,mode;

    printf("Welcome Player!\n\nThis is a Tic Tac Toe game in 3x3 area\n\nYou will play with the computer\n\nIf you want to you can play with your friend too\n\n>>PRESS '1' for playing with computer\n>>PRESS '2' for playing with your friend\n\n>> ");

    mode = playerCheck('1','2',ERR_MSG_WRONG_PLAYER);

    if(mode){



    }
    else{

        play('X',0);

    }

    return 0;

};
