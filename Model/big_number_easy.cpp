#include <cstdio>
#include <iostream> 
#include <cstring>
using namespace std;
const int maxn = 5000;
int a[maxn],b[maxn],c[maxn];
void clear(int a[]){
  for (int i=0;i<maxn;i++) a[i] = 0;
}
void read(int a[]){
  clear(a);
  static char s[maxn];
  scanf("%s",s);
  int len = strlen(s);
  for (int i=0;i<len;i++) a[i] = s[len-1-i]-'0';
}
void print(int a[]){
  int pos = maxn - 1;
  for (;a[pos]==0&&pos>0;pos--);
  for (int i=pos;i>=0;i--) printf("%d",a[i]);
}
void add(int a[],int b[],int c[]){
  memcpy(c,a,sizeof(int)*maxn);
  for (int i=0;i<maxn-1;i++){
    c[i] += b[i];
    c[i+1] += c[i]/10;
    c[i]%=10;
  }
}
bool sub(int a[],int b[],int c[]){
  bool a_bigger_b = 1;
  int a_pos=maxn-1;
  int b_pos=maxn-1;
  for (;a[a_pos]==0&&a_pos>0;a_pos--);
  for (;b[b_pos]==0&&b_pos>0;b_pos--);
  if (a_pos==b_pos){
    for (int i=a_pos;i>-1;i--) if (b[i]>a[i]) { a_bigger_b = 0; break; }
  }
  else if (a_pos<b_pos) a_bigger_b = 0;
  if (!a_bigger_b) { int *t=a; a=b; b=t; swap(a_pos,b_pos); }
  memcpy(c,a,sizeof(int)*maxn);
  for (int i=0;i<=a_pos;i++){
    c[i]-=b[i];
    if (c[i]<0) { c[i]+=10; c[i+1]--; }
  }
  return a_bigger_b;
}
void mul_short(int a[],int b,int c[]){
  clear(c);
  for (int i=0;i<maxn-1;i++){
    c[i] += a[i]*b;
    if (c[i]>=10){
      c[i+1] += c[i] /10;
      c[i]%=10;
    }
  }
}
void mul(int a[],int b[],int c[]){
  clear(c);
  for (int i=0;i<maxn-1;i++){
    for (int j=0;j<=i;j++)
      c[i] += a[j]*b[i-j];
    if (c[i]>=10){
      c[i+1] += c[i]/10;
      c[i]%=10;
    }
  }
}
int main(){
  read(a); read(b); clear(c); mul(a,b,c);
  //sub(a,b,c)?:putchar('-'); 
  print(c);
  return 0;
}