#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 100;
int is_prime[maxn];
ll fac_sum[maxn];
int main(){
  for (int i=2;i<=maxn;i++) is_prime[i] = 1;
  for (int i=2;i<=maxn;i++) if (is_prime[i]) for (int j=i+i;j<=maxn;j+=i) is_prime[j] = 0;
  for (int i=2;i<=maxn;i++){
    if (is_prime[i]){
      fac_sum[i] = 1;
      for (int j=i*2;j<=maxn;j+=i){
        if (!fac_sum[j]&&fac_sum[j/i]) fac_sum[j] = fac_sum[j/i] + 1;
      }
    }
  }
  for (int i=3;i<=maxn;i++) fac_sum[i] += fac_sum[i-1];
  int n;
  while (scanf("%d",&n)==1){
    printf("%lld\n",fac_sum[n]);
  }

  return 0;
}