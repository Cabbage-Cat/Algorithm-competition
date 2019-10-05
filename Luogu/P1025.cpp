#include <bits/stdc++.h>
using namespace std;

int dfs(int sum,int k,int last){
  if (sum<last) return 0;
  if (k==0) return 1;
  int res = 0;
  for (int i=last;i<=sum;i++){
    res+=dfs(sum-i,k-1,i);
  }
  return res;
}
int main(){
  int n,k; cin >> n >> k; k--;
  cout << dfs(n,k,1);
  return 0;
}
