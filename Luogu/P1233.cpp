#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 10;
typedef pair<int,int> P;
P d[maxn];
int a[maxn];
bool cmp(const P& p1,const P& p2){
  if (p1.first!=p2.first) return p1.first > p2.first;
  else return p1.second > p2.second;
}
int main(){
  int n; cin >> n;
  for (int i=1;i<=n;i++)
    scanf("%d%d",&d[i].first,&d[i].second);
  sort(d+1,d+n+1,cmp);
  int res = 0; 
  for (int i=1;i<=n;i++){
    for (int j=0;j<i;j++) if (d[j].second<d[i].second) a[i] = max(a[i],a[j]+1);
  }
  for (int i=1;i<=n;i++) res = max(res,a[i]);
  cout << res;
  return 0;
}