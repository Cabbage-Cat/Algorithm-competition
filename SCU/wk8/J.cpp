#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int l[maxn];
int main(){
  int a,b,c,d; cin >> a >> b >> c >> d;
  int res=-1;
  int flag = 1;
  if (b==d || (b-d>0&&(b-d)%c==0) ) { res=b; flag = 0; }
  if ((d-b>0&&(d-b)&a==0)) { res = d; flag =  0;}
  if (flag){
    for (int k2=0;!l[k2];k2++){
      int r = d-b+k2*c;
      if (r>=0)
        if (r%a==0) { flag = 0; res = r+b; break; }
    }
  }
  if (flag) cout << -1;
  else cout << res;
  
  return 0;
}