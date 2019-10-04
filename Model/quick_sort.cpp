#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int d[maxn];
void quick_sort(int A[],int start,int end){
  if (start > end) return;
  int mid = A[(start+end)/2];
  int l = start,r = end;
  while (l<=r){
    while (A[l]<mid) l++;
    while (A[r]>mid) r--;
    if (l<=r) { swap(A[l],A[r]); l++; r--; }
  }
  if (start < r) quick_sort(A,start,r);
  if (end > l) quick_sort(A,l,end);
}
int main(){
  int n; cin >> n;
  for (int i=0;i<n;i++) scanf("%d",&d[i]);
  sort(d,d+n);
  for (int i=0;i<n-1;i++) printf("%d ",d[i]);
  printf("%d\n",d[n-1]);
  return 0;
}

