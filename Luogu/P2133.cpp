#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n;
const int maxn = 20000 + 10;
typedef pair<int,int> P;
typedef long long ll;
P d[maxn];
bool cmp(const P& p1,const P& p2){
  return min(p1.first,p2.second) < min(p2.first,p1.second);
}
int main(){
  cin >> t;
  while (t--){
    cin >> n;
    for (int i=1;i<=n;i++){
      scanf("%d%d",&d[i].first,&d[i].second);
    }
    sort(d+1,d+n+1,cmp);
    ll left=0,res=0;
    for (int i=1;i<=n;i++){
      left+=d[i].first;
      if (res<left) res=left+d[i].second;
      else res+=d[i].second;
    }
    
    cout << res << endl;
  }
  return 0;
}