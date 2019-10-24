#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 2;
int d[maxn];
int is_prime[40+2];
int main(){
  for (int i=2;i<=40;i++) is_prime[i] = 1;
  for (int i=2;i<=40;i++){
    if (is_prime[i]){
      for (int j = i+i;j<41;j+=i) is_prime[j] = 0;
    }
  }
  int t=0;
  int n; 
  while (scanf("%d",&n)==1){
    cout << "Case " << ++t << ":"<< endl;
    for (int i=0;i<n;i++) d[i] = i+1;
    do{
      int flag = 1;
      if (!is_prime[d[n-1]+1]) flag = 0;
      if (flag)
      for (int i=1;i<n;i++) if (!is_prime[d[i]+d[i-1]]) { flag = 0; sort(d+i+1,d+n,greater<int>()); break; }
      if (flag){
        for (int i=0;i<n-1;i++) cout << d[i] << " "; cout << d[n-1];
        cout << endl;
      }
    }while (next_permutation(d+1,d+n));
    cout << endl;
  }
  return 0;
}