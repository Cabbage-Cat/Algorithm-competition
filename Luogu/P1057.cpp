#include <bits/stdc++.h>
using namespace std;

const int maxn = 30 + 5;
int dp[maxn][maxn];
int main(){
  int n,m; cin >> n >> m;
  dp[0][0] = 1;
  for (int i=0;i<=m;i++)
    for (int j=0;j<n;j++){
      if (dp[i][j]){
        dp[i+1][(j-1+n)%n] += dp[i][j];
        dp[i+1][(j+1)%n] += dp[i][j];
      }
    }
  cout << dp[m][0];
  return 0;
}