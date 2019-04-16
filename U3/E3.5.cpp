#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;bool flag = true;
    while ((c=getchar())!=EOF)
    {
        if (c == '"')
        {
            printf("%s",flag?"``":"''");
            flag = !flag;
        }
        else
            putchar(c);
        
    }
    return 0;
}