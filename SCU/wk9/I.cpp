#include <bits/stdc++.h>
using namespace std;
set<string> cache;

string prev_do(string s){
  string x;
  for (char c: s) if (isupper(c) || islower(c)) x.push_back(tolower(c));
  return x;
}
int main(){
  string s;
  while (cin >> s) cache.insert(prev_do(s));
  for (string s : cache) cout << s << endl;
  return 0;
}