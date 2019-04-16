#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    int kase = 0;
    while (scanf("%d %d",&n,&m)==2 && n!=0)
    {
        double _sum = 0;
        for (int i=n;i<=m;i++)
            _sum += 1.0/((long long)i*i);
            
        cout << "Case "<< ++kase << ": " << _sum << endl;

    }

    return 0;
}