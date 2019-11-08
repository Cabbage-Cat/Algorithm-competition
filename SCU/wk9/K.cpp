#include <bits/stdc++.h>
using namespace std;
set<long long> s;
priority_queue<long long,vector<long long>,greater<long long>> pq;
int d[3] = {2,3,5};
int main(){
  pq.push(1); s.insert(1);
  for (int i=1;;i++){
    long long x = pq.top(); pq.pop();
    if (i==1500) { cout << x; break; }
    for (int i=0;i<3;i++){
      long long x2 = x*d[i];
      if (!s.count(x2)){
        s.insert(x2); pq.push(x2);
      }
    }
  }
  
  return 0;
}