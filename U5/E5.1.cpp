#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
const int maxn = 10000;

int main(){
    int n,q,x,a[maxn],kase=0;
    while (scanf("%d%d",&n,&q)==2&&n){
        printf("CASE# %d:\n",++kase);
        _for(i,0,n) scanf("%d",&a[i]);
        sort(a,a+n);
        while (q--){
            scanf("%d",&x);
            int p = lower_bound(a,a+n,x) - a;
            if (a[p]==x) printf("%d found at %d\n",x,p+1);
            else printf("%d not found\n",x);
        }
    }
    return 0;
}