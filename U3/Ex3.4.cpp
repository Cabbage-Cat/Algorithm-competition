#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[80+5];
    int t;
    cin >> t;

    while (t--)
    {
        scanf("%s",s);
        int flag=1;
        int l = strlen(s);
        for (int i=1;i<=l;i++)
        {
            if (l%i != 0)
                continue;
            flag = 1;
            for (int j=0;j<i;j++)
            {
                char c = s[j];
                for (int k=j;k<strlen(s);k+=i)
                {
                    if (s[k]!=c)
                    {
                        flag = 0;
                        break;
                        break;
                    }
                }
            }

            if (flag)
            {
                if (!t)
                    printf("%d\n",i);
                else
                    printf("%d\n\n",i);
                break;
            }
        }

        if (!flag)
        {
            if (!t)
                printf("%d\n",strlen(s));
            else
                printf("%d\n\n",strlen(s));
        }

    }
    return 0;
}