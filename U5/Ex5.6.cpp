#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
typedef pair<int,int> P;
set<P> points;
bool is_sym(int sym,P p){
    if (p.first == sym) return true;
    P x;
    x.first = 2*sym - p.first; x.second = p.second;
    return points.count(x)>0;
}
int main(){
    int t; cin >> t;
    while (t--){
        points.clear();
        int n; cin >> n;
        P p; int sym = 0;
        _for(i,0,n){
            cin >> p.first >> p.second; 
            p.first*=n; p.second*=n; points.insert(p);
            sym+=p.first/n;
        }
        bool flag = true;
        for (P x:points){
            if (!is_sym(sym,x)){
                flag = false;break;
            }
        }
        puts(flag?"YES":"NO");

    }
    return 0;
}