#include <bits/stdc++.h>
using namespace std;
const int maxn = 12 + 2;
int frac(int x){  
  return x==0?1:x*frac(x-1);
}
int a[maxn];
int f[maxn];
int fr[maxn];
int main(){
  int n,sum;
  cin >> n >> sum;
  for (int i=0;i<maxn;i++) fr[i] = frac(i);
  for (int i=0;i<n;i++){
    a[i] = i+1;
    f[i] = fr[n-1] / (fr[i] * fr[n-1-i]);
  } 
  do{
    int s = 0; 
    for (int i=0;i<n;i++){
      s += a[i] * f[i];
      if (s>sum && i < n-1){
        sort(a+i+1,a+n,greater<int>());
        break;
      }  
    }
    if (s==sum){
      for (int i=0;i<n;i++) printf("%d ",a[i]);
      break;
    }
  }while (next_permutation(a,a+n));
  return 0;
}