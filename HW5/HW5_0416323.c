#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int switcher;
void f_sign(void);
void f_integer(void);
void f_error(void);
void f_real(void);
void f_fraction(void);
void f_fail(void);
void method_f(void);
void method_c(void);
void f_fail(void);
void f_success(void);

int main()
{
int input;
srand(time(NULL));
    while(1)
    {
    input=getchar();
    if(input==EOF)
    return 0;
    ungetc(input,stdin);
    switch(rand()%2)
    {
    case 0:
    method_f();
    break;
    case 1:
    method_c();
    break;
    }
    }
return 0;
}

void method_f()
{
switcher=0;
f_sign();
return;
}

void f_sign()
{
if(switcher==1)
return;
int input=getchar();
    switch(input)
    {
    case '+': case '-':
    f_sign(); return;
    case '.':
    f_fraction(); return;
    case '\n':
    f_fail(); return;
    default:
    if(isdigit(input))
    {f_integer(); return;}
    }
return;
}

void f_integer(void)
{
if(switcher==1)
return;
int input=getchar();
    switch(input)
    {
    case '+': case '-':
    f_error(); return;
    case '.':
    f_real(); return;
    return;
    case '\n':
    f_fail(); return;
    default:
    if(isdigit(input))
    {f_integer(); return;}
    }
return;
}

void f_fraction()
{
if(switcher==1)
return;
int input=getchar();
    switch(input)
    {
    case '+': case '-': case '.':
    f_error(); return;
    case '\n':
    f_fail(); return;
    default:
    if(isdigit(input))
    {f_real(); return;}
    }
return;
}

void f_error()
{
switcher=1;
int input=getchar();
while(input!='\n')
input=getchar();
printf("Rejected by Method 1\n");
return;
}

void f_real()
{
if(switcher==1)
return;
int input=getchar();
    switch(input)
    {
    case '+': case '-': case '.':
    f_error(); return;
    case '\n':
    printf("Accepted by Method 1\n");
    switcher=1;
    return;
    default:
    if(isdigit(input))
    {f_real(); return;}
    }
}

void f_fail(void)
{
switcher=1;
printf("Rejected by Method 1\n");
return;
}

void method_c(void)
{
const int sign=1, integer=2, error=3, fraction=4, real=5;
int status=sign, input;

    while(1)
{
    input=getchar();
    switch(status)
    {

    case 1:
        switch(input)
        {
        case '+': case '-':
        status=sign; break;
        case '.':
        status=fraction; break;
        case '\n':
        printf("Rejected by method 2\n");
        return;
        default:
        if(isdigit(input))
        {status=integer; break;}
        }
        break;

    case 2:
        switch(input)
        {
        case '+': case '-':
        status=error; break;
        case '.':
        status=real; break;
        case '\n':
        printf("Rejected by method 2\n");
        return;
        default:
        if(isdigit(input))
        {status=integer; break;}
        break;
        }
        break;

    case 4:
        switch(input)
        {
        case '+': case '-': case '.':
        status=error; break;
        case '\n':
        printf("Rejected by method 2\n");
        return;
        default:
        if(isdigit(input))
        {status=real; break;}
        }
        break;

    case 3:
        switch(input)
        {
        case '\n':
        printf("Rejected by method 2\n");
        return;
        default:
        status=error; break;
        }
        break;

    case 5:
        switch(input)
        {
        case '+': case '-': case '.':
        status=error; break;
        case '\n':
        printf("Accepted by method 2\n"); return;
        default:
        if(isdigit(input))
        {status=real; break;}
        }
        break;
    }

}
return;
}
