#include<stdio.h>
#include<stdlib.h>

int col_emp(int**,int,int);

int main(){
    while(1){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) return 0;
        int **rule,ans[n];
        int rule_body[(n+1)*(n+1)];
        rule=(int**)malloc(sizeof(int*)*(n+1));
        for(int count=0;count<n+1;count++)
            rule[count]=&rule_body[count*(n+1)];
        for(int count=0;count<=n;count++)
            rule[count][0]=rule[0][count]=count;
        for(int count=1;count<=n;count++)
        for(int count2=1;count2<=n;count2++)
            rule[count][count2]=0;
        for(int count=1;count<=m;count++){
            int form,latt;
            scanf("%d%d",&form,&latt);
            rule[form][latt]=1;
        }//above initialize
        for(int count=0;count<n;count++){
            for(int count2=1;count2<=n;count2++){
                if(rule[0][count2]==0) continue;
                if(rule[0][count2]!=0) if(col_emp(rule,count2,n)){
                    ans[count]=count2;
                    for(int count3=0;count3<=n;count3++)
                        rule[count2][count3]=rule[count3][count2]=0;
                    break;
                }
            }
        }
        printf("%d",ans[0]);
        for(int count=1;count<n;count++)
            printf(" %d",ans[count]);
        printf("\n");
        free(rule);
    }
    return 0;
}
int col_emp(int **rule,int col,int n){
    int empty=1;
    for(int count=1;count<=n;count++)
        if(rule[count][col]!=0) empty=0;
    return empty;
}
