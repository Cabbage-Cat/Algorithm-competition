#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=n;i>0;i--)
    {
        for (int j=0;j<n-i;j++)
            cout << ' ';
        for (int j=0;j<2*i-1;j++)
            cout << '#';
        cout << endl;
    }
}