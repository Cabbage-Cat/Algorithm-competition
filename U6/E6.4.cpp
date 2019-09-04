#include <bits/stdc++.h>
const int maxn = 100000 + 5;
char str[maxn];
int _next[maxn];
int cur,last=0;
int main(){
    while (scanf("%s",str+1)!=EOF){
        _next[0] = 0;
        cur=0,last=0;
        int l = strlen(str+1);
        for (int i=1;i<=l;i++){
            char c = str[i];
            if (c == '[') cur = 0;
            else if (c == ']') cur = last;
            else{
                _next[i] = _next[cur];
                _next[cur] = i;
                if (cur==last) last=i;
                cur = i;
            }
        }
        for (int i=_next[0];i!=0;i=_next[i])
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}