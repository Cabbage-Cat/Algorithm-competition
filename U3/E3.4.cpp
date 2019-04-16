#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[10],buf[99];
    scanf("%s",s);
    int kase = 0;
    for(int abc=100;abc<1000;abc++)
    {
        for(int de=10;de<100;de++)
        {
            memset(buf,0,sizeof(buf));
            int x = abc * (de%10);
            int y = abc * (de/10);
            int z = abc * de;

            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
            int flag = 1;

            for (int i=0;i<strlen(buf);i++)
                if (strchr(s,buf[i]) == NULL)
                {
                    flag = 0;
                    break;
                }
            
            if (flag)
                printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",++kase,abc,de,x,y,z);
        }
    }
    return 0;
}