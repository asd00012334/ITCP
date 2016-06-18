#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,a,b,c,d,e;
    Blank:
    printf("Enter a 5-digit integer: ");
    scanf("%d",&m);
    a=m%10;
    b=(m)%100/10;
    c=(m)%1000/100;
    d=(m)%10000/1000;
    e=(m)/10000;
    if(!(10000<=m&&m<100000))
    {printf("Your input is not a 5-digit integer. Exit\n\n");
    goto Blank;
    }
    else if(a==e&&b==d)
    printf("It is a palindrome.\n\n");
    else
    {printf("It is not a palindrome\n\n");
    goto Blank;
    }
    system("pause");

    return 0;
}
