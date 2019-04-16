#include <bits/stdc++.h>

using namespace std;

int maze[100][100];
int main()
{
    int n;
    cin >> n;
    int x,y,total;

    total = maze[x=0][y=n-1] = 1;

    while (total<n*n)
    {
        while (x+1<n && !maze[x+1][y])
            maze[++x][y] = ++total;
        while (y-1>-1 && !maze[x][y-1])
            maze[x][--y] = ++total;
        while (x-1>-1 && !maze[x-1][y])
            maze[--x][y] = ++total;
        while (y+1<n && !maze[x][y+1])
            maze[x][++y] = ++total;
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%3d ",maze[i][j]);
            // cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}