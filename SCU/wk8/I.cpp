#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int d[maxn];
int main(){
  int n; cin >> n; int res = 0; int x;
  for (int i=0;i<n;i++){
    scanf("%d",&x);
    if (x%2) { res=1; break; }
  }
  if (res) cout << "First";
  else cout << "Second";
  
  return 0;
}