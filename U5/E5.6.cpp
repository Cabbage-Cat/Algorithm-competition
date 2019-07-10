#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
const int maxt = 1000+2;
int main(){
    int t,kase=0;
    while (scanf("%d",&t)==1 && t){
        cout << "Scenario #" << ++kase << '\n';
        map<int,int> teamcache;
        queue<int> q_team;queue<int> q_num[maxt];
        _for(i,0,t){
            int n = readint();
            _for(j,0,n) teamcache[readint()] = i;
        }

        for (;;){
            string s;int x;
            cin >> s;
            if (s[0] == 'S') break;
            else if (s[0] == 'E'){
                cin >> x;
                int t = teamcache[x];
                if (q_num[t].empty()) q_team.push(t);
                q_num[t].push(x);
            }
            else{
                int t = q_team.front();
                cout << q_num[t].front() << '\n'; q_num[t].pop();
                if (q_num[t].empty()) q_team.pop();
            }
        }
        cout << '\n';
    }
    return 0;
}