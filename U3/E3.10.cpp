#include <bits/stdc++.h>

using namespace std;

char s[100+5];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s",s);
        int res=0;
        int l = strlen(s);
        for (int i=1;i<l;i++)
        {
            for (int j=0;j<l;j++)
            {
                if (s[(i+j)%l] < s[(res+j)%l])
                {
                    res = i;
                    break;
                }
                else if (s[(i+j)%l] > s[(res+j)%l])
                    break;
            }
        }

        for (int i=0;i<l;i++)
            printf("%c",s[(res+i)%l]);
        printf("\n");
    }
    return 0;
}