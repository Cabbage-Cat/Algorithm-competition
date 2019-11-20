#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1000000 + 10;
int prime[maxn];
int vis[maxn];
int sum[maxn];
void euler(){
  int cnt = 0;
  for (int i=2;i<maxn;i++){
    if (!vis[i]) prime[cnt++] = i;
    for (int j=0;j<cnt&&prime[j]*i<maxn;j++){
      vis[i*prime[j]] = 1;
      if (i%prime[j]==0) break;
    }
  }
}
int main(){
  euler();
  vis[0] = vis[1] = 1;
  for (int i=0;i<maxn;i++){
    vis[i] = !vis[i];
  }
  for (int i=1;i<maxn;i++)
    sum[i] = sum[i-1] + vis[i];
  int l,r,n,m;
  cin >> n >> m;
  for (int i=0;i<n;i++){
    cin >> l >> r;
    if (l<1||r>m)
      cout << "Crossing the line\n";
    else 
      cout << sum[r]-sum[l-1] << endl;
  }
  return 0;
}