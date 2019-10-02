#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;

char str[maxn];
set<int> vec[26];
int main(){
  scanf("%s",str); int le = strlen(str);
  for (int i=0;i<le;i++){
    int c = str[i] - 'a';
    vec[c].insert(i);
  }
  int q; cin >> q;
  
  int cmd,l,r; char b;
  for (int i=0;i<q;i++){
    scanf("%d %d ",&cmd,&l); l--;
    if (cmd==1){
      scanf("%c",&b); 
      int c = str[l] - 'a';
      vec[c].erase(l);
      vec[b-'a'].insert(l);
      str[l] = b;
    }else{
      scanf("%d",&r); r--;
      int res = 0;
      for (int i=0;i<26;i++){
        auto it = vec[i].lower_bound(l);
        if (it == vec[i].end() || *it > r) continue;
        else res++;
      }
      printf("%d\n",res);
    }
  }
  return 0;
}