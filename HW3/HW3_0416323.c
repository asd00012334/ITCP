#include <stdio.h>
#include <stdlib.h>

char* fistType[3] = {"scissors","stone","paper"};
char* msg[3]={"DRAW","YOU WIN","YOU LOSE"};

int main(){
    int fist,pc,round,status[3]={};
    srand(time(NULL));
    printf("Please input the round you want to play:");
    scanf("%d",&round);
    while(round--){
        printf("#Please threw the Fist you want, 1=scissors 2=stone 3=paper: ");
        scanf("%d",&fist);
        pc=rand()%3;
        printf("You threw %s, Computer threw %s, ",fistType[--fist],fistType[pc]);
        int game=(fist-pc+3)%3;
        printf("%s!!\n",msg[game]);
        ++status[game];
    }
    printf("WIN: %d\nLOSE: %d\nDRAW: %d\n",status[1],status[2],status[0]);
    return 0;
}
