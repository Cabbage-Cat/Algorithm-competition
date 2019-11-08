#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int l[maxn],r[maxn];
int l_cnt=0,r_cnt=0;
int main(){
  int n; cin >> n;
  char cmd[20]; int x,res;
  while (n--){
    scanf("%s%d",cmd,&x); 
    if (cmd[0]=='L') l[x]=++l_cnt;
    else if (cmd[0]=='R') r[x]=++r_cnt;
    else{
      if (l[x]) res = min(l_cnt-l[x],r_cnt+l[x]-1);
      else if (r[x]) res = min(r_cnt-r[x],l_cnt+r[x]-1);
      cout << res << endl;
    }
  }
  return 0;
}