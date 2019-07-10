#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}

map<string,int> cnt;
vector<string> words;

string repr(const string& s){
    string ans = s;
    _for(i,0,ans.length())
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n=0;
    string s;
    while (cin >> s){
        if (s[0]=='#') break;
        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r)) cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> res;
    _for(i,0,words.size())
        if (cnt[repr(words[i])]==1) res.push_back(words[i]);
    sort(res.begin(),res.end());
    _for(i,0,res.size())
        cout << res[i] << endl;
    return 0;
} 