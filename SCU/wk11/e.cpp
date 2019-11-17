#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
const char str[18] = {"0123456789ABCDEF"};
int main(){
  ll a,b;
  string n;
  cin >> a >> n >> b;
  int l = n.length() -1;
  ll res=0;
  for (int i=0;i<=l;i++){
    char c = toupper(n[i]);
    for (int j=0;j<16;j++){
      if (c==str[j]) { res=res*a+j; break;}
    }
  }
  stack<char> ans;
  while (res){
    ans.push(str[res%b]);
    res/=b;
  }
  while (!ans.empty()) { putchar(ans.top()); ans.pop(); }
  return 0;
}