#include <bits/stdc++.h>

const int MAX_D = 1000000000+1;
using namespace std;
int s[100000+5];
int n,m;

bool jg(int d)
{
    int last=0;
    for (int i=1;i<m;i++)
    {
        int x = last+1;
        while (x<n && s[x]-s[last]<d)
            x++;
        
        if (x==n)
            return false;
        last = x;
    }
    return true;
}

int main()
{
    
    cin >> n >> m;
    for (int i=0;i<n;i++)
        scanf("%d",&s[i]);
    
    sort(s,s+n);
    
    int lb = 0,rb = MAX_D;
    while (rb-lb>1)
    {
        int mid = (rb+lb)/2;
        if (jg(mid))
            lb = mid;
        else
            rb = mid;
    }

    cout << lb << endl;
    return 0;
}