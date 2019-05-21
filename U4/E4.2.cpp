#include <bits/stdc++.h>

using namespace std;

char s1[100],s2[100];
int l,chance;
int win,lose;

void guess(char c)
{
    int bad = 1;
    for (int i=0;i<strlen(s1);i++)
    {
        if (c == s1[i])
        {
            l--;
            s1[i] = ' ';
            bad = 0;
        }
    }
    if (bad)
        chance--;
    
    if (!chance)
        lose = 1;
    if (!l)
        win = 1;
}
int main()
{
    int t;
    while (~scanf("%d",&t) && t!=-1)
    {
        scanf("%s %s",s1,s2);
        l = strlen(s1);chance = 7;
        win = lose = 0;

        for (int i=0;i<strlen(s2);i++)
        {
            guess(s2[i]);
            if (win || lose)
                break;
        }

        printf("Round %d\n",t);
        if (lose)
            printf("You lose.\n");
        else if (win)
            printf("You win.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}