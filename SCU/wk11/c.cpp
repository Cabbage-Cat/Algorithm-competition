#include <iostream>
using namespace std;
int n,m;
int main(){
  cin >> n >> m;
  int res = n/m;
  int r2 = n%m;
  int r1 = m-r2;
  for (int i=1;i<=r1;i++) cout << res << " ";
  for (int i=1;i<=r2;i++) cout << res+1 << " ";
  return 0;
}