#include "common.h"
#include "gameTimes.h"
#include "gameMoney.h"

#define FILE_NAME "gamecont_info.data"
#define FILE_DEL_CMD "del gamecont_info.data"

int DoYouWantToContinue(){
    FILE* fp;
    int conti;
    if(!AvailContinue())
        return 0;

    fputs("Do you want to continue playing the game? (YES 1, NO 0) : ",stdout);
    scanf("%d",&conti);

    if(conti==0)
        return 0;

    fp = fopen(FILE_NAME,"rb");
    if(fp==NULL){
        puts("No Continue Data is exist.");
        return 0;
    }

    LoadGameTimesFromFile(fp);

    LoadGameMoneyFromFile(fp);

    fclose(fp);

    return 1;
}

int DoYouWantToStore(void){
    FILE* fp;
    int cont;

    fputs("Do you want to save the game? (Yes 1, NO 0) : ",stdout);
    scanf("%d",&cont);

    if(cont==0)
        return 0;
    fp = fopen(FILE_NAME,"wb");

    StoreGameTimesToFile(fp);

    StoreGameMoneyToFile(fp);
    fclose(fp);

    return 1;
}

int AvailContinue(){
    FILE* fp;
    fp = fopen(FILE_NAME, "rb");
    if(fp==NULL)
        return 0;
    else{
        fclose(fp);
        return 1;
    }
}

void ClearContinueInfo(){
    FILE* fp;
    fp=fopen(FILE_NAME,"rb");

    if(fp!=NULL){
        fclose(fp);
        system(FILE_DEL_CMD);
    }
}
