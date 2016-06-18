#include<stdio.h>
#include<stdlib.h>

int main(){
    while(1){
        int input_f[100000]={0}, n,max=0;
        for(int count=n=0;count<100000;count++){
            scanf("%d",&input_f[count]);
            if(max<input_f[count]) max=input_f[count];
            n++;
            if(getchar()=='\n') break;
        }
        if(max>n-1){
            printf("Message hacked by the Martians!!!\n");
            continue;
        }
        int input[n],ans[n];
        for(int count=0;count<n;count++)
            ans[count]=input[count]=-1;
        for(int count=0;count<n;count++)
            input[count]=input_f[count];
        if(n==1&&input[0]==0) exit(1);
        for(int count=0;count<n;count++){
            for(int count2=0;count2<n;count2++){
                if(input[count2]==count){
                    ans[count]=input[count2];
                    input[count2]=-1;
                    break;
                }
            }
        }
        for(int count=0;count<n;count++){
            if(ans[count]==-1)
                for(int count2=0;count2<n;count2++){
                    if(input[count2]!=-1){
                        ans[count]=input[count2];
                        input[count2]=-1;
                        break;
                }
            }
        }
        printf("%d",ans[0]);
        for(int count=1;count<n;count++)
            printf(" %d",ans[count]);
        printf("\n");
    }
    return 0;
}
