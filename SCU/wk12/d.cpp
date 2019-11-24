#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
  ll n; cin >> n;
  ll res=0;
  while (n>0){
    res+=(n+1)/2;
    n/=2;n/=2;
  }
  cout << res;
  return 0;
}