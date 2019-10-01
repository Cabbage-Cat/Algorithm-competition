#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 5;
int pre_order[maxn];
int n;
int m = 0;
int ans = 0;
int score(int l,int r){
  int res=0;
  if (l>r) return 1;
  if (l==r) return pre_order[l];
  for (int mid = l;mid<=r;mid++){
    res = score(l,mid-1) + score(mid+1,r) + pre_order[mid];
    if (ans < res) { ans = res; m = mid; }
  }
  return res;
}
int main(){
  cin >> n;
  cout << score(0,n-1);
  return 0;
}