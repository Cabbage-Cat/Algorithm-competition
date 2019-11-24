#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
char pre_order[10];
char in_order[10];
char post_order[10];
void build_pre(int l1,int r1,int l2,int r2){
  // 1: in_order  2: post_order
  if (l2>r2 || l1>r1) return;
  int root;  // root: r2
  for (int i=l1;i<=r1;i++) { if (in_order[i]==post_order[r2]) {root=i ;break;} }
  pre_order[root] = post_order[r2];
  putchar(pre_order[root]);
  build_pre(l1,root-1,l2,l2+root-l1-1);
  build_pre(root+1,r1,l2+root-l1,r2-1);
}
int main(){
  scanf("%s %s",in_order,post_order);
  //printf("%s\n%s",in_order,post_order);
  build_pre(0,strlen(in_order)-1,0,strlen(post_order)-1);
  return 0;
}