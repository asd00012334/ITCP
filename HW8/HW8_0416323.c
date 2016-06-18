#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define mom_l map[mom.r][mom.c]
#define map_c map[count][count2]
#define test printf("error\n")


struct bee{
int r;
int c;
};

void air(int,int);
int in_garden(struct bee);
int ischar(int);

int map[10][20];
int count,count2,flag,stuck;


int main(){
    for(count=0;count<10;count++)
    for(count2=0;count2<20;count2++)
    map[count][count2]='#';

    struct bee mom,son,first;
    srand(time(NULL));
    mom.r=rand()%10;
    mom.c=rand()%20;
    mom_l='A';
    first=mom;
    while(1){


        while(1){//mom moving
            flag=0;
            switch(rand()%4+1){
                case 1:
                    mom.r++;
                    if(!in_garden(mom))      mom.r--;
                    else if(ischar(mom_l))   mom.r--;
                    else flag=1;
                    break;
                case 2:
                    mom.r--;
                    if(!in_garden(mom))      mom.r++;
                    else if(ischar(mom_l))   mom.r++;
                    else flag=1;
                    break;
                case 3:
                    mom.c--;
                    if(!in_garden(mom))      mom.c++;
                    else if(ischar(mom_l))   mom.c++;
                    else flag=1;
                    break;
                case 4:
                    mom.c++;
                    if(!in_garden(mom))      mom.c--;
                    else if(ischar(mom_l))   mom.c--;
                    else flag=1;
                    break;
            }if(flag==1) break;

        }

        flag=0;
        for(count=0;count<10;count++)
        for(count2=0;count2<20;count2++){// mom affecting
            if(map_c>='A'&&map_c<'Z') map_c++;
            if(map_c=='Z') flag=1;
        }
        mom_l='A';
        if(flag==1) break;

            //if stuck or not?
            stuck=count=0;

            mom.r++;
            if(!in_garden(mom)) count++;
            else if(ischar(mom_l)) count++;
            mom.r--;
            mom.r--;
            if(!in_garden(mom)) count++;
            else if(ischar(mom_l)) count++;
            mom.r++;
            mom.c++;
            if(!in_garden(mom)) count++;
            else if(ischar(mom_l)) count++;
            mom.c--;
            mom.c--;
            if(!in_garden(mom)) count++;
            else if(ischar(mom_l)) count++;
            mom.c++;
            if(count==4) stuck=1;
            if(stuck==1) break;
            //if stuck or not
    }

    for(count=0;count<10;count++){//print out
    for(count2=0;count2<20;count2++)
    printf("%c",map_c);
    printf("\n");
    }
    if(stuck==1) return 0;
    son=mom;
    air(son.r,son.c);

    #define map_f map[first.r][first.c]
    flag=0;
    first.r++;
    if(in_garden(first)&&map_f=='Z') flag=1;
    first.r--;
    first.r--;
    if(in_garden(first)&&map_f=='Z') flag=1;
    first.r++;
    first.c++;
    if(in_garden(first)&&map_f=='Z') flag=1;
    first.c--;
    first.c--;
    if(in_garden(first)&&map_f=='Z') flag=1;
    first.c++;
    if(flag==1) printf("Yes");
    else printf("No");
    return 0;
}

int in_garden(struct bee a){
    if(0<=a.r&&a.r<10)
    if(0<=a.c&&a.c<20)
    return 1;
    return 0;
}

int ischar(int input){
    if('A'<=input&&input<='Z') return 1;
    else return 0;
}

void air(int r, int c){
    struct bee a;
    a.r=r;
    a.c=c;
    //if spreadable or not?
            stuck=count=0;

            a.r++;
            if(!in_garden(a)||ischar(map[a.r][a.c])) count++;
            else   {map[a.r][a.c]='Z'; air(a.r,a.c);}
            a.r--;
            a.r--;
            if(!in_garden(a)||ischar(map[a.r][a.c])) count++;
            else   {map[a.r][a.c]='Z'; air(a.r,a.c);}
            a.r++;
            a.c++;
            if(!in_garden(a)||ischar(map[a.r][a.c])) count++;
            else   {map[a.r][a.c]='Z'; air(a.r,a.c);}
            a.c--;
            a.c--;
            if(!in_garden(a)||ischar(map[a.r][a.c])) count++;
            else   {map[a.r][a.c]='Z'; air(a.r,a.c);}
            a.c++;
    //if spreadable or not?
return;
}
