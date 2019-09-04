#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{ 
    int seed=time(NULL);
    if(argc > 1)
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;
    }
    srand(seed);
    int n=random(1,100000),m=random(1,100000);
    printf("%d %d\n",n,m);
    for (int i=0;i<m;i++){
        int s = random(1,4);
        if (s == 4) printf("4\n");
        else{
            int x = random(1,n);
            int y = random(1,n);
            printf("%d %d %d\n",s,x,y);
        }
    }

    //printf("\n");
    return 0;
}
