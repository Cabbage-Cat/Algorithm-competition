#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int s1[maxn],s2[maxn];
int main(){
  int n;
  while (scanf("%d",&n)&&n){
    for (int i=0;i<n;i++) scanf("%d",s1+i);
    int step=-1,flag = 0;
    while (!flag){
      flag = 1;
      for (int i=0;i<n;i++) { 
        s2[i] = 2*((s1[i]/2+s1[(i-1+n)%n]/2+1)/2);
        if (s2[i]!=s1[i]) flag = 0;
      }
      for (int i=0;i<n;i++) s1[i] = s2[i];
      step++;
    }
    cout << step << " "<< s1[0] << endl;
  }
  return 0;
}