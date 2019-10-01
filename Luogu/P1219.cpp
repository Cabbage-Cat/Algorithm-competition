#include <bits/stdc++.h>
using namespace std;
const int maxn = 13 + 2;
int vis[3][2*maxn];
int C[maxn];
int n;
int total = 0;
void search(int cur){
  if (cur==n) { total += 1; if (total < 4) { for (int i=0;i<n;i++) printf("%d ",C[i]); 
  printf("\n"); }  return; }
  else {
    for (int i=0;i<n;i++){
      if (!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){
        vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
        C[cur] = i+1;
        search(cur+1);
        vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
      }
    }
  }
}
int main(){
  cin >> n;
  search(0);
  cout << total;
  return 0;
}