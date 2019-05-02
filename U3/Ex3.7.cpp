#include <bits/stdc++.h>

using namespace std;

char s[50+2][1000+2];
char res[1000+2];
int rres[4];
char con_s[5] = {'A','C','G','T'};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for(int i=0;i<4;i++)
            rres[i] = 0;

        int m,n;
        cin >> m >> n;
        
        for (int i=0;i<m;i++)
            scanf("%s",s[i]);
        
        for (int i=0;i<n;i++)
        {
            for(int i=0;i<4;i++)
                rres[i] = 0;
            for (int j=0;j<m;j++)
            {
                char c = s[j][i];
                switch (c)
                {
                    case 'A':
                    {
                        rres[0]++;
                        break;
                    }
                    case 'C':
                    {
                        rres[1]++;
                        break;
                    }
                    case 'G':
                    {
                        rres[2]++;
                        break;
                    }
                    case 'T':
                    {
                        rres[3]++;
                        break;
                    }
                }
            }
            int count = 0;
            for (int i=0;i<4;i++)
                if (rres[i] > rres[count])
                    count = i;
            res[i] = con_s[count];
        }
        res[n]=0;

        int d=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (res[i] != s[j][i])
                    d++;
        printf("%s\n%d\n",res,d);
    }
    return 0;
}