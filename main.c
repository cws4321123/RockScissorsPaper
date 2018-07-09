/* Name : main.c ver 1.0
 * Content : main function
 * Implementation : CHOI WOOSUK
 *
 * Last modified 2018/07/09
 */
#include "common.h"
#include "game.h"

int main()
{
    int com;
    int you;
    int youmoney;
    int gamblingMoney;
    int ret;

    if(!DoYouWantToContinue()){
        puts("Yeah! Game is starting..!");
        puts("");

        printf("# Set your game money.");
        scanf("%d",&youmoney);
        setComMoney(1000);
        setYouMoney(youmoney);
    }

    printf("Your's Game money: %d \n",youmoney);
    printf("Com's Game money: %d \n",1000);

    printf("\n");
    //If someone won, they will be compensated.


    while(1){
        printf("Set gambling MONEY!!!!!!!!\n");
        printf("Input gambling MONEY : ");
        scanf("%d",&gamblingMoney);

        ret = SetGamblingTableMoneybyGamer(gamblingMoney);
        if(ret ==0 || ret==-1){
            if(ret == 0){
                puts("Stay within the amount you own!");
                printf("Your current game money : %d \n",getYouMoney());
            }
            else{
                puts("computer is over amount!");
                printf("Com's current game money : %d \n",getComMoney());
            }
            continue;
        }

        puts("");
        puts("¡Ù¡Ù¡Ù¡Ù¡Ù¡Ù Fight! ¡Ù¡Ù¡Ù¡Ù¡Ù¡Ù!!");
        com = ChoiceOfCom();
        you = ChoiceOfMe();
        puts("");
        if(you == QUIT)
            break;
        puts("¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú Result! ¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú!!");

        WhoIsWinner(com, you);

        switch(com){
        case ROCK:
            printf("¢¹ Computer's Choice is : Rock.\n");
            break;
        case SCISSOR:
            printf("¢¹ Computer's Choice is : Scissor.\n");
            break;
        case PAPER:
            printf("¢¹ Computer's Choice is : Paper.\n");
            break;
        }


        switch(you){
        case ROCK:
            printf("¢¹ Player's Choice is : Rock.\n");
            break;
        case SCISSOR:
            printf("¢¹ Player's Choice is : Scissor.\n");
            break;
        case PAPER:
            printf("¢¹ Player's Choice is : Paper.\n");
            break;
        }

        puts("");

        printf("Percentage of win : %d %% \n\n",GetPercentageOfWin());
        printf("Gamer money : %d \n", getYouMoney());
        printf("Computer money : %d \n", getComMoney());

        if(getComMoney()<=0 || getYouMoney()<=0)
            break;

    }

    printf("\n\n");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts("$$$$$$$$$$$$$$$$ FINALLLL RESULT $$$$$$$$$$$$$$$$");
    printf("Final percentage of WIN! : %d %% \n",GetPercentageOfWin());
    if(getComMoney() != 0 && getYouMoney() != 0)
        DoYouWantToStore();
    else
        ClearContinueInfo();
    puts("Thank you for using it!!!!!");

    return 0;
}
