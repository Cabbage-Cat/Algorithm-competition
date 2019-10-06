#include <bits/stdc++.h>
using namespace std;
const int maxn = 255+10;
char s[maxn];
int main(){
  scanf("%s",s);
  stack<char> st;
  int flag = 1;
  for(int i=0;i<strlen(s);i++){
    if (s[i]=='(') st.push(s[i]);
    else if (s[i]==')'){
      if (st.empty() || st.top()!='(') { flag = 0; break; }
      st.pop();
    }
  }
  printf("%s",flag&&st.empty()?"YES":"NO");
  return 0;
}