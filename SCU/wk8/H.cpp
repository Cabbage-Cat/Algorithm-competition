#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int matrix[maxn][maxn];
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++) scanf("%d",&matrix[i][j]);
  int flag = 1,sum=0;
  for (int i=n-1;flag&&i>-1;i--)
    for (int j=m-1;j>-1;j--){
      sum+=matrix[i][j];
      if (matrix[i][j]==0){
        matrix[i][j] = min(matrix[i+1][j],matrix[i][j+1]) -1;
        sum+=matrix[i][j];
      } 
      else{
        if ((i<n-1&&matrix[i][j]>=matrix[i+1][j]) || 
          (j<m-1&&matrix[i][j]>=matrix[i][j+1])) { flag = 0; break; }
      }
    }
  printf("%d\n",flag?sum:-1);
  return 0;
}