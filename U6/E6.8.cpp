#include <iostream>
using namespace std;

bool solve(int& W){
  int w1,d1,w2,d2;
  bool b1 = true,b2 = true;
  scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
  if (!w1) b1 = solve(w1);
  if (!w2) b2 = solve(w2);
  W = w1 + w2;
  return b1 && b2 && (w1*d1 == w2*d2);
}
int main(){
  int t; cin >> t;
  while (t--){
    int w;
    printf("%s",solve(w)?"YES\n":"NO\n");
    if (t) printf("\n");
  }
  return 0;
}