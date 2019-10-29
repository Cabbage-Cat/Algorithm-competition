#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;
  cin.ignore();
  string line;
  while (t--){
    getline(cin,line);
    stringstream ss(line);
    int i=0;
    int pos;
    while ((pos=line.find(' ',i))!=string::npos){
      reverse(line.begin()+i,line.begin()+pos);
      i=pos+1;
    }
    reverse(line.begin()+i,line.end());
    cout << line << endl;
  }
  return 0;
}