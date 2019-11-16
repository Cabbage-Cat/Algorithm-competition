#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 30000000;
long long n;
int main(){
  while (scanf("%lld",&n)==1 && n!=EOF){
    for (long long i=1;i<=sqrt(n);i++)
      cout << i*i<<" ";
    cout << endl;
  }
  return 0;
}