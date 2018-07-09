#include "common.h"
static int moneyCom;
static int moneyYou;

static int gamblingTableMoney;

void setComMoney(int money){
    if(money<0)
        return;

    moneyCom = money;
}

int getComMoney(){

    return moneyCom;
}
void setYouMoney(int money){
    if(money<0)
        return;

    moneyYou = money;
}

int getYouMoney(){

    return moneyYou;
}

void SetGamblingTableMoney(int money){
    if(money<0)
        return;
    else
        gamblingTableMoney = money;
}
int SetGamblingTableMoneybyGamer(int money){
    if(money > moneyYou)
        return 0;
    else if(money>moneyCom)
        return -1;

    SetGamblingTableMoney(money);
    return 1;
}

void ComWinMoneyAccount(){
    moneyCom += gamblingTableMoney;
    moneyYou -= gamblingTableMoney;
}

void YouWinMoneyAccount(){
    moneyCom -= gamblingTableMoney;
    moneyYou += gamblingTableMoney;
}

void StoreGameMoneyToFile(FILE* fp){
    fwrite(&moneyCom, sizeof(int),1,fp);
    fwrite(&moneyYou, sizeof(int),1,fp);
}

void LoadGameMoneyFromFile(FILE* fp){
    int readCnt1, readCnt2;

    readCnt1 = fread(&moneyCom,sizeof(int),1,fp);
    readCnt2 = fread(&moneyYou, sizeof(int),1,fp);

    if(readCnt1!=1 ||readCnt2 !=1){
        moneyCom = 1000;
        moneyYou = 1000;
    }
}
