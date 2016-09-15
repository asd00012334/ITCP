#include <stdio.h>
#include <stdlib.h>

char* fistType[3] = {"scissors","stone","paper"};

int main()
{
    int fist,pc,round,win,lose,draw;
    srand(time(NULL));
    printf("Please input the round you want to play:");
    scanf("%d",&round);
    win=lose=draw=0;
    while(round--){
        printf("#Please threw the Fist you want, 1=scissors 2=stone 3=paper: ");
        scanf("%d",&fist);
        pc=rand()%3+1;
        printf("You threw %s, Computer threw %s, ",fistType[fist],fistType[pc]);
        switch(fist-pc){
            case 1:
            printf("YOU WIN!!\n");
            win++;
            break;
    
            case -1:
            printf("YOU LOSE!!\n");
            lose++;
            break;
    
            case 0:
            printf("DRAW!!\n");
            draw++;
            break;
        }
    }
    printf("WIN: %d\nLOSE: %d\nDRAW: %d\n",win,lose,draw);
    return 0;
}
