#include <bits/stdc++.h>

using namespace std;

int n,k,m,p[23];
int go(int begin,int d,int step){
    while (step--){
        do{
            begin = (begin + d + n -1)%n + 1;
        }while(!p[begin]);
    }    
    return begin;
}
int main(){
    while (scanf("%d%d%d",&n,&k,&m) == 3 && n){
        for (int i=1;i<=n;i++){
            p[i] = i;
        }

        int left = n,p1 = n,p2 = 1;
        while (left){
            p1 = go(p1,1,k);
            p2 = go(p2,-1,m);

            printf("%3d",p1);left--;

            if (p1-p2){
                printf("%3d",p2);
                left--;
            }

            p[p1] = p[p2] = 0;
            if (left){
                printf(",");
            }
        }

        printf("\n");
    }
    return 0;
}