#include <bits/stdc++.h>
#define MAX_N 100000+5

using namespace std;

int x[MAX_N];

int sep(int x)
{
    int res=x;
    while (x>0)
    {
        res+=(x%10);
        x/=10;
    }
    return res;
}
int main()
{
    for (int i=1;i<MAX_N;i++)
    {
        int r = sep(i);
        if (r<MAX_N && !x[r])
            x[r] = i;
    }

    int t,tmp;
    cin >> t;
    for (int i=0;i<t;i++)
    {
        scanf("%d",&tmp);
        printf("%d\n",x[tmp]);
    }
    return 0;
}