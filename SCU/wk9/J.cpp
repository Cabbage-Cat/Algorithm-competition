#include <bits/stdc++.h>
using namespace std;
map<string,int> cnt;
vector<string> words;
string do_before(string s){
  string ss = s;
  for (int i=0;i<ss.length();i++) ss[i] = tolower(ss[i]);
  sort(ss.begin(),ss.end());
  return ss;
}
int main(){
  string s;
  while (cin >> s){
    if (s[0]=='#') break;
    words.push_back(s);
    string x = do_before(s);
    if (!cnt[x]) cnt[x] = 0;
    cnt[x]++;
  }
  vector<string> ans;
  for (int i=0;i<words.size();i++)
    if (cnt[do_before(words[i])]==1) ans.push_back(words[i]);
  sort(ans.begin(),ans.end());
  for (string x : ans) cout << x << endl;
  return 0;
}