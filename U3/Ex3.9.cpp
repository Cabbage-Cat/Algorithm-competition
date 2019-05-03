#include <bits/stdc++.h>

using namespace std;

char s[10000000];
char t[10000000];

int main()
{
    while (scanf("%s%s",s,t) == 2)
    {
        int s_l = strlen(s);
        int t_l = strlen(t);
        char c;
        int flag = 1;
        int pos = -1;
        for (int i=0;i<s_l;i++)
        {
            c = s[i];
            for (;++pos<t_l;)
                if (c == t[pos])
                    break;
            if (pos == t_l)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
        
    }
    return 0;
}