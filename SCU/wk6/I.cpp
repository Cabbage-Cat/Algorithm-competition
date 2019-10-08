#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 100;
int is_prime[maxn];
int main(){
  for (int i=2;i<=maxn;i++) is_prime[i] = 1;
  for (int i=2;i<=maxn;i++) if (is_prime[i]) for (int j=i+i;j<=maxn;j+=i) is_prime[j] = 0;
  int n;
  while (scanf("%d",&n)==1){
    ll sum = 0;
    for (int m=1;m<=n;m++){
      if (!is_prime[m]) continue;
      int nn = n; while (nn){ sum+=nn/m; nn/=m; }
    }
    printf("%lld\n",sum);
  }

  return 0;
}