#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; cin.ignore();
  while (n--){
    int res = 0;
    char c;
    while ((c=getchar())!='\n') if (isdigit(c)) res++;
    cout << res << endl;
  }
  return 0;
}