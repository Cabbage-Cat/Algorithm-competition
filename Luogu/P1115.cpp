#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 15;
int A[maxn];
int main(){
  int n; cin >> n;
  for (int i=1;i<=n;i++){
    scanf("%d",A+i);
    if (A[i-1] > 0)
      A[i] += A[i-1];
  }
  int res = -99999999;
  for (int j=1;j<=n;j++)
    if (A[j]>res) res = A[j];
  cout << res;
  return 0;
}