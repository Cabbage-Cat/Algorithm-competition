#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
  if (y==0) return x;
  return gcd(y,x%y);
}

int main(){
  int p,q; cin >> p >>q;
  int res = p*q;
  int cnt = 0;
  for (int i=1;i<=sqrt(res);i++){
    if (res%i==0){
      if (gcd(i,res/i)==p) cnt++;
    } 
  }
  cnt*=2;
  cout << cnt;
  return 0;
}