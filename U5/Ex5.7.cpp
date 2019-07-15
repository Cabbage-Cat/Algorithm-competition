#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
const int maxn = 100+2,maxp=10;

int n,m,priority[maxn],pCnt[maxp];
int main(){
    int t = readint();
    while (t--){
        n = readint(); m = readint();
        memset(pCnt,0,sizeof(pCnt));
        queue<int> q;
        _for(i,0,n){
            cin >> priority[i];
            q.push(i);
            pCnt[priority[i]]++;
        }

        int timer = 1;
        while (!q.empty()){
            int t = q.front(), p = priority[t];
            bool lower = false;
            for (int i=maxp-1;i>p;i--)
                if (pCnt[i]>0){
                    lower=true;break;
                }
            q.pop();
            if (lower) {q.push(t);continue;}
            if (t==m) break;
            pCnt[p]--;
            timer++;
        }
        cout << timer << endl;
    }
    return 0;
}