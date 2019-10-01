#include <bits/stdc++.h>
using namespace std;

int main(){
  int s,m; 
  while (~scanf("%d%d",&s,&m) && s){
    int flag = 0;
    for (int i=1;i<=abs(m);i++){
      if (m%i!=0) continue;
      if (s==m/i+i || s==-i-m/i) { flag = 1; printf("Yes\n"); break; }
    }
    if (!flag) printf("No\n");
  }
  return 0;
}