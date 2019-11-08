#include <cstdio>
#include <iostream>
#include <algorithm>
int num[100000+5];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int _min = num[0],_max = num[n-1];
    if (_min>_max) std::swap(_min,_max);
    printf("%d ",_max);
    int res;
    if (n%2){
       res =  num[n/2];
        printf("%d ",res);
    }
    else{
        res = num[n/2-1] + num[n/2];
        if (res%2)
            printf("%d.5 ",res/2);
        else
            printf("%d ",res/2);
    }
    printf("%d",_min);
    
    return 0;
}