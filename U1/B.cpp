#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

string s[10000+5];


int main()
{
    ios::sync_with_stdio(false);
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        cin >> n;
        for (int i=0;i<n;i++)
            cin >> s[i];
        sort(s,s+n);

        for (int i=0;i<n-1;i++)
        {
            if (s[i].size() < s[i+1].size())
            {
                int j;
                for (j=0;j<s[i].size();j++)
                {
                    if (s[i][j]!=s[i+1][j])
                        break;
                }

                if (j==s[i].size())
                {
                    flag=1;
                    break;
                }
            }
        }
        
        
        if (flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    
    

    return 0;
}