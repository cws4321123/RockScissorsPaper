#ifndef GAMETIMES_H_INCLUDED
#define GAMETIMES_H_INCLUDED

void increWholeGameCount();
int getWholeGameCounting();
void increPlayerWinCount();
int getPlayerWinCount();
int GetPercentageOfWin();
void StoreGameTimesToFile(FILE* fp);
void LoadGameTimesFromFile(FILE* fp);
#endif // GAMETIMES_H_INCLUDED
