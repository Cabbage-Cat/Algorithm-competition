#include <cstdio>
int k,y;
bool f(int k,int y){
  if (k==y) return true;
  if (k>y) return false;
  return f(2*k+1,y) || f(3*k+1,y);
}
int main(){
  scanf("%d,%d",&k,&y);
  printf("%s",f(k,y)?"YES":"NO");
  return 0;
}