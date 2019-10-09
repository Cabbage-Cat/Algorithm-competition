#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 6;
char s[maxn];
int main(){
  while (~scanf("%s",s)){
    int dot_sum = 0;
    int dot_idx[4]; dot_idx[3] = strlen(s);
    for (int i=0;i<strlen(s);i++) if (s[i]=='.'){ if (dot_sum<3) dot_idx[dot_sum]=i; dot_sum++;} 
    if (dot_sum!=3) { printf("NO\n"); continue; }
    if (dot_idx[0]==0||dot_idx[1]-dot_idx[0]==1||dot_idx[2]-dot_idx[1]==1) { printf("NO\n"); continue; } 
    int p=-1,flag=1;
    for (int i=0;i<4;i++){
      int sum=0; flag = 1;
      while(++p<dot_idx[i]){
        if (isdigit(s[p])) sum = sum*10 + (s[p]-'0');
        else { flag = 0; break;}
      }
      if (flag&&(sum<0||sum>255)) flag = 0; p++;
      if (!flag) { printf("NO\n"); break; }
    }
    if (flag) printf("YES\n");
  }
  
  return 0;
}