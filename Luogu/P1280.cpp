#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
bool cmp(const P &p1,const P &p2){
  return p1.first > p2.first;
}
const int maxn = 10000 + 10;
P d[maxn];
int t[maxn];
int f[maxn];
int main(){
  int n,k; cin >> n >> k;
  for (int i=0;i<k;i++) { scanf("%d%d",&d[i].first,&d[i].second); t[d[i].first]++; }
  sort(d,d+k,cmp);
  // for (int i=0;i<k;i++) cout << d[i].first << " " << d[i].second << endl;
  int pos = 0;
  for (int i=n;i>0;i--){
    if (!t[i]) f[i] = f[i+1] + 1;
    else{
      for (;d[pos].first>=i;pos++){
        if (d[pos].first == i)
          f[i] = max(f[i],f[i+d[pos].second]);
      }
    }
  }
  cout << f[1];
  return 0;
}