#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  vector<int> x(m);
  for (int i=0;i<m;i++) { cin >> x[i]; x[i]--; }
  vector<int> res(n);
  vector<vector<int>> edge(n);
  vector<int> cnt(n);
  for (int i=0;i<m-1;i++) res[0] += abs(x[i]-x[i+1]);
  for (int i=0;i<m-1;i++){
    int l = x[i],r = x[i+1];
    if (l!=r){
      edge[l].push_back(r);
      edge[r].push_back(l);
      if (l>r) swap(l,r);
      if (r-l<2) continue;
      cnt[l+1]++;
      cnt[r]--;
    }
  }
  for (int i=1;i<n;i++)
    cnt[i] += cnt[i-1];
  for (int i=1;i<n;i++){
    res[i] = res[0] - cnt[i];
    for (auto c : edge[i]){
      res[i] -= abs(c-i);
      res[i] += c + (c<i);
    }
  }
  for (int i=0;i<n;i++) cout << res[i] << " ";
  return 0;
}