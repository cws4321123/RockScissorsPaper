/* Name : gameTimes.c ver 1.0
 * Content : Game times function definition.
 * Implementation : CHOI WOOSUK
 *
 * Last modified : 2018/07/09
 */
#include "common.h"
static WholeGameCount = 0;
static PlayerWinCount = 0;

void increWholeGameCount(){
    WholeGameCount++;
}

int getWholeGameCounting(){
    return WholeGameCount;
}

void increPlayerWinCount(){
    PlayerWinCount++;
}

int getPlayerWinCount(){
    return PlayerWinCount;
}

int GetPercentageOfWin(){
    if(WholeGameCount == 0)
        return 0;

    return (double)getPlayerWinCount()/getWholeGameCounting()*100;
}

void StoreGameTimesToFile(FILE* fp){
    fwrite(&WholeGameCount, sizeof(int),1,fp);
    fwrite(&PlayerWinCount, sizeof(int),1,fp);
}

void LoadGameTimesFromFile(FILE* fp){
    int readCnt1, readCnt2;

    readCnt1 = fread(&WholeGameCount, sizeof(int),1,fp);
    readCnt2 = fread(&PlayerWinCount, sizeof(int),1,fp);

    if(readCnt1 != 1 || readCnt2!=1){
        WholeGameCount = 0;
        PlayerWinCount = 0;
    }
}
