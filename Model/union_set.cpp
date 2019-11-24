#include <iostream>
using namespace std;
const int maxn = 1000 + 10;
int fa[maxn];

void makeSet(int n){
  for (int i=0;i<n;i++) fa[i] = i;
}

int find(int x){
  if (fa[x]!=x) fa[x] = find(fa[x]);
  return fa[x];
}

void unionSet(int x,int y){
  x=find(x); y = find(y);
  if (x!=y) fa[x] = y;
}

int main(){
  int n; cin >> n; makeSet(n);
  int x0=0;
  int x;
  for (int i=0;i<n;i++){
    cin >> x;
    unionSet(x,x0);
  }
  for (int i=0;i<n;i++){
    if (find(0)==find(i)) cout << i << " ";
  }
}