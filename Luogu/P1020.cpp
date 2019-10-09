#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
int d[maxn];
int d1[maxn];
int d2[maxn];
int main(){
  int n = 0;
  while (~scanf("%d",&d[n++])); n--;
  d1[0] = d2[0] = d[0];
  int p1=0,p2=0;
  for (int i=1;i<n;i++){
    if (d1[p1]>=d[i]) d1[++p1] = d[i];
    else
      *upper_bound(d1,d1+p1+1,d[i],greater<int>()) = d[i];
    if (d2[p2]<d[i]) d2[++p2] = d[i];
    else
      *lower_bound(d2,d2+p2+1,d[i]) = d[i];
  }
  cout << p1+1 << endl << p2+1;
  return 0;
}