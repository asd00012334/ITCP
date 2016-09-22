#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi (acos(0)*2) ///for this sample output you shall use pi=3.1415926
#define ld long double

int main(){
    int r[2],h;
    printf("Value of r1:");
    scanf("%d",&r[0]);
    printf("Balue of r2:");
    scanf("%d",&r[1]);
    printf("Value of h:");
    scanf("%d",&h);
    printf("Volumn: %.6f\n",(float)((r[1]*r[1]+r[0]*r[1]+r[0]*r[0])*pi*h/3));
    return 0;
}
