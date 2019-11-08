#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[100 + 10];
int vis[100 + 10];
int main(){
  int q,n; cin >> q;
  while (q--){
    cin >> n; for (int i=0;i<n;i++) cin >> d[i];
    sort(d,d+n);
    int res = 0;
    memset(vis,0,sizeof(vis)); 
    for (int i=0;i<n;i++){
      if (!vis[i]){
        vis[i] = 1; int pos = i; res++;
        for (int j=i+1;j<n;j++) if (d[j]-d[pos]!=1 && !vis[j]){
          vis[j] = 1; 
          pos = j;
        } 
      }
    }
    cout << res << endl; 
  }
  return 0;
}