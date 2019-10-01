#include <bits/stdc++.h>

using namespace std;
const int maxn = 7+2;
int cto[7];
char text[1<<maxn];
int n;
int main(){
  int x,m,t=0;
  while(scanf("%d",&n)==1 && n){
    char s1[maxn];
    for(int i=0;i<n;i++){
      scanf("%s",s1);
      sscanf(s1+1,"%d",&x);
      cto[i]=x-1;
    }
    scanf("%s",text);
    scanf("%d",&m);
    printf("S-Tree #%d:\n",++t);
    for(int i=0;i<m;i++){
      int num=0;
      scanf("%s",s1);
      for(int j=0;j<n;j++){
        num=num*2+(s1[cto[j]]-'0');
      }
      printf("%c",text[num]);
    }
    printf("\n\n");
  }
  return 0;
}
