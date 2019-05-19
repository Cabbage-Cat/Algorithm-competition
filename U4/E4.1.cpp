#include <bits/stdc++.h>

using namespace std;

char s1[100+2];
char s2[100+2];
int cnt1[26];
int cnt2[26];

int main()
{
    while (scanf("%s",s1)==1 && s1[0]!=0)
    {
        scanf("%s",s2);
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));

        for (int i=0;i<strlen(s1);i++)
        {
            char c = s1[i];
            cnt1[c-'A']++;
            c = s2[i];
            cnt2[c-'A']++;
        }

        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        int flag = 1;
        for (int i=0;i<26;i++)
        {
            if (cnt1[i] != cnt2[i])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            printf("YES\n");
        else
            printf("NO\n");

        
    }
    return 0;
}