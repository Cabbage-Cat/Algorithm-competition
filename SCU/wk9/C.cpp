#include <bits/stdc++.h>
using namespace std;
const int maxn = 32767 *2 + 10;
int n,m;
int a[maxn];
int main(){
  while (scanf("%d%d",&n,&m)==2){
    memset(a,0,sizeof(a));
    int pos = -1;
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        pos = (pos+1)%(2*n);
        while(a[pos]) pos = (pos+1)%(2*n);
      }
      a[pos] = 1;
    }
    int count = 0;
    for (int i=0;i<2*n;i++){
      if (count++>=50) { putchar('\n'); count=0; }
      if (a[i]) putchar('B');
      else putchar('G');
    }
    printf("\n\n");
  }
  return 0;
}