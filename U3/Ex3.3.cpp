#include <bits/stdc++.h>

using namespace std;

int num[10];

void sep_num(int x)
{
    while (x)
    {
        num[x%10]++;
        x/=10;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(num,0,sizeof(num));
        int x;
        cin >> x;
        x++;
        while (x--)
            sep_num(x);
        
        for (int i=0;i<9;i++)
            printf("%d ",num[i]);
        printf("%d\n",num[9]);
        // putchar('\n');
    }
    return 0;
}