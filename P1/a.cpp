#include <cstdio>
#include <iostream>
#include <vector>

const int maxn = 1000 + 10;
int fa[maxn];
void makeSet(int n){
  for (int i=0;i<n;i++) fa[i] =i;
}
int find(int x){
  if (x!=fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
void unionSet(int x,int y){
  x = find(x); y = find(y);
  if (x==y) return;
  fa[x] = y;
}
typedef std::pair<int,int> P;
P computers[maxn];
std::vector<int> next_coms[maxn];
int vis[maxn];
int main(){
  int n,d; std::cin >> n >> d;
  makeSet(n+1);
  for (int i=0;i<n;i++){
    scanf("%d%d",&computers[i].first,&computers[i].second);
  }
  for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++){
      int dx = computers[i].first - computers[j].first;
      int dy = computers[i].second - computers[j].second;
      if (dx*dx+dy*dy<=d){
        next_coms[i].push_back(j);
        next_coms[j].push_back(i);
      }
    }
  char cmd[5]; int a,b;
  while (scanf("%s",cmd)==1){
    if (cmd[0]=='S'){
      scanf("%d%d",&a,&b);a--;b--;
      printf("%s", find(a)==find(b)?"SUCCESS\n":"FAIL\n");
    }
    else{
      scanf("%d",&a);a--; vis[a] = 1;
      for (int i=0;i<next_coms[a].size();i++){
        int x = next_coms[a][i];
        if (vis[x])
          unionSet(a,x);
      }
      
      // for (int x : next_coms[a]){
      //   if (vis[x])
      //     unionSet(a,x);
      // } 
    } 
  }
  return 0;
}