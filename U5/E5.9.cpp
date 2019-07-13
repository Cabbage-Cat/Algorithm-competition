#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}

const int maxn = 10000+5,maxm = 10+2;
map<string,int> IDcache;
int database[maxn][maxm];


int ID(string s){
    if (IDcache.count(s)) return IDcache[s];
    return IDcache[s] = IDcache.size();
}

int main(){
    int n,m;
    string s,line;
    while (scanf("%d%d ",&n,&m)==2 && n){
        IDcache.clear();
        memset(database,0,sizeof(database));
        _for(i,0,n){
            getline(cin,line);
            stringstream ss(line);
            _for(j,0,m){
                getline(ss,s,',');
                database[i][j] = ID(s);
            }
        }
        int flag = 0;
        _for(i,0,m){
            if (flag) break;
            _for(j,i+1,m){
                if (flag) break;
                map<pair<int,int>,int> rowcache;
                _for(k,0,n){
                    pair<int,int> x = pair<int,int>(database[k][i],database[k][j]);
                    if (rowcache.count(x)){
                        printf("NO\n");
                        printf("%d %d\n%d %d\n",rowcache[x]+1,k+1,i+1,j+1);
                        flag = 1;break;
                    }
                    else rowcache[x] = k;
                }
            }
        }
        if (!flag) printf("YES\n");
    }
    return 0;
}