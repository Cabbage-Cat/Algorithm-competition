#include <bits/stdc++.h>

using namespace std;

bool is_daf(int xx)
{
    int x = xx;
    int c = x%10;
    x/=10;
    int b = x%10;
    x/=10;
    int a = x;

    return xx==a*a*a + b*b*b + c*c*c;

}
int main()
{
    for (int i=100;i<1000;i++)
        if (is_daf(i))
            cout << i << endl;
    return 0;
}