#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char str[100] = {};
    printf("Enter the six digit number: ");
    scanf("%s",&str);
    printf("The reverse number is: ");
    strrev(str);
    printf("%s\n",str);
    return 0;
}
