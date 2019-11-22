#include <iostream>
const int maxn = 40000+10;
using namespace std;
int f[maxn];
int main(){
  int n; cin >> n;
  if (n==1) { cout << "0"; }
  else{
    int res = (n-1)*(n-1); n--;
    for (int i=n;i>1;i--){
      f[i] = (n/i)*(n/i);
      for (int j=i*2;j<=n;j+=i) { f[i]-=f[j]; }
      res-=f[i];
    }
    cout << res+2;
  }
  
  return 0;
}