#include <bits/stdc++.h>

using namespace std;

int _people(int a,int b,int c)
{
    int res=0;
    for (int i=10;i<100;i++)
    {
        if (i%3==a && i%5==b && i%7==c)
        {
            res = i;
            break;
        }
    }

    return res;
}
int main()
{
    int a,b,c;
    int t = 0;
    while (scanf("%d %d %d",&a,&b,&c)==3)
    {
        int r = _people(a,b,c);
        if (!r)
            cout << "Case " << ++t << ": "<<"No answer" << endl;
        else
            cout << "Case " << ++t << ": "<<r << endl;
    }
    return 0;
}