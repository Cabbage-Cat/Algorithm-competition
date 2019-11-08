#include <bits/stdc++.h>
using namespace std;
map<string,int> cache;
int main(){
  string s;
  while (cin >> s){
    if (s=="#") break;
    for (int i=0;i<s.length();i++){
      s[i] = tolower(s[i]);
      cache[s]++;
    }
  }
  map<string,int>::iterator maxptr = cache.begin();
  for (map<string,int>::iterator it = cache.begin();it!=cache.end();it++)
    if (it->second > maxptr->second) maxptr = it;
  cout << maxptr->first;
  return 0;
}