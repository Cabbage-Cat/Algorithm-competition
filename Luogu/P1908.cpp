#include <bits/stdc++.h>
using namespace std;
const int maxn = 5*100000 + 50;
int A[maxn],B[maxn];
typedef long long ll;
template <typename T>
inline T
read() {  //声明 template 类,要求提供输入的类型T,并以此类型定义内联函数 read()
  T sum = 0, fl = 1;  //将 sum,fl 和 ch 以输入的类型定义
  int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
  return sum * fl;
}
template <typename T>
inline void write(T x) {
  if (x < 0) {  // 判负 + 输出负号 + 变原数为正数
    x = -x;
    putchar('-');
  }
  if (x > 9) write(x / 10);  // 递归，将除最后一位外的其他部分放到递归中输出
  putchar(x % 10 + '0');  // 已经输出（递归）完 x 末位前的所有数字，输出末位
}
ll cnt = 0;

void merge_sort(int *A,int x,int y,int *B){
  if (y-x>1){
    int m = x+(y-x)/2;
    int p = x,q=m,i=x;
    merge_sort(A,x,m,B); merge_sort(A,m,y,B);
    while (p<m||q<y){
      if (q>=y || (p<m&&A[p]<=A[q])) B[i++] = A[p++];
      else { cnt+=(m-p); B[i++] = A[q++]; }
    }
    for (int i=x;i<y;i++) A[i] = B[i];
  }
}
int main(){
  int n = read<int>();
  for (int i=0;i<n;i++) A[i] = read<int>();
  merge_sort(A,0,n,B);
  printf("%lld",cnt);
  return 0;
}