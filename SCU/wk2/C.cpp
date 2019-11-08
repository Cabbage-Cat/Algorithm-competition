#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;m--;
  while (~scanf("%d%d",&n,&m)){
    double res = 0;
    double nn = n;
    if (m>=1) res+=n;
    for (int i=2;i<=m;i++){
      nn = sqrt(nn); res+=nn;
    }
    printf("%.2lf\n",res);
  }
  return 0;
}