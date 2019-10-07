#include <bits/stdc++.h>
using namespace std;
const int maxn = 8 + 2;
char in_order[maxn],post_order[maxn];
void print(int l1,int r1,int l2,int r2){
  if (l1>r1) return;
  char root = post_order[r2];
  cout << root;
  int p = l1; while (in_order[p]!=root) p++;
  int cnt = p-l1;
  print(l1,p-1,l2,l2+cnt-1);
  print(p+1,r1,l2+cnt,r2-1);
}
int main(){
  scanf("%s%s",in_order,post_order);
  int l = strlen(in_order);
  print(0,l-1,0,l-1);
  return 0;
}