#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
const int maxn = 15 + 5;
P points[maxn];
double d[maxn][maxn];
int n;
double dis(P& p1,P& p2){
  double x1 = p1.first,y1 = p1.second;
  double x2 = p2.first,y2 = p2.second;
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
  cin >> n;
  int v[maxn];
  for (int i=0;i<n;i++){
    scanf("%lf%lf",&points[i].first,&points[i].second);
    v[i] = i;
  }
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      if (d[i][j]!=0) continue;
      d[i][j] = dis(points[i],points[j]);
      d[j][i] = d[i][j];
    }
  double res = 999999999;
  do{
    double ans = 0;
    int bgn_idx = v[0];
    double bgn_x = points[bgn_idx].first,bgn_y = points[bgn_idx].second;
    ans = sqrt(bgn_x*bgn_x + bgn_y*bgn_y);
    if (ans>res){
      sort(v+1,v+n,greater<int>()); continue;
    }
    for (int i=1;i<n;i++){
      ans+=d[v[i-1]][v[i]];
      if (ans>res){
        sort(v+i,v+n,greater<int>()); break;
      }
    }
    if (ans<res) res = ans;
  }while(next_permutation(v,v+n));
  printf("%.2lf",res);
  return 0;
}