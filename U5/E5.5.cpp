#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
#define ALL(x) (x).begin(),(x).end()
#define INS_ITER(x) inserter((x),(x).begin())
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x){
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main(){
    int t;t=readint();
    int n;string op;
    while (t--){
        IDcache.clear();Setcache.clear();
        stack<int> s;
        n=readint();
        _for(i,0,n){
            cin >> op;
            if (op[0]=='P') s.push(ID(Set())) ;
            else if (op[0]=='D') s.push(s.top());
            else{
                Set x1 = Setcache[s.top()]; s.pop();
                Set x2 = Setcache[s.top()]; s.pop();
                Set x;

                if (op[0]=='U') set_union(ALL(x1),ALL(x2),INS_ITER(x));
                else if (op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS_ITER(x));
                else{
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << "\n";
        }
        cout << "***" << '\n';
    }
    return 0;
}