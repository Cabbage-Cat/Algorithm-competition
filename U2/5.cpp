#include <bits/stdc++.h>

using namespace std;

int calc_f(int a,int b,int c,int *f)
{
    int res = a/b;
    a = a%b;
    memset(f,0,100);
    for (int i=0;i<c+1;i++)
    {
        a*=10;
        f[i] = a/b;
        a = a%b;
    }
    if (f[c] > 4)
        f[c-1]++;
    return res;
}

int main()
{
    int a,b,c,f[100+5];
    int kase = 0;
    while (scanf("%d %d %d",&a,&b,&c)==3 && a!=0)
    {
        double res = (double)a / (double) b;
        cout << "Case " << ++kase << ": " << calc_f(a,b,c,f)<<'.';
        for (int i=0;i<c;i++)
            cout << f[i];
        cout << endl;
    }
    return 0;
}