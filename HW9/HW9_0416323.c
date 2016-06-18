#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define test system("pause")
int flag=0;
void mazeTraverse(char*, int, int, int, int);
void print_maze(char*);
void break_walls(char**,int,int,int);
int in_maze(int,int);
int in_broader(int,int);
int mix(char**,int,int);
char* mazeGenerator(void);

int main(){
    srand(time(NULL));
    char *maze_r;
    char maze[12*13]={"############"\
                      "#...#......#"\
                      "..#.#.####.#"\
                      "###.#....#.#"\
                      "#....###.#.."\
                      "####.#.#.#.#"\
                      "#..#.#.#.#.#"\
                      "##.#.#.#.#.#"\
                      "#........#.#"\
                      "######.###.#"\
                      "#......#...#"\
                      "############"};

    mazeTraverse(maze,2,0,0,0);
    printf("\n");
    maze_r=mazeGenerator();
    flag=0;
    mazeTraverse(maze_r,1,0,0,0);
    return 0;
}

void mazeTraverse(char* maze, int row, int col, int startRow, int startColumn){
    if(flag==1) return;
    if(!in_maze(row,col)) return;
    if(maze[12*row+col]=='#'||maze[12*row+col]=='X') return;
    if(row==4&&col==11){
        maze[12*row+col]='X';
        print_maze(maze);
        printf("\nSuccess!\n");
        flag=1;
        return;
    }
    maze[12*row+col]='X';
    print_maze(maze);
    printf("\n");
    mazeTraverse(maze,row+1,col,0,0);
    mazeTraverse(maze,row-1,col,0,0);
    mazeTraverse(maze,row,col+1,0,0);
    mazeTraverse(maze,row,col-1,0,0);
    return;
}
int in_maze(int row,int col){
    if(0<=row&&row<12)
    if(0<=col&&col<12)
    return 1;
    return 0;
}
void print_maze(char* maze){
    int count,count2;
    for(count=0;count<12;count++){
        for(count2=0;count2<12;count2++){
            if(count2!=0) printf(" ");
            printf("%c",maze[count*12+count2]);
        }
        printf("\n");
    }
    return;
}


char* mazeGenerator(void){
    char* maze;
    int count,count2,count3;
    char** Maze;
    maze=malloc(sizeof(char)*12*12);//14

    Maze=(char**)malloc(sizeof(char*)*12);
    for(count=0;count<12;count++)
        Maze[count]=maze+count*12;

    for(count=0;count<12;count++)
    for(count2=0;count2<12;count2++){
        Maze[count][count2]='#';
    }

    int seq[4]={0},direction_r,temp;

    for(count=0;count<4;count++){
        temp=rand()%(4-count)+1;
        direction_r=-1;

        for(count2=1;count2<=temp;count2++){
            direction_r++;
            if(seq[direction_r]==1) count2--;
        }
        seq[direction_r]=1;
    break_walls(Maze,1,1,rand()%4);
    }

    Maze[1][0]='.';
    Maze[4][11]='.';
    if(Maze[4][10]!='.')
        Maze[4][10]='.';
    return maze;
}

void break_walls(char **Maze,int row,int col,int direction){
    int count,count2,count3,unstuck;

    unstuck=0;
    switch(direction){
        case 0:
        if(in_broader(row+1,col))
        if(!mix(Maze,row+1,col))
        if(Maze[row+1][col]=='#'){
            Maze[row][col]='.';
            Maze[row+1][col]='.';
            unstuck=1;
            row+=1;
        }
        break;

        case 1:
        if(in_broader(row-1,col))
        if(!mix(Maze,row-1,col))
        if(Maze[row-1][col]=='#'){
            Maze[row][col]='.';
            Maze[row-1][col]='.';
            unstuck=1;
            row-=1;
        }
        break;

        case 2:
        if(in_broader(row,col+1))
        if(!mix(Maze,row,col+1))
        if(Maze[row][col+1]=='#'){
            Maze[row][col]='.';
            Maze[row][col+1]='.';
            unstuck=1;
            col+=1;
        }
        break;

        case 3:
        if(in_broader(row,col-1))
        if(!mix(Maze,row,col-1))
        if(Maze[row][col-1]=='#'){
            Maze[row][col]='.';
            Maze[row][col-1]='.';
            unstuck=1;
            col-=1;
        }
        break;
    }if(!unstuck) return;

    //randomize a non-repeatedly sequence
    int seq[4]={0},direction_r,temp;

    for(count=0;count<4;count++){
        temp=rand()%(4-count)+1;
        direction_r=-1;

        for(count2=1;count2<=temp;count2++){
            direction_r++;
            if(seq[direction_r]==1) count2--;
        }
        seq[direction_r]=1;
    break_walls(Maze,row,col,direction_r);

    }

    //randomize a non-repeatedly sequence



    return;
}

int in_broader(int row,int col){
    if(1<=row&&row<11)
    if(1<=col&&col<11)
    return 1;
    return 0;
}

int mix(char**Maze,int row,int col){
    int count=0;
    if(in_maze(row+1,col))
    if(Maze[row+1][col]=='.')
        count++;
    if(in_maze(row-1,col))
    if(Maze[row-1][col]=='.')
        count++;
    if(in_maze(row,col+1))
    if(Maze[row][col+1]=='.')
        count++;
    if(in_maze(row,col-1))
    if(Maze[row][col-1]=='.')
        count++;
    return count>=2?1:0;
}
