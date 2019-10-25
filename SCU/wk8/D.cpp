#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int flag = 0;
  for (int k = sqrt(2*n);k>1;k--){
    if ((2*n)%k==0){
      int ta = 2*n/k-k+1;
      if (ta%2==0) { flag = 1; cout << ta/2 << endl; }
    }
  }
  if (!flag) cout << "No Solution";
  return 0;
}

