#include <bits/stdc++.h>
using namespace std;

int digit[3000+2];
int s_res[3000+2];
set<int> s;
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b) == 2 && b)
    {
        memset(digit,0,sizeof(digit));
        memset(s_res,0,sizeof(s_res));
        s.clear();
        digit[0] = a/b;
        int res = a;
        int count = 0;
        int flag = 1;

        while ((res-=b*digit[count++]) && !s.count(res))
        {
            s.insert(res);
            s_res[count] = res;
            res*=10;
            digit[count] = res/b;
        }

        int l=0;
        while (s_res[++l]!=res);

        printf("%d/%d = %d.",a,b,digit[0]);
        for (int i=1;i<l;i++)
            printf("%d",digit[i]);
        printf("(");
        if (count==l)   count++;
        if (count-l>50)
        {
            for (int i=l;i<l+50;i++)
                printf("%d",digit[i]);
            printf("...");
        }
        else
            for (int i=l;i<count;i++)
                printf("%d",digit[i]);
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n",count-l);
    }
    return 0;
}