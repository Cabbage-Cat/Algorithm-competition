#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100 + 10;
int d[maxn*2];
int f[maxn*2][maxn*2];
int n;
int main(){
  cin >> n;
  for (int i=1;i<=n;i++) cin >> d[i];
  for (int i=n+1;i<=2*n;i++) d[i] = d[i-n]; d[2*n+1] = d[1];
  for (int len = 1;len<=n;len++)
    for (int i=1;i<=2*n-1;i++){
      int j = i+len-1;
      for (int k=i;k<2*n&&k<j;k++)
        f[i][j] = max(f[i][j],f[i][k] + f[k+1][j] + d[i]*d[k+1]*d[j+1]);
    }
  int res = 0;
  for (int i=1;i<=n;i++)
    res = max(res,f[i][i+n-1]);
  cout << res;
  return 0;
}