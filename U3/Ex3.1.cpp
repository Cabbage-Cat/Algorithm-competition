#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    char s[85];
    cin >> t;
    while (t--)
    {
        scanf("%s",s);
        int power = 0;
        char c;
        int res=0;
        int l = strlen(s);
        for (int i=0;i<l;i++)
        {
            c = s[i];
            if (c=='X')
            {
                power = 0;
                continue;
            }
            res+=(++power);
        }
        printf("%d\n",res);
    }
    return 0;
}