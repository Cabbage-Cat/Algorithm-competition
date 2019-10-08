#include <bits/stdc++.h>
#include <regex>
using namespace std;
string s;
int main(){
  
  regex repPatten("^[0-9]{1,3}-[0-9]{1,3}-[0-9]{1,3}-[0-9]{1,3}");
  while (cin >> s){
    for (int i=0;i<s.length();i++) if (s[i]=='.') s[i] = '-';
    bool b = regex_match(s,repPatten);
    if (!b) { cout << "NO\n"; continue; }
    stringstream ss(s);
    string sub_str;
    int flag = 1;
    while (getline(ss,sub_str,'-')){
      int s_sum = 0;
      for (int i=0;i<sub_str.length();i++)
        s_sum = s_sum*10 + (sub_str[i]-'0');
      if (s_sum<0||s_sum>255) { flag = 0; break;};
    }
    printf("%s", flag?"YES\n":"NO\n");
  }
  return 0;
}