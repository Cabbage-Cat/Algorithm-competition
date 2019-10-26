#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int a[maxn],b[maxn];
int gcd(int x ,int y){
  return y?gcd(y,x%y):x;
}
int main(){
  int t; cin >> t; int n;
  for(int tt = 1;tt<=t;tt++) {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i+1];
    for (int i=0;i<n;i++) cin >> b[i+1];
    int p=b[n],q=a[n];
    for (int i=n-1;i>0;i--){
      int p_tmp = p;
      p = q*b[i];
      q = a[i]*q+p_tmp;
    }
    int x = gcd(p,q);
    printf("Case #%d: %d %d\n",tt,p/x,q/x);
  }
  return 0;
}