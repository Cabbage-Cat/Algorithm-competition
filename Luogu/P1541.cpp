#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 350 + 10;
int a[maxn];
int f[44][44][44][44];
int main(){
  int n,m; cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> a[i];
  int i_max=0,j_max=0,m_max=0,n_max=0;
  int tmp;
  for (int i=0;i<m;i++){
    cin >> tmp;
    switch (tmp)
    {
    case 1:
      i_max++;
      break;
    case 2:
      j_max++;
      break;
    case 3:
      m_max++;
      break;
    case 4:
      n_max++;
      break;
    default:
      break;
    }
  }
  f[0][0][0][0] = a[1];
  for (int i=0;i<=i_max;i++)
    for (int j=0;j<=j_max;j++)
      for (int m=0;m<=m_max;m++)
        for (int n=0;n<=n_max;n++){
          int res[5]; memset(res,0,sizeof(res));
          int p = 1+ i*1 + j*2 + m*3 + n*4;
          if (i>0)
            res[1] = f[i-1][j][m][n];
          if (j>0)
            res[2] = f[i][j-1][m][n];
          if (m>0)
            res[3] = f[i][j][m-1][n];
          if (n>0)
            res[4] = f[i][j][m][n-1];
          int r = max(max(res[1],res[2]),max(res[3],res[4]));
          f[i][j][m][n] = max(f[i][j][m][n],r+a[p]);
        }
  cout << f[i_max][j_max][m_max][n_max];
  return 0;
}