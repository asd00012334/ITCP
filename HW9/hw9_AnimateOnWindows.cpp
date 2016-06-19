#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void gotorc(int row, int col){
    COORD screen;
    HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    screen.X=col;
    screen.Y=row;
    SetConsoleCursorPosition(handleOutput,screen);
}

struct Maze{
    pair<int,int> start;
    vector<vector<int> > mapp;

    vector<int> & operator[](int row){return mapp[row];}

    bool within(pair<int,int> test){
        return 0<=test.first&&test.first<mapp.size()&&
        0<=test.second&&test.second<mapp[test.first].size();
    }
    bool edge(pair<int,int> test){
        return test.first==0||test.second==0||
        test.first==mapp.size()-1||test.second==mapp[test.first].size()-1;
    }

    Maze(int rowN, int colN){
        for(int row=0;row<rowN;row++){
            vector<int> rowLine(colN,'#');
            mapp.push_back(rowLine);
        }
        start.first=rand()%rowN;
        start.second=rand()%colN;
        vector<pair<int,int> > dfs;
        dfs.push_back(start);
        bool traversed[rowN][colN];
        for(int row=0;row<rowN;row++)
        for(int col=0;col<colN;col++)
            traversed[row][col]=false;
        while(1){
            vector<pair<int,int> > dir={pair<int,int>(-1,0),pair<int,int>(+1,0),pair<int,int>(0,-1),pair<int,int>(0,+1)};
            if(dfs.empty()) break;
            pair<int,int> cur=dfs.back();
            dfs.pop_back();
            if(!within(cur)) continue;
            if(traversed[cur.first][cur.second]) continue;
            int aroundTra=0;
            for(int cnt=0;cnt<dir.size();cnt++)
                if(within(pair<int,int>(cur.first+dir[cnt].first,cur.second+dir[cnt].second)))
                    if(mapp[cur.first+dir[cnt].first][cur.second+dir[cnt].second]!='#')
                        aroundTra++;
            if(aroundTra<2&&!edge(cur)){
                traversed[cur.first][cur.second]=true;
                mapp[cur.first][cur.second]='.';
            }
            else continue;
            for(int cnt=0;cnt<dir.size();cnt++)
                swap(dir[cnt],dir[rand()%dir.size()]);
            for(int cnt=0;cnt<dir.size();cnt++)
                dfs.push_back(pair<int,int>(cur.first+dir[cnt].first,cur.second+dir[cnt].second));
        }

        while(1){
            int cnt=rand()%mapp.size();
            if(mapp[cnt][mapp[0].size()-2]=='.'){
                mapp[cnt][mapp[0].size()-1]='.';
                break;
            }
        }
    }

    Maze():Maze(20,20){};

    Maze(Maze const& ini): start(ini.start),mapp(ini.mapp){}

    Maze(vector<vector<int> > mapp, pair<int,int> start):start(start),mapp(mapp){}

    friend ostream& operator<<(ostream& out, Maze const& maze){
        for(int row=0;row<maze.mapp.size();row++){
            for(int col=0;col<maze.mapp[row].size();col++){
                if(col) out<<" ";
                out<<(char)maze.mapp[row][col];
            }
            out<<"\n";
        }
        return out;
    }

    void print(pair<int,int> const& anchorLU, pair<int,int> const& anchorRD, pair<int,int> const& screenAnchor){
        for(int row=anchorLU.first;row<=anchorRD.first;row++){
            int col=anchorLU.second;
            gotorc(row+screenAnchor.first,col+screenAnchor.second);
            for(;col<=anchorRD.second;col++){
                if(col!=anchorLU.second) cout<<" ";
                cout<<(char)(*this)[row][col];
            }
        }
    }

};


int main(){
    srand(time(NULL));
    vector<string> smaze1=
    {"############",
     "#...#......#",
     "..#.#.####.#",
     "###.#....#.#",
     "#....###.#..",
     "####.#.#.#.#",
     "#..#.#.#.#.#",
     "##.#.#.#.#.#",
     "#........#.#",
     "######.###.#",
     "#......#...#",
     "############"};
    vector<vector<int> > mapp1;
    for(int row=0;row<smaze1.size();row++){
        vector<int > tempLine;
        for(int col=0;col<smaze1[row].size();col++)
            tempLine.push_back(smaze1[row][col]);
        mapp1.push_back(tempLine);
    }
    Maze maze1(mapp1,pair<int,int>(2,0));
    Maze maze2(21,21);
    vector<pair<int,int> > dfs;
    bool adjTra[maze1.mapp.size()][maze1[0].size()];
    for(int row=0;row<maze1.mapp.size();row++)
    for(int col=0;col<maze1[0].size();col++)
        adjTra[row][col]=false;
    dfs.push_back(maze1.start);
    cout<<maze1<<endl;
    while(1){
        vector<pair<int,int> > dir={pair<int,int>(-1,0),pair<int,int>(+1,0),pair<int,int>(0,-1),pair<int,int>(0,+1)};
        if(dfs.empty()) break;
        pair<int,int> cur=dfs.back();
        dfs.pop_back();
        if(!maze1.within(cur)) continue;
        if(adjTra[cur.first][cur.second]) continue;
        if(maze1[cur.first][cur.second]=='.'){
            Sleep(100);
            maze1[cur.first][cur.second]='*';
            maze1.print(pair<int,int>(0,0),
                        pair<int,int>(maze1.mapp.size()-1,maze1[0].size()-1),
                        pair<int,int>(0,0));
            if(cur!=maze1.start&&maze1.edge(cur))
                break;
        }
        else continue;
        for(int cnt=0;cnt<dir.size();cnt++)
            dfs.push_back(pair<int,int>(cur.first+dir[cnt].first,cur.second+dir[cnt].second));
    }
    bool adjTra2[maze2.mapp.size()][maze2[0].size()];
    for(int row=0;row<maze2.mapp.size();row++)
    for(int col=0;col<maze2[0].size();col++)
        adjTra2[row][col]=false;
    dfs.push_back(maze2.start);
    system("cls");
    cout<<maze2<<endl;
    while(1){
        vector<pair<int,int> > dir={pair<int,int>(-1,0),pair<int,int>(+1,0),pair<int,int>(0,-1),pair<int,int>(0,+1)};
        if(dfs.empty()) break;
        pair<int,int> cur=dfs.back();
        dfs.pop_back();
        if(!maze2.within(cur)) continue;
        if(adjTra2[cur.first][cur.second]) continue;
        if(maze2[cur.first][cur.second]=='.'){
            Sleep(100);
            maze2[cur.first][cur.second]='*';
            maze2.print(pair<int,int>(0,0),
                        pair<int,int>(maze2.mapp.size()-1,maze2[0].size()-1),
                        pair<int,int>(0,0));
            if(maze2.edge(cur)&&cur!=maze2.start) break;
        }
        else continue;
        for(int cnt=0;cnt<dir.size();cnt++)
            dfs.push_back(pair<int,int>(cur.first+dir[cnt].first,cur.second+dir[cnt].second));
    }
    dfs.resize(0);
    return 0;
}
