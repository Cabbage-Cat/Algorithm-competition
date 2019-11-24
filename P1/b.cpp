#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 30000 + 10;
const int maxm = 500 + 10;

int fa[maxn];
void init_union(int n){
  for (int i=0;i<n;i++) fa[i] = i;
}

int find(int x){
  if (fa[x]==x) return fa[x];
  return fa[x] = find(fa[x]);
}
// int find(int x){
//   if (x!=fa[x]) fa[x] = find(fa[x]);
//   return fa[x];
// }
void union_union(int x,int y){
  x = find(x); y = find(y);
  if (x!=y) fa[x] = y;
}
int n,m,k;
int main(){
  while (~scanf("%d%d",&n,&m)&&n){
    init_union(n);
    int x1;  int x;
    for (int j=0;j<m;j++){
      scanf("%d",&k);
      for (int i=0;i<k;i++){
        if (i==0) scanf("%d",&x1);
        else{
          scanf("%d",&x);
          union_union(x,x1);
        }
      }
    }
    
    int cnt = 0;
    for (int i=0;i<n;i++) {find(i)==find(0)?cnt++:cnt;} 
    cout << cnt << endl;    
  }
}