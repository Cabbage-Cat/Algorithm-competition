#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int a[maxn];
int main(){
  int t,n; cin >> t;
  while (t--){
    memset(a,0,sizeof(a));
    cin >> n;
    int res = n;
    while(res >3){
      int pos = 0;
      for (int i=0;i<n&&res>3;i++){
        if (!a[i]) {
          pos = !pos;
          if (!pos) { a[i]=1; res--; }
        }
      }
      pos = 0;
      for (int i=0;i<n&&res>3;i++){
        if (!a[i]){
          pos+=1;
          if (pos==3){
            pos = 0;
            a[i] = 1;
            res--;
          }
        }
      }
    }
    vector<int> ans;
    
    for (int i=0;i<n;i++)
      if (!a[i]) ans.push_back(i+1);
    for (vector<int>::iterator it = ans.begin();it!=ans.end();it++){
      if (it!=ans.end()-1) printf("%d ",*it);
      else printf("%d\n",*it);
    }
  }
  return 0;
}