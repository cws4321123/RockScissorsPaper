#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

enum {ROCK=1, SCISSOR, PAPER,QUIT};

int ChoiceOfCom(void);
int ChoiceOfYou(void);
void WhoIsWinner(int com, int you);


#endif // GAME_H_INCLUDED
