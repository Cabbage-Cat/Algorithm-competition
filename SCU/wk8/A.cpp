#include <bits/stdc++.h>
using namespace std;

int main(){
  int T; cin >> T;
  int n,s,t;
  while (T--){
    cin >> n >> s >> t;
    cout << max(n-t,n-s) + 1 << endl;
  } 
  return 0;
}