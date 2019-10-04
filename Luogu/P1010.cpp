#include <bits/stdc++.h>
using namespace std;
int n;
string dfs(int x,int i=0,string s=string("")){
  if (x==0) return string("0");
  do{
    if (x&1){
      s = (i==1?"2":"2("+dfs(i)+")")+(s==""?"":"+")+s;
    }
  }while(i++,x>>=1);
  return s;
} 
int main(){
  cin >> n;
  cout << dfs(n);
}