#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char d[10];
int main(){
  scanf("%s",d);
  int l = strlen(d);
  printf("%s\n",d);
  while (next_permutation(d,d+l)) printf("%s\n",d);
  return 0;
}