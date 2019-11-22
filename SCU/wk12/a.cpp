#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000+10;
char d[maxn];
int f(int x){
  int mid = x/2;
  if (x%2) return x;
  for (int i=1;i<=mid;i++)
    if (d[i]!=d[x-i+1]) return x;
  return f(mid);
}
int main(){
  scanf("%s",d+1);
  int len = strlen(d+1);
  printf("%d",f(len));
  return 0;
}