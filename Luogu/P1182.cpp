#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int A[maxn];
int n,m;
int maxa = -99999999; int suma = 0;
bool check(int x){
  int a_sum = 0,cnt = 1;
  for (int i=0;i<n;i++){
    if (a_sum + A[i] <= x) a_sum+=A[i];
    else{
      a_sum = A[i]; cnt++;
    }
  }
  return cnt <= m;
}
int main(){
  cin >> n >> m;
  for (int i=0;i<n;i++){
    scanf("%d",&A[i]);if (A[i] > maxa) maxa = A[i];
    suma+=A[i];
  }
  int L=maxa,R=suma;
  while (L<=R){
    int mid = L + ((R-L)>>1);
    if (check(mid)) R = mid-1;
    else L = mid+1;
  }
  cout << L;
  return 0;
}