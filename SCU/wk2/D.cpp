#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int num[maxn];
bool cmp(int &i1,int &i2){
  return abs(i1) > abs(i2);
}
int main(){
  int n;
  while (scanf("%d",&n)==1 && n){
    for (int i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n,cmp);
    for (int i=0;i<n-1;i++) printf("%d ",num[i]); printf("%d\n",num[n-1]);
  }
  return 0;
}