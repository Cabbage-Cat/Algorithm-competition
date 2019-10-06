#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int A[maxn];
int main(){
  int n,m; cin >> n >> m;
  for (int i=1;i<=n;i++) A[i] = i;
  int res = n,p=0;
  while (res > 0){
    for (int i=0;i<m;i++){
      while (A[(p+1)%(n+1)]==0) p = (p+1)%(n+1);
      p = (p+1)%(n+1);
    }
    cout << A[p] << " ";
    A[p] = 0; res--;
  }
  return 0;
}