#include <cstdio>
#include <iostream>
using namespace std;
ll n,m;
const int maxn = 50000 + 10;
ll res[maxn];
// int main(){
//   int min_num = 1;
//   cin >> n >> m; int n_cpy=n;
//   int l=1,r=n;
//   while (l<=r){
//     int x = r-l+1;
//     if ((n-1)*(n-2)/2 >= m){
//       res[l] = min_num++;
//       l+=1; n--;
//     }
//     else{
//       res[r] = min_num++; r--;
//       m-=(r-l+1); n--;
//     }
//   }
//   for (int i=1;i<=n_cpy;i++) cout << res[i] << " ";
//   return 0;
// }
typedef long long ll;
int main(){
  cin >> n >> m;
  ll l=1,r=n;
  for (int i=1;i<=n;i++){
    ll t = (n-i)*(n-i-1)/2;
    if (t>=m) res[l++] = i;
    else { res[r--]=i; m-=(r-l+1); }
  }
  for (int i=1;i<=n;i++) cout << res[i] << " ";
  return 0;
}