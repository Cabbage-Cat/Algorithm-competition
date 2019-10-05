#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int f[maxn];
int dfs(int n,int k){
  if (n<0) return 0;
  if (f[n]>-1) return f[n];
  int res = 0;
  for (int i=1;i<=k;i++) res+=dfs(n-i,k);
  res%=100003;
  f[n] = res;
  return res;
}
int main(){
  memset(f,-1,sizeof(f));
  int n,k; cin >> n >> k;
  f[0] = 1;
  cout << dfs(n,k);
  return 0;
}