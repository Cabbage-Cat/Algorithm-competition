#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

int main(){
  int q;
  int n;
  cin >> q;
  while (q--){
    cin >> n;
    int x; int s = 0;
    for (int i=0;i<n;i++){
      cin >> x; s+=x;
    }
    int res = s/n;
    if (s%n) res++;
    cout << res << endl;
  }
  return 0;
}