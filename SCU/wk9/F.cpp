#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
int g[maxn][maxn];
int v[maxn][maxn];
map<string,int> id_cache;
int getid(string name){
  return id_cache.count(name)?id_cache[name]:(id_cache[name] = id_cache.size());
}

int main(){
  int n;
  while (scanf("%d",&n)==1 && n){
    memset(g,0,sizeof(g));
    memset(v,0,sizeof(v));
    id_cache.clear();
    string x,y; 
    for (int i=0;i<n;i++){
      cin >> x >> y;
      g[getid(x)][getid(y)] = 1;
    }
    int flag = 1;
    set<int> s; for (int i=0;i<id_cache.size();i++) s.insert(i);
    for (int i=0;i<id_cache.size();i++)
      for (int j=0;j<id_cache.size();j++)
        if (g[i][j]) if (s.count(j)) s.erase(j);
    printf("%s\n", s.size()==1?"Yes":"No");
  }
  return 0;
}