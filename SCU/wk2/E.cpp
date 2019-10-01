#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  if (a>b) swap(a,b); if (a>c) swap(a,c);
  if (b>c) swap(b,c);
  int i = c+1-a-b;
  printf("%d",i>0?i:0);
  return 0;
}