#include <bits/stdc++.h>

using namespace std;

char maze[10+2][10+2];
int m_count[10+2][10+2];
typedef struct
{
    int count;
    char word[12];
}P;
bool cmp(P &p1, P &p2)
{
    return p1.count - p2.count<0;
}
int main()
{
    int t=0;
    while (++t)
    {
        int r,c;
        cin >> r >> c;
        if (!r)
            break;
        if (t!=1)
            printf("\n");
        for (int i=0;i<r;i++)
            scanf("%s",maze[i]);
        
        int count = 0;
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
            {
                if (maze[i][j]!='*' && ((i==0||j==0) || maze[i-1][j]=='*' || maze[i][j-1] == '*'))
                    m_count[i][j] = ++count;
            }
        
        char s[10+2];
        printf("puzzle #%d:\n",t);
        
        //row
        printf("Across\n");
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                int s_c = 0;
                memset(s,0,sizeof(s));
                int cc = m_count[i][j];
                if (cc)
                {
                    s[s_c++] = maze[i][j];
                    while (++j<c && maze[i][j]!='*')
                        s[s_c++] = maze[i][j];
                    printf("%3d.%s\n",cc,s);
                }
            }
        }
        //column
        printf("Down\n");
        P words[100];
        int co = 0;

        for (int j=0;j<c;j++)
        {
            for (int i=0;i<r;i++)
            {
                int s_c = 0;
                memset(s,0,sizeof(s));
                int cc = m_count[i][j];
                if (cc)
                {
                    s[s_c++] = maze[i][j];
                    while (++i<r && maze[i][j]!='*')
                        s[s_c++] = maze[i][j];
                    words[co++].count = cc;
                    strcpy(words[co-1].word,s);
                }
            }
        }
        sort(words,&words[co],cmp);
        for (int i=0;i<co;i++)
            printf("%3d.%s\n",words[i].count,words[i].word);
        
        for (int i=0;i<12;i++)
            for (int j=0;j<12;j++)
            {
                maze[i][j] = 0;
                m_count[i][j] = 0;
            }
    }
    return 0;
}