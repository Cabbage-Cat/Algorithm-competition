#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int A[maxn];
int a,b;
bool check(int x){
  int p=0,total=0;
  for (int i=0;i<a;i++)
    if (A[i]-A[p]>=x) { total++; p=i; }
  return total+1 >= b;
}
int main(){
  cin >> a >> b;
  for (int i=0;i<a;i++) scanf("%d",A+i);
  sort(A,A+a);
  int L = 0,R = A[a-1] - 0;
  while (L<=R){
    int mid = L + ((R-L)>>1);
    if (check(mid)) L = mid+1;
    else R = mid-1;
  }
  cout << R;
  return 0;
}