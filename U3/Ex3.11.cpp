#include <bits/stdc++.h>

using namespace std;

char s1[100+5];
char s2[100+5];
int main()
{
    while (~scanf("%s",s1))
    {
        scanf("%s",s2);
        if (strlen(s1)>strlen(s2))
        {
            char tmp[100+5];
            strcpy(tmp,s1);
            strcpy(s1,s2);
            strcpy(s2,tmp);
        }

        int res = 0;
        for (int j=0;j<=strlen(s2)-strlen(s1);j++)
        {
            int flag = 1;
            for (int i=0;i<strlen(s1);i++)
            {
                if (s1[i] == '2' && s2[i+j] == '2')
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                res = strlen(s2);
        }

        if (!res)
        {
            int p;
            for (p=1;p<=strlen(s1);p++)
            {
                int flag1 = 1,flag2=1;
                for (int i=p;i<strlen(s1);i++)
                {
                    if (s1[i]=='2' && s2[i-p]=='2')
                    {
                        flag1 = 0;
                        break;
                    }
                }

                for (int i=0;i<strlen(s1)-p;i++)
                {
                    if (s1[i]=='2' && s2[strlen(s2)-strlen(s1)+p+i]=='2')
                    {
                        flag2=0;
                        break;
                    }
                }

                if (flag1||flag2)
                {
                    res = strlen(s2) + p;
                    break;
                }
            }
        }

        if (!res)
            res = strlen(s1) + strlen(s2);
        printf("%d\n",res);
    }
    return 0;
}