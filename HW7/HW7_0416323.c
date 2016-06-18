#include<stdio.h>
#include<stdlib.h>
void bubble(int [],int,int);
void quick(int [], int, int);
void swap(int*,int*);
void merge();
void merge_2();
void bubble_d(int [],int,int);
void quick_d(int [], int, int);
void swap_d(int*,int*);
int **array_d,N,sts_d,*num_d,**array,sts,count,count2,*num;
int main(){
printf("Given N number:");
scanf("%d",&N);
printf("Input: ");
int input[N],bub[N],qui[N],mer[N],bub_d[N],qui_d[N],mer_d[N];
for(count=0;count<N;count++){
scanf("%d",input+count);
*(bub_d+count)=*(qui_d+count)=*(mer_d+count)=*(bub+count)=*(qui+count)=*(mer+count)=*(input+count);
}
printf("0:bubble, 1:quick, 2:merge  :");
fflush(stdin);
switch(getchar()){
case '0':
    printf("Bubble sort:\n");
    bubble(bub,N,0);
    printf("(1)Increasing:\n");
    printf("%d",*bub);
    for(count=1;count<N;count++) printf(" %d",*(bub+count));
    bubble_d(bub_d,N,0);
    printf("\n(2)Decreasing:\n");
    printf("%d",*bub_d);
    for(count=1;count<N;count++) printf(" %d",*(bub_d+count));
    printf("\n");
break;
case '1':
    quick(qui,0,N-1);
    printf("Quick sort:\n(1)Increasing:\n%d",*qui);
    for(count=1;count<N;count++) printf(" %d",*(qui+count));

    quick_d(qui_d,0,N-1);
    printf("\n(2)Decreasing:\n%d",*qui_d);
    for(count=1;count<N;count++) printf(" %d",*(qui_d+count));
    printf("\n");
break;
case '2':
array=(int**)malloc(sizeof(int*)*N);
for(count=0;count<N;count++)
*(array+count)=(int*)malloc(sizeof(int)*N);
num=(int*)malloc(sizeof(int)*N);
for(count=0;count<N;count++){
    *(num+count)=1;
    for(count2=0;count2<N;count2++)
        *(*(array+count)+count2)=0;
    *(*(array+count)+0)=*(mer+count);
}
sts=N;
merge();array_d=(int**)malloc(sizeof(int*)*N);
for(count=0;count<N;count++)
*(array_d+count)=(int*)malloc(sizeof(int)*N);
num_d=(int*)malloc(sizeof(int)*N);
for(count=0;count<N;count++){
    *(num_d+count)=1;
    for(count2=0;count2<N;count2++)
        *(*(array_d+count)+count2)=0;
    *(*(array_d+count)+0)=*(mer_d+count);
}
sts_d=N;
merge_d();
break;
}
system("pause");
return 0;
}
void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}
void bubble(int input[],int length,int count){
if(count>=length) return;
for(count2=count;count2<length;count2++){
if(*(input+count)>*(input+count2)) swap(input+count,input+count2);
}
bubble(input,length,count+1);
}
void quick(int *input, int lower_bound, int upper_bound){
if(lower_bound>=upper_bound) return;
int partition=(upper_bound+lower_bound)/2;

	for(count=lower_bound;lower_bound<=count&&count<partition;count++){
		if(*(input+count)>*(input+partition)){
		for(count2=count;count2<partition;count2++)
		swap(input+count2,input+count2+1);
		partition--;
		count=lower_bound-1;
		}
	}
	for(count=partition+1;partition<count&&count<=upper_bound;count++){
		if(*(input+count)<*(input+partition)){
		for(count2=count;count2>partition;count2--)
		swap(input+count2,input+count2-1);
		partition++;
		count=partition;
		}
	}
quick(input,lower_bound,partition-1);
quick(input,partition+1,upper_bound);
return;
}
void merge(){
merge_2();
printf("Merge sort:\n(1)Increasing:\n%d",*(*(array+0)+0));
for(count=1;count<N;count++)
printf(" %d",*(*(array+0)+count));
return;
}
void merge_2(){
int up=0,down=sts-1;

if(sts==1) return;
while(up<down){

    while(*(num+down)>0){
        *(*(array+up)+((*(num+up))++))=*(*(array+down)+(--(*(num+down))));
        for(count=*(num+up)-1;count>0&&*(*(array+up)+count-1)>*(*(array+up)+count);count--)
            swap(*(array+up)+count-1,*(array+up)+count);
    }
    sts--; up++; down--;
}
merge_2();
return;
}
void bubble_d(int input[],int length,int count){
if(count>=length) return;
for(count2=count;count2<length;count2++){
if(*(input+count)<*(input+count2)) swap(input+count,input+count2);
}
bubble_d(input,length,count+1);
return;
}
void quick_d(int *input, int lower_bound, int upper_bound){
if(lower_bound>=upper_bound) return;
int partition=(upper_bound+lower_bound)/2;
	for(count=lower_bound;lower_bound<=count&&count<partition;count++){
		if(*(input+count)<*(input+partition)){
		for(count2=count;count2<partition;count2++)
		swap(input+count2,input+count2+1);
		partition--;
		count=lower_bound-1;
		}
	}
	for(count=partition+1;partition<count&&count<=upper_bound;count++){
		if(*(input+count)>*(input+partition)){
		for(count2=count;count2>partition;count2--)
		swap(input+count2,input+count2-1);
		partition++;
		count=partition;
		}
	}
quick_d(input,lower_bound,partition-1);
quick_d(input,partition+1,upper_bound);
return;
}
void merge_d(){
merge_2_d();
printf("\n(2)Decreasing:\n%d",*(*(array_d+0)+0));
for(count=1;count<N;count++)
printf(" %d",*(*(array_d+0)+count));
printf("\n");
return;
}
void merge_2_d(){
int up=0,down=sts_d-1;
if(sts_d==1) return;
while(up<down){
    while(*(num_d+down)>0){
        *(*(array_d+up)+((*(num_d+up))++))=*(*(array_d+down)+(--(*(num_d+down))));
        for(count=*(num_d+up)-1;count>0&&*(*(array_d+up)+count-1)<*(*(array_d+up)+count);count--)
            swap(*(array_d+up)+count-1,*(array_d+up)+count);
    }
    sts_d--; up++; down--;
}
merge_2_d();
return;
}
