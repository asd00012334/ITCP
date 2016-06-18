#include <stdio.h>
#include <stdlib.h>

int examine_p(int a){
int factor,factor_sum;
for(factor=1,factor_sum=0;factor<a;factor++)
if(a%factor==0)
factor_sum+=factor;
return (a==factor_sum)?1:0;
}

int examine_d(int a){
int factor,factor_sum;
for(factor=1,factor_sum=0;factor<a;factor++)
if(a%factor==0)
factor_sum+=factor;
return (a>factor_sum)?1:0;
}


int main()
{
    int count,input, perfect=0, deficient=0, abundant=0;
    printf("Please input N:");
    scanf("%d",&input);
    for(count=2;count<=input;count++)
    {
        if(examine_p(count)==1)
        perfect++;
        else if(examine_d(count)==1)
        deficient++;
        else
        abundant++;

    }
    printf("DEFICIENT:%d\n",deficient);
    printf("PERFECT:%d\n",perfect);
    printf("ABUNDANT:%d\n",abundant);
    system("pause");
    return 0;
}

