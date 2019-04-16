#include <bits/stdc++.h>

using namespace std;

char s_r[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char rev(char c)
{
    return isalpha(c)?s_r[c-'A']:s_r[c-'0'+25];
}
int main()
{
    char buf[99];
    char *status[] = {"is not a palindrome.","is a mirrored string.","is a regular palindrome.","is a mirrored palindrome."};
    while (scanf("%s",buf) == 1)
    {
        bool is_c = true,is_rev = true;
        int l = strlen(buf);

        for (int i=0;i<(l+1)/2;i++)
        {
            if (buf[i] != buf[l-1-i])
                is_c = false;
            if (buf[i] != rev(buf[l-1-i]))
                is_rev = false;
        }

        printf("%s -- ",buf);

        printf("%s\n\n",is_c?is_rev?status[3]:status[2]:is_rev?status[1]:status[0]);
        
    }
    return 0;
}
