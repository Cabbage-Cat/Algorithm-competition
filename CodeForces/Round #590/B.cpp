#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

deque<int> dq;
map<int,int> screen;
int n,k,x;
void input(int x){
  if (screen[x]) return;
  if (dq.size()==k){
    screen[dq.back()] = 0;
    dq.pop_back();
  }
  dq.push_front(x);
  screen[x] = 1;
}
int main(){
  cin >> n >> k;
  for (int i=0;i<n;i++){
    scanf("%d",&x);
    input(x);
  }
  cout << dq.size() << endl;;
  for (int i=0;i<dq.size();i++)
    printf("%d ",dq[i]);
  return 0;
}