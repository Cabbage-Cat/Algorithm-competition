#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll res[21];
int main(){
  res[0] = 1;
  for (int i=1;i<=20;i++) res[i] = i*res[i-1];
  int n; cin >> n;
  cout << res[n];
  return 0;
}