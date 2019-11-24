#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int d[11][11];
int t,m,n;
int f(int m,int n){
  if (d[m][n]) return d[m][n];
  if (m==0||n==1) return 1;
  int res;
  if (m<n) { res = f(m,m); }
  else { res=f(m,n-1)+f(m-n,n);  }
  return res;
}
int main(){
  scanf("%d",&t);
  while (t--){
    cin >> m >> n;
    cout << f(m,n) << endl;
  }
  return 0;
}