#include <bits/stdc++.h>

#define MAX_N 1000+5

using namespace std;

int main()
{
    int n,kase=0,a[MAX_N],b[MAX_N];

    while (scanf("%d",&n)==1 && n)
    {
        printf("Game %d:\n",++kase);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        while(1)
        {
            for (int i=0;i<n;i++)
                scanf("%d",&b[i]);
            if(!b[0])
                break;
            
            int A=0,B=0;
            for (int i=0;i<n;i++)
                if (a[i]==b[i])
                    A++;
            
            for (int num=1;num<10;num++)
            {
                int x=0,y=0;
                for (int i=0;i<n;i++)
                {
                    if (a[i] == num)
                        x++;
                    if (b[i] == num)
                        y++;
                }
                B+=min(x,y);
            }

            printf("    (%d,%d)\n",A,B-A);
        }
    }
    return 0;
}