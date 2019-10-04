#include <bits/stdc++.h>
using namespace std;

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
int main(){
  auto a = read<long long>();
  write<long long>(a);
  return 0;
}