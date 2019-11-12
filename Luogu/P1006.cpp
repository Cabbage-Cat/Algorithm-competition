#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50+2;
int a[maxn][maxn];
int f[maxn][maxn][maxn][maxn];
int main(){
  int m,n; cin >> m >> n;
  for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
      for (int p=i+1;p<=m;p++)
        for (int q=1;q<j;q++)
            f[i][j][p][q] = max(max(f[i-1][j][p-1][q],f[i-1][j][p][q-1]),max(f[i][j-1][p-1][q],f[i][j-1][p][q-1]))  + a[i][j] + a[p][q] ;
  cout << f[m-1][n][m][n-1];
}