#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}

struct Martrix{
    int a,b;
    Martrix(int a=0,int b=0):a(a),b(b) {}
}m[26];
int main(){
    int n; cin >> n;
    _for(i,0,n){
        string name; cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while (cin >> expr){
        int len = expr.length();
        bool error = false;
        int ans = 0;
        stack<Martrix> s;
        _for(i,0,len){
            if (isalpha(expr[i])) s.push(m[expr[i]-'A']);
            else if (expr[i]==')'){
                Martrix m2 = s.top(); s.pop();
                Martrix m1 = s.top(); s.pop();
                if (m1.b!=m2.a) { error = true;break;}
                ans += m1.a * m1.b * m2.b;
                s.push(Martrix(m1.a,m2.b));
            }
        }
        if (error) printf("error\n"); else printf("%d\n",ans);
    }
    return 0;
}