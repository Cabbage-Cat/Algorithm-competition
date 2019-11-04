#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while (scanf("%d",&n)==1){
    map<string,int> cache;
    for (int i=0;i<n;i++){
      string s; cin >> s;
      cache.insert(pair<string,int>(s,0));
    }
    int m; cin >> m;
    while (m--){
      string ss; int x; 
      for (int i=0;i<n;i++){
        cin >> x >> ss;
        cache[ss]+=x;
      }
      int res = 1;
      map<string,int>::iterator it;
      it = cache.find("memory"); int xx = it->second; it = cache.begin(); 
      while (it!=cache.end()){
        if (it->second > xx) res++;
        it++;
      }
      cout << res << endl;
    }
  }
  
  return 0;
}