#include <iostream>
using namespace std;
int h,a,b;
int main(){
  cin >> h >> a >> b;
  int res = h-a;
  if (res<=0) { cout << "YES " << 1; return 0;}
  if (b>=a) { cout << "NO"; return 0; }
  cout << "YES " << res/(a-b) + 1;
  return 0;
}