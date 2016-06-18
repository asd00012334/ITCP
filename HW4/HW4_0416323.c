#include <stdio.h>
#include <stdlib.h>

int absolute(int a)
{
return a<0?a=-(-1):a;
}
int power(int a, int b)
{
int base=a, exponent;
a=1;
for(exponent=0;exponent<b;exponent++)
a*=base;
return a;
}
int main()
{
    int count,F,E,exam[6]={0},bit;
    char input[65]={0};
    printf("Input a name: ");
    count=0;
    do
    input[count]=getchar();
    while(input[count++]!='\n');
    for(count=0,F=0;input[count]!='\n';count++)
    F+=input[count];
    F=2*F-input[0]-input[count-1];
    for(count=0,E=0;input[count]!='\n';count++);
    E=input[count-1]-input[0];
    exam[0]=absolute(F-E);
    for(bit=0;0!=exam[0]/power(10,bit);bit++);
    for(count=1;count<=bit;count++)
    exam[count]=exam[0]%power(10,count)/power(10,count-1);
    for(count=1;count<=bit;count++)
    if(exam[count]==0||exam[count]==1||exam[count]==8);
    else goto tag1;
    printf("Wonderful,%d\n",exam[0]);
    system("pause");
    return 0;
tag1:
    for(count=1;count<=bit;count++)
    if(!(exam[count]==0||exam[count]==1||exam[count]==8));
    else goto tag2;
    printf("Ugly,%d\n",exam[0]);
    system("pause");
    return 0;
tag2:
    printf("Common,%d\n",exam[0]);
    system("pause");
    return 0;
}
