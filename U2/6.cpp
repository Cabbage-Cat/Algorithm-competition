#include <bits/stdc++.h>

using namespace std;

bool used[9+5];

int num[3];

void sep_x_use(int x,int *num)
{
    for (int i=0;i<3;i++)
    {
        num[2-i] = x%10;
        x/=10;
    }
    for (int i=0;i<3;i++)
        used[num[i]] = true;
}

bool jg(bool *x)
{
    for (int i=1;i<10;i++)
        if (!used[i])
            return false;
    return true;
}

int main()
{
    for (int i=123;i<=329;i++)
    {
        memset(used,0,14);
        int def = 2*i,ghi = 3*i;
        sep_x_use(i,num);
        sep_x_use(def,num);
        sep_x_use(ghi,num);

        if (jg(used))
            cout << i <<' '<< def<<' ' << ghi <<endl;
    }
    return 0;
}