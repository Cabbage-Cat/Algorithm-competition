#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int d[maxn];
int n,m;
int main(){
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> d[i];
  for (int i=0;i<m;i++) next_permutation(d,d+n);
  for (int i=0;i<n-1;i++) cout << d[i] << " "; cout << d[n-1];
  return 0;
}