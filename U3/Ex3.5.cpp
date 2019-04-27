#include <bits/stdc++.h>

using namespace std;

char maze[5+3][5+3];

int R(int &x,int &y)
{
    if (y+1>=0 && y+1<5)
    {
        maze[x][y] = maze[x][y+1];
        maze[x][y+1] = ' ';
        y++;
        return 1;
    }
    return 0;
}

int L(int &x,int &y){
    if (y-1>=0 && y-1<5)
    {
        maze[x][y] = maze[x][y-1];
        maze[x][y-1] = ' ';
        y--;
        return 1;
    }
    return 0;
}

int A(int &x,int &y)
{
    if (x-1>=0 && x-1<5)
    {
        maze[x][y] = maze[x-1][y];
        maze[x-1][y] = ' ';
        x--;
        return 1;
    }
    return 0;
}

int B(int &x,int &y)
{
    if (x+1>=0 && x+1<5)
    {
        maze[x][y] = maze[x+1][y];
        maze[x+1][y] = ' ';
        x++;
        return 1;
    }
    return 0;
}

int main()
{
    int t=0;
    char cond;
    int blank_x,blank_y;
    while (++t)
    {
        memset(maze,0,sizeof(maze));
        int flag;
        fgets(maze[0],8,stdin);
        if (maze[0][0] == 'Z')
            break;
        for (int i=1;i<5;i++)
            fgets(maze[i],8,stdin);
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                if (maze[i][j] == ' ')
                {
                    blank_x = i;
                    blank_y = j;
                }
        while ((cond=getchar())!='0')
        {
            if (cond == 'A')
            {
                flag = A(blank_x,blank_y);
            }
            else if (cond == 'B')
            {
                flag = B(blank_x,blank_y);
            }
            else if (cond == 'L')
            {
                flag = L(blank_x,blank_y);
            }
            else if (cond == 'R')
            {
                flag = R(blank_x,blank_y);
            }
        }
        getchar();
        // for (int i=0;i<5;i++)
        // {
        //     if (!b)
        //         break;
        //     for (int j=0;j<5;j++)
        //     {
        //         scanf("%c",&maze[i][j]);
        //         c = maze[i][j];
        //         if (c=='Z')
        //         {
        //             b = 0;
        //             break;
                    
        //         }
        //         if (c==' ')
        //         {
        //             blank_x = i;
        //             blank_y = j;
        //         }
        //     }
        
        // }
        // char con[1000];
        // scanf("%s",con);

        // for (int i=0;i<strlen(con);i++)
        // {
        //     int flag;
        //     if (con[i] == 'A')
        //     {
        //         flag = A(blank_x,blank_y);
        //     }
        //     else if (con[i] == 'B')
        //     {
        //         flag = B(blank_x,blank_y);
        //     }
        //     else if (con[i] == 'L')
        //     {
        //         flag = L(blank_x,blank_y);
        //     }
        //     else if (con[i] == 'R')
        //     {
        //         flag = R(blank_x,blank_y);
        //     }

        //     if (!flag)
        //     {
        //         printf("Puzzle #%d:\n",t);
        //         printf("This puzzle has no final configuration.\n");
        //         break;
        //     }

            if (flag)
            {
                printf("Puzzle #%d:\n",t);
                for (int i=0;i<5;i++)
                {
                    fputs(maze[i],stdout);
                }
                printf("\n");
            }
            else
            {
                printf("Puzzle #%d:\n",t);
                printf("This puzzle has no final configuration.\n");
            }
            
        
    }
    return 0;
}