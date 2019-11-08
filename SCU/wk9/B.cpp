#include <bits/stdc++.h>
using namespace std;

int main(){
  int t,n,x; cin >> t;
  while (t--){
    scanf("%d",&n);
    deque<int> dq;
    char cmd[1000];
    int left_flag;
    scanf("%s",cmd);
    if (cmd[2]=='F') left_flag = 1; else left_flag = 0;
    for (int i=0;i<n;i++){
      scanf("%s",cmd);
      if (cmd[0] == 'I'){
        scanf("%d",&x);
        dq.push_back(x);
      }
      else{
        if (dq.empty()) puts("None");
        else{
          if (left_flag) { printf("%d\n",dq.front()); dq.pop_front(); }
          else { printf("%d\n",dq.back()); dq.pop_back(); }
        }
      }
    }
  }
  return 0;
}