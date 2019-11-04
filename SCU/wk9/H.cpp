#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int d[maxn];
int main(){
  int n,q;
  int t = 0;
  while (scanf("%d%d",&n,&q)==2 && n && q){
    printf("CASE# %d:\n",++t);
    for (int i=0;i<n;i++) scanf("%d",&d[i]);
    sort(d,d+n);
    int x;
    for (int i=0;i<q;i++){
      cin >> x;
      int start = 0,end = n;
      int res = -1;
      while (start<end){
        int mid = (start + end) /2;
        if (d[mid] == x) { res = mid; break; }
        if (d[mid] > x) end = mid;
        if (d[mid] < x) start = mid+1;
      }
      res++;
      printf("%d ",x);
      if (!res) printf("not found\n");
      else printf("found at %d\n",res);
    }
  }
  return 0;
}