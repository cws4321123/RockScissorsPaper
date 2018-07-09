/* Name : game.c ver 1.0
 * Content : game function definition
 * Implementation : CHOI WOOSUK
 *
 * Last modified : 2018/07/09
 */
#include <time.h>
#include "common.h"
#include "game.h"

int ChoiceOfCom(){

    srand((unsigned int)time(NULL));
    int rand_num = rand()%3+1;

    return rand_num;
}

int ChoiceOfMe(){

    int choice;
    printf("Rock<1> Scissor<2> Paper<3> Quit<4> Choice? : ");
    scanf("%d",&choice);

    return choice;
}

void WhoIsWinner(int com, int you){
    increWholeGameCount();

    if(com == you){
        printf("Drawing Game.\n");
        return;
    }

    if((com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1)){
        printf("Computer is Win!!\n");
        ComWinMoneyAccount();
        return;
    }

    if((you==1 && com==2) || (you==2 && com==3) || (you==3 && com==1)){
        printf("Player is Win!!\n");
        increPlayerWinCount();
        YouWinMoneyAccount();
        return;
    }
}
