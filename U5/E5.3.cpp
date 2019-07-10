#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}

set<string> dict;
int main(){
    string s,buf;
    while(cin>>s){
        _for(i,0,s.length())
            if (isalpha(s[i])) s[i] = tolower(s[i]); else s[i]=' ';
        stringstream ss(s);
        while (ss>>buf) dict.insert(buf); 
    }
    for (set<string>::iterator it=dict.begin();it!=dict.end();it++) cout << *it << "\n";
    return 0;
}