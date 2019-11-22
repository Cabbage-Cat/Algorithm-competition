#include <cstdio>
int res = 0;
int nn,k;
void f(int n){
  if (n>k&&(n-k)%2==0){
    int x = (n-k)/2;
    f(x); f(x+k);
  }
  else res++;
}

int main(){
  scanf("%d%d",&nn,&k);
  f(nn);
  printf("%d",res);
  return 0;
}