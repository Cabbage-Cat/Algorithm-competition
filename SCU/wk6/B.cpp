#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;int n;
  cin >> n; cin.ignore();
  while (n--){
    bool flag = true;
    getline(cin,s);
    if (s[0]>='0' && s[0]<='9') flag = false;
    for (int i=0;i<s.length();i++)
      if (!((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||s[i]=='_' )) flag = false;
    printf("%s",flag?"yes\n":"no\n");
  }
  return 0;
}