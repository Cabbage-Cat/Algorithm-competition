#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int q,n;
char s1[maxn];
char s2[maxn];
void cache(int n){
  for (int i=0;i<n;i++){
    if (s1[i] == '1' || s1[i] == '2') s1[i] = '1';
    else s1[i] = '2';
    if (s2[i] == '1' || s2[i] == '2') s2[i] = '1';
    else s2[i] = '2';
  }
}
int main(){
  cin >> q;
  for (int i=0;i<q;i++){
    cin >> n;
    scanf("%s",s1);
    scanf("%s",s2);
    cache(n);
    int flag = s2[n-1]-'0';
    int down = 1;
    for (int i=n-1;i>=0;i--){
      if (s1[i]-'0' != s2[i]-'0') { down=1; break; }
      flag = s2[i]-'0';
      if (flag == 2){
        down = !down;
      }
    }
    if (!down) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}