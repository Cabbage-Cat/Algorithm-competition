#include <bits/stdc++.h>
using namespace std;

int main(){
  int k; cin >> k;
  int a1; int flag = 0;
  for (a1=1;a1<=k/2;a1++){
    int s; 
    s = (int)sqrt((2*a1-1)*(2*a1-1)+8*k);
    if (s*s == (2*a1-1)*(2*a1-1)+8*k && (s+1-2*a1)%2==0){
      flag = 1;
      cout << a1 << endl;
    }
  }
  if (!flag) cout << "No Solution";
  return 0;
}

