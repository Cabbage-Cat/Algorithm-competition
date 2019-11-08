#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow_mod(ll a,ll n,ll m){
  if (n==0) return 1;
  ll x = pow_mod(a,n/2,m);
  ll ans = x*x%m;
  if (n%2==1) ans = ans*a%m;
  return ans;
}
int main(){
  ll a,n,m; cin >> a >> n >> m; ll ans;
  ans = pow_mod(a,n,m);
  printf("%lld^%lld mod %lld=",a,n,m);
  printf("%lld",ans%m);
  return 0;
}