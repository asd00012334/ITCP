#include<stdio.h>
#include<stdlib.h>
int main(){
    int input[100],a[100]={0},b[100]={0},count,temp,count2,temp2;
    printf("Input a:");
    for(count=0;count<=99;count++)
        input[count]=0;
    count=0;
    do input[count]=getchar()-'0';
    while(input[count++]!='\n'-'0');
    temp=count=count-2;
    for(;count>=0;count--)
        a[temp-count]=input[count];
    for(count=0;count<=99;count++)
        input[count]=0;
    count=0;
    printf("Input b:");
    do input[count]=getchar()-'0';
    while(input[count++]!='\n'-'0');
    temp=count=count-2;
    for(;count>=0;count--)
        b[temp-count]=input[count];
    int addition[101]={0}, multiplication[200]={0}, subtraction[100]={0};
    for(count=0;count<=99;count++)
        addition[count]=a[count]+b[count];
    for(count=0;count<=99;count++)
        subtraction[count]=a[count]-b[count];
    for(temp=99;a[temp]==0;temp--);
    for(temp2=99;b[temp2]==0;temp2--);
    for(count=0;count<=temp;count++)
    for(count2=0;count2<=temp2;count2++)
        multiplication[count+count2]+=a[count]*b[count2];
    for(temp=100;addition[temp]==0;temp--);
    for(count=0;count<=temp;count++)
        if(addition[count]>=10){
            addition[count+1]+=addition[count]/10;
            addition[count]%=10;
        }
    for(temp=99;subtraction[temp]==0;temp--);
    for(count=0;count<=temp;count++)
        if(subtraction[count]>=10){
            subtraction[count+1]+=subtraction[count]/10;
            subtraction[count]%=10;
        }else if(subtraction[count]<0){
            subtraction[count+1]--;
            subtraction[count]+=10;
        }
    for(temp=199;multiplication[temp]==0;temp--)
    for(count=0;count<=temp;count++)
        if(multiplication[count]>=10){
            multiplication[count+1]+=multiplication[count]/10;
            multiplication[count]%=10;
        }
    printf("a+b=");
    for(temp=100;temp>=0&&addition[temp]==0;temp--);
    if(temp==-1)
        printf("0");
    else{
        for(count=100;addition[count]==0;count--);
        for(;count>=0;count--)
            printf("%d",addition[count]);
    }
    printf("\na-b=");
    for(temp=99;temp>=0&&subtraction[temp]==0;temp--);
    if(temp==-1)
        printf("0");
    else{
        for(count=99;subtraction[count]==0;count--);
        for(;count>=0;count--)
            printf("%d",subtraction[count]);
    }
    printf("\na*b=");
    for(temp=199;temp>=0&&multiplication[temp]==0;temp--);
    if(temp==-1)
        printf("0");
    else{
        for(count=199;multiplication[count]==0;count--);
        for(;count>=0;count--)
            printf("%d",multiplication[count]);
    }
    printf("\n");
    system("pause");
    return 0;
}
