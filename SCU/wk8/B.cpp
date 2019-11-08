#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int res = 0; int x,y;
  while (n--){
    cin >> x >> y;
    res = max(res,x+y);
  }  
  cout << res << endl;
  return 0;
}