#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

typedef pair<int,int> p;
p d[8] = {p(-1,-1),p(-1,0),p(-1,1),p(0,-1),p(0,1),p(1,-1),p(1,0),p(1,1)};

int readint(){
    int x; scanf("%d",&x); return x;
}
int n;
char chess[9][9];
char player[2];
char command[5];
int legal_move[9][9];

int calc_mov(){
    int res = 0;
    memset(legal_move,0,sizeof(legal_move));
    _for(j,0,8)
        _for(i,0,8){
            if (chess[i][j]!='-') continue;
            int flag=0;
            _for(k,0,8){
                int x=i,y=j;
                x+=d[k].first;y+=d[k].second;
                if (x>=0&&x<8&&y>=0&&y<8&&chess[x][y]!='-'&&chess[x][y]!=player[0]){
                    do{
                        x+=d[k].first;y+=d[k].second;                
                        if (!(x>=0&&x<8&&y>=0&&y<8)) break;
                        if (chess[x][y]=='-') break;
                        if (chess[x][y]==player[0]) {flag=1;break;}
                    }
                    while(x>=0&&x<8&&y>=0&&y<8&&chess[x][y]!='-'&&chess[x][y]!=player[0]);
                }
            }
            if (flag) {legal_move[i][j]=1;res++;};
        }
    return res;
}
void pnt_mov(){
    int res = calc_mov();
    int r=0;
    if (res){
        _for(i,0,8)
            _for(j,0,8) 
                if (legal_move[i][j]){
                    if (!r++) printf("(%d,%d)",i+1,j+1);
                    else printf(" (%d,%d)",i+1,j+1);
                } 
        printf("\n");
    }else printf("No legal move.\n");
}
void change_player(){
    if (player[0]=='W'){
        player[0] = 'B';
    }            
    else player[0] = 'W';
}
void mov_chess(int x,int y){
    calc_mov();
    if (!legal_move[x][y]){
        change_player();
        calc_mov();
    }
    chess[x][y] = player[0];
    _for(i,0,8){
        int xx=x,yy=y;
        xx+=d[i].first;yy+=d[i].second;
        if (xx>=0&&xx<8&&yy>=0&&yy<8&&chess[xx][yy]!='-'&&chess[xx][yy]!=player[0]){
            do{
                xx+=d[i].first;yy+=d[i].second;
                if (!(xx>=0&&xx<8&&yy>=0&&yy<8)) break;
                if (chess[xx][yy]=='-') break;
                if (chess[xx][yy]==player[0]){
                    for (int tmpx=x,tmpy=y;!(tmpx==xx&&tmpy==yy);tmpx+=d[i].first,tmpy+=d[i].second) chess[tmpx][tmpy]=player[0];

                }
            }while(x>=0&&x<8&&y>=0&&y<8);
        }
    }
    int black=0,white=0;
    _for(i,0,8) _for(j,0,8){
        if (chess[i][j]=='B') black++;
        else if (chess[i][j]=='W') white++;
    }
    printf("Black - %2d White - %2d\n",black,white);
    change_player();
}

int main(){
    n = readint();
    int kase=0;
    while (n--){
        if (kase++>0) printf("\n");
        memset(chess,0,sizeof(chess));
        _for(i,0,8) scanf("%s",chess[i]);
        scanf("%s",player);
        do{
            scanf("%s",command);
            if (command[0]=='L') pnt_mov();
            if (command[0]=='M') mov_chess(command[1]-'0'-1,command[2]-'0'-1);
            if (command[0]=='Q') _for(i,0,8) printf("%s\n",chess[i]);
        } while (command[0]!='Q');
    }
    return 0;
}