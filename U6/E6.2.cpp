#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
const int maxn = 1000+10;
int n,target[maxn];
int main(){
    int kase=0;
    while (scanf("%d",&n)==1){
        if (kase++) printf("\n");
        while (scanf("%d",&target[1])==1 && target[1]){
            _rep(i,2,n) target[i]=readint();
            stack<int> c;
            bool ok = true;
            int A=1,B=1;
            while (B<=n){
                if (A==target[B]) {A++;B++;}
                else if (!c.empty() && c.top()==target[B]) {c.pop(); B++;}
                else if (A<=n) {c.push(A); A++;}
                else {ok=false;break;}
            }
            printf("%s\n",ok?"Yes":"No");    
        }
    }
    return 0;
}