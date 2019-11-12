#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 200 + 10;
int a[maxn][maxn];
int m,n;
int main(){
  cin >> m >> n;
  for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++){
      scanf("%d",&a[i][j]);
      a[i][j] += max(a[i-1][j-1],max(a[i-1][j],a[i-1][j+1]));
    }
  cout << max(a[m][n/2],max(a[m][n/2+1],a[m][n/2+2]));
  return 0; 
}
