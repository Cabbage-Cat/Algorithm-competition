#include <bits/stdc++.h>
using namespace std;
int n,r;
char base[17] = "0123456789ABCDEF";
char s[100000 + 10];
int main(){
  while (scanf("%d%d",&n,&r)==2){
    int flag = 0;
    if (n<0) { flag = 1; n=-n;}
    int i=-1,k;
    while (n){
      k = n%r;
      s[++i] = base[k];
      n/=r;
    }
    if (flag) putchar('-');
    for (int j=i;j>=0;j--) putchar(s[j]);
    printf("\n");
  }
  return 0;
}