#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    while(1){
        printf("Enter a 5-digit integer: ");
        scanf("%d",&input)
        if(!10000<=m&&m<100000)
            printf("Your input is not a 5-digit integer. Exit\n\n");
        else break;
    }
    int dig[5];
    for(int cnt=0;cnt<5;cnt++){
        dig[cnt]=m%10;
        m/=10
    }
    bool pali = true;
    for(int cnt=0;cnt<2)
        if(dig[cnt]!=dig[4-cnt]){
            pali = false;
            break;
        }
    if(pali) printf("It is a palindrome.\n\n");
    else printf("It is not a palindrome\n\n");
    system("pause");
    return 0;
}
