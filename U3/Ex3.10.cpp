#include <bits/stdc++.h>
using namespace std;
set<int> s;
int l_count[10000+5];
int l[10000+5];

int main()
{
    int length,width;
    while (scanf("%d%d",&length,&width)==2)
    {
        s.insert(length);s.insert(width);
        l_count[length]++;l_count[width]++;

        if (length!=width)
            l[length]++;
        l[width]++;

        for (int i=0;i<5;i++)
        {
            scanf("%d%d",&length,&width);
            l_count[length]++;l_count[width]++;
            s.insert(length);s.insert(width);
            if (length!=width)
                l[length]++;
            l[width]++;
        }

        
        if (s.size()==1)
        {
            printf("POSSIBLE\n");continue;
        }

        if (s.size()==2)
        {
            int flag = 0;
            int a,b;set<int>::iterator it = s.begin();
            a = *it;it++;
            b = *it;
            if (((l_count[a]==8 && l_count[b]==4) || (l_count[a]==4 && l_count[b]==8)) && ((l[a]==6 && l[b]==4) || (l[a]==4 && l[b]==6)))
                flag = 1;
            if (flag)
            {
                printf("POSSIBLE\n");continue;
            }
            printf("IMPOSSIBLE\n");
        }

        if (s.size()==3)
        {
            int flag = 1;
            int a;set<int>::iterator it;
            for (it=s.begin();it!=s.end();it++)
            {
                a = *it;

                if (l_count[a]!=4)
                {
                    flag = 0;break;
                }

                if (l[a]!=4)
                {
                    flag = 0;break;
                }
            }
            if (flag)
            {
                printf("POSSIBLE\n");continue;
            }
            printf("IMPOSSIBLE\n");
        }

        if (s.size()>3)
            printf("IMPOSSIBLE\n");
        s.clear();
        memset(l,0,sizeof(l));memset(l_count,0,sizeof(l_count));
    }
        
    return 0;
}