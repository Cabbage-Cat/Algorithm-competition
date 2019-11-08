#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P; // P.first: pq P.second: id
bool operator<(const P &p1,const P &p2){
  if (p1.first!=p2.first) return p1.first < p2.first;
  else return p1.second > p2.second;
}

priority_queue<P,vector<P>,less<P>> pq[4];

int main(){
  int n;
  while (scanf("%d",&n)==1){
    for (int i=0;i<4;i++) while (!pq[i].empty()) pq[i].pop();
    char cmd[1000];
    int cnt = 0;
    for (int i=0;i<n;i++){
      scanf("%s",cmd);
      if (cmd[0]=='I'){
        int a,b;
        scanf("%d%d",&a,&b);
        pq[a].push(P(b,++cnt));
      }
      else{
        int a; scanf("%d",&a);
        if (pq[a].empty()) printf("EMPTY\n");
        else{
          P p; p = pq[a].top(); pq[a].pop();
          printf("%d\n",p.second);
        }
      }
    }
  }  
  return 0;
}