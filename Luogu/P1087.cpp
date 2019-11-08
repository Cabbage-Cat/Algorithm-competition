#include <bits/stdc++.h>
using namespace std;
const int maxn = 1<<(10 + 1);
char s[maxn];
char color[5] = {'B','I','F'};
int post_order(int l,int r){
  if (l==r){
    if (s[l]=='0') return 0;
    else return 1;
  }
  int l_c = post_order(l,l-1+(r-l+1)/2);
  int r_c = post_order(r+1-(r-l+1)/2,r);
  cout << color[l_c] << color[r_c];
  int c = l_c + r_c;
  if (c==1) c = 2;
  else if (c==2) c = 1; 
  cout << color[c];
  return c;
}
int main(){
  int n; cin >> n;
  scanf("%s",s);
  n = 1<<n;
  int root = post_order(0,n-1);
  return 0;
}