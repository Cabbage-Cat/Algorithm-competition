#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn],b[maxn];
int main(){
  int n; cin >> n;
  for (int i=0;i<n;i++)
    scanf("%d%d",a+i,b+i);
  int res = 0;
  for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
      if (a[i] + a[j] == b[i] + b[j]) res++;
  cout << res;
  return 0;
}