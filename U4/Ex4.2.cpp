#include <bits/stdc++.h>
using namespace std;

int sq[10][10];
int h[10][10];int v[10][10];
int n,m,kase=0;
int sq_num[10];
int count_square(int side){
    int res=0;
    for (int i=0;i<n-side;i++)
        for (int j=0;j<n-side;j++){
            int flag = 1;
            for (int k=0;k<side;k++)
                if ( !(h[i][j+k] && h[i+side][j+k] && v[i+k][j] && v[i+k][j+side])){
                    flag = 0;
                    break;
                }
            if (flag) res++;
        }
    return res;
}

int main(){
    while (scanf("%d%d",&n,&m)==2 &&n){
        char s[3];
        int x,y,res=0;
        memset(h,0,sizeof(h));memset(v,0,sizeof(v));memset(sq_num,0,sizeof(sq_num));
        for (int i=0;i<m;i++){
            scanf("%s",s);
            scanf("%d%d",&x,&y);x--;y--;
            if (s[0] == 'H') h[x][y] = 1;
            else v[y][x] = 1;
        }
        if (kase>0) printf("**********************************\n\n");
        printf("Problem #%d\n\n",++kase);

        for (int i=1;i<=n;i++){
            sq_num[i] = count_square(i);
            res+=sq_num[i];
            if (sq_num[i]) printf("%d square (s) of size %d\n",sq_num[i],i);
        }
        if (!res) printf("No completed squares can be found.\n");
    }
    return 0;
}