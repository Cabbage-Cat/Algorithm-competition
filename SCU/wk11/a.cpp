#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 34;
int d[maxn];
int main(){
  int n=0; long long sum=0;
  while (scanf("%d",&d[n])==1) { sum+=d[n++]; };
  n--; n = (2<<(n-1)); sum*=n;
  cout << sum;
  return 0;
}