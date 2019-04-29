#include <bits/stdc++.h>

using namespace std;

char maze[5][7];
int kase = 0;
int main()
{
    while (fgets(maze[0],8,stdin))
    {
        if (maze[0][0] == 'Z')
            break;
        
        for (int i=1;i<5;i++)
            fgets(maze[i],8,stdin);
        int blank_x,blank_y;
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                if (maze[i][j] == ' ')
                {
                    blank_x = i;
                    blank_y = j;
                }
        int count = 0;
        char cond[1000];
        while (~scanf("%c",&cond[count]))
            if (cond[count] != '0')
                count++;
            else
                break;
        cond[count] = 0;getchar();

        int flag = 0;
        for (int i=0;cond[i];i++)
        {
            int x=blank_x,y=blank_y;
            switch (cond[i])
            {
                case 'A':
                {
                    x--;
                    break;
                }
                case 'B':
                {
                    x++;
                    break;
                }
                case 'L':
                {
                    y--;
                    break;
                }
                case 'R':
                {
                    y++;
                    break;
                }
            }
            if (x<0 || x>4 || y<0 || y>4)
            {
                flag = 1;break;
            }
            else
            {
                maze[blank_x][blank_y] = maze[x][y];
                maze[x][y] = ' ';
                blank_x = x;blank_y = y;
            }
        }
        if (kase++)
            printf("\n");
        printf("Puzzle #%d:\n",kase);

        if (flag)
            printf("This puzzle has no final configuration.\n");
        else
        {
            for (int i=0;i<5;i++)
            {
                printf("%c",maze[i][0]);
                for (int j=1;j<5;j++)
                {
                    printf(" %c",maze[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}