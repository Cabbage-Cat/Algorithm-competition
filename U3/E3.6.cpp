#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[] = "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c;
    while ((c=getchar())!=EOF)
    {
        int i;
        for (i=1;s[i] && s[i]!=c;i++);
        printf("%c",s[i]?s[i-1]:c);
    }
    
    return 0;
}