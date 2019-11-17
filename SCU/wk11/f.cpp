#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
  if (x<y) return gcd(y,x);
  if (y==0) return x;
  return gcd(y,x-y);
}
ll lcs(ll x,ll y){
  return x/gcd(x,y)*y;
}
int main(){
  ll a,b; cin >> a >> b;
  cout << lcs(a,b);
  return 0;
}