#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int main(){
  int t;cin >> t;
  ll a=0,b=0;
  for (int i=0;i<t;i++){
    a=0;b=0;
    string s1,s2;
    cin >> s1; cin >> s2;
    int l1=s1.length(),l2=s2.length();
    for (int i=0;i<19 && i<l1;i++){
      a = a*10 + s1[i]-'0';
    }
    for (int i=0;i<19 && i<l2;i++){
      b = b*10 + s2[i]-'0';
    }
    a%=mod; b%=mod;
    cout << (a*b)%mod <<endl;
  }
  return 0;
}