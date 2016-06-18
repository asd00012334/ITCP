#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct Data{
    char* name;
    char* mate;
    char* concerntrate;
    char* unit;
    int index;
    struct Data* forw;
    struct Data* back;
};

char* str_in(char* string,FILE* file){
    int num=0;
    char* output=NULL;
    char temp;
    char consume;
    while(1){
        num++;
        string=(char*)realloc(string,sizeof(char)*num);
        if((temp=fgetc(file))==','){
            fscanf(file," ",&consume);
            string[num-1]='\0';
            break;
        }
        if(temp=='\n'){
            fscanf(file," ",&consume);
            string[num-1]='\0';
            break;
        }
        string[num-1]=temp;
    }
    return string;
}

void swap(struct Data* a,struct Data* b){
    struct Data c=*a;
    *a=*b;
    *b=c;
    return;
}

void data_initialize(struct Data* data){
    data->name=NULL;
    data->mate=NULL;
    data->concerntrate=NULL;
    data->unit=NULL;
}

void data_free(struct Data* data){
    free(data->name);
    free(data->mate);
    free(data->concerntrate);
    free(data->unit);
}

int numcmp(char* a,char* b){
    int size_a=0,size_b=0;
    int sum_a=0,sum_b=0;
    for(size_a=0;a[size_a]!='\0';size_a++);
    for(size_b=0;b[size_b]!='\0';size_b++);
    for(int count=0;count<size_a;count++)
        if(isdigit(a[count]))
            sum_a=sum_a*10+a[count]-'0';
    for(int count=0;count<size_b;count++)
        if(isdigit(b[count]))
            sum_b=sum_b*10+b[count]-'0';
    return sum_a-sum_b;
}

int main(){
    struct Data data[1000];
    FILE *file,*output_1,*output_2,*output_3;
    file=fopen(".\\PM2.5.csv","r");
    int num=0;
    for(int count=0;count<1000;count++)
        data_initialize(&data[count]);
    for(int count=0;count<1000;count++){
        data[count].name=str_in(data[count].name,file);
        data[count].mate=str_in(data[count].mate,file);
        data[count].concerntrate=str_in(data[count].concerntrate,file);
        data[count].unit=str_in(data[count].unit,file);
        data[count].index=count;
        num++;
    }
    for(int count=2;count<num;count++){
        for(int count2=count;count2>=2;count2--){
            if(strcmp(data[count2].name,data[count2-1].name)<0)
                swap(&data[count2],&data[count2-1]);
            else
                break;
        }

    }
    output_1=fopen(".\\outcomeSingle.csv","w");
    output_2=fopen(".\\outcomeBinary.bin","wb");
    for(int count=0;count<1000;count++){
        fputs(data[count].name,output_1);
        fputs(", ",output_1);
        fputs(data[count].mate,output_1);
        fputs(", ",output_1);
        fputs(data[count].concerntrate,output_1);
        fputs(", ",output_1);
        fputs(data[count].unit,output_1);
        fputs("\n",output_1);
        fputs(data[count].name,output_2);
        fputs(", ",output_2);
        fputs(data[count].mate,output_2);
        fputs(", ",output_2);
        fputs(data[count].concerntrate,output_2);
        fputs(", ",output_2);
        fputs(data[count].unit,output_2);
        fputs("\n",output_2);
    }
    for(int count=0;count<1000;count++)
        data_free(&data[count]);
    fclose(output_1);
    fclose(output_2);
    fclose(file);
    file=fopen(".\\outcomeBinary.bin","rb");
    output_3=fopen(".\\outcomePair.csv.","w");
    num=0;
    for(int count=0;count<1000;count++)
        data_initialize(&data[count]);
    for(int count=0;count<1000;count++){
        data[count].name=str_in(data[count].name,file);
        data[count].mate=str_in(data[count].mate,file);
        data[count].concerntrate=str_in(data[count].concerntrate,file);
        data[count].unit=str_in(data[count].unit,file);
        data[count].index=count;
        num++;
    }
    for(int count=2;count<num;count++){
        for(int count2=count;count2>=2;count2--){
            if(strcmp(data[count2].name,data[count2-1].name)==0)
                if(numcmp(data[count2].concerntrate,data[count2-1].concerntrate)>0)
                    swap(&data[count2],&data[count2-1]);
                else
                    break;
            else
                break;
        }
    }
    for(int count=0;count<1000;count++){
        fputs(data[count].name,output_3);
        fputs(", ",output_3);
        fputs(data[count].mate,output_3);
        fputs(", ",output_3);
        fputs(data[count].concerntrate,output_3);
        fputs(", ",output_3);
        fputs(data[count].unit,output_3);
        fputs("\n",output_3);
    }
    fclose(output_3);
    fclose(file);
    return 0;
}
