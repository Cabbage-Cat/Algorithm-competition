#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000000 + 15;
ll d[maxn];

int main(){
  int n; cin >> n;
  for (int i=1;i<=n;i++) d[i] = d[i-1] + i;
  for (int i=1;i<=n;i++){
    ll ans = d[i-1] + n;
    ll idx = lower_bound(d,d+n+1,ans) - d;
    if (ans == d[idx] && i!=idx) cout <<i << " "<<idx <<endl; 
  }
}