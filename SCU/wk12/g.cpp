#include <cstdio>
#include <iostream>
using namespace std;
string f(int x,int i=0,string s=""){
  if (x==0) return "0";
  do{
    if (x&1) s= (i==1?"2":"2("+f(i)+")") + (s==""?"":"+") +s;
  } while (++i,x>>=1);
  return s;
}

int main(){
  int n; cin >> n;
  cout << f(n);
  return 0;
}