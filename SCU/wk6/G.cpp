#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
char s[maxn];
int main(){
  int n; cin >> n;
  while (n--){
    scanf("%s",s);
    char c = s[0]; int cnt = 0; int l = strlen(s)+1;
    for (int i=0;i<l;i++){
      if (s[i]==c) cnt++;
      else {
        if (cnt > 1) cout << cnt;
        cout << c;
        c=s[i]; cnt = 1;
      }
    }
    cout << endl;
  }
}