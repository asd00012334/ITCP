#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int a;
    printf("Enter the six digit number: ");
    scanf("%d",&a);
    printf("The reverse number is: ");
    char str[100] = {};
    sprintf(str,"%d",a);
    strrev(str);
    printf("%s\n",str);
    return 0;
}
