#include <bits/stdc++.h>
int main(){
    int l,D,I;
    scanf("%d",&l);
    for (int i=0;i<l;i++){
        scanf("%d%d",&D,&I);
        int k=1;
        for (int j=0;j<D-1;j++){
            if (I%2) { k*=2; I = (I+1)/2; }
            else { k=k*2+1; I = I/2; }
        }
        printf("%d\n",k);
    }
    return 0;
}