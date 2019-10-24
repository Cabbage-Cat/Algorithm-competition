#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; int x;
  while (scanf("%d",&n)==1){
    map<int,int> cache;
    for (int i=0;i<n;i++){
      scanf("%d",&x);
      cache[x]++;
    }
    int s = (n+1)/2;
    int res;
    for (map<int,int>::iterator it=cache.begin();it!=cache.end();it++){
      if (it->second >= s) { res = it->first; break; }
    }
    cout << res << endl;
  }
  return 0;
}