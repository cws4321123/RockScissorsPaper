#ifndef GAMEMONEY_H_INCLUDED
#define GAMEMONEY_H_INCLUDED

void setComMoney(int);
int getComMoney();
void setYouMoney(int);
int getYouMoney();

void SetGamblingTableMoney(int);
int SetGamblingTableMoneybyGamer(int money);

void ComWinMoneyAccount();
void YouWinMoneyAccount();
void StoreGameMoneyToFile(FILE* fp);
void LoadGameMoneyFromFile(FILE* fp);
#endif // GAMEMONEY_H_INCLUDED
