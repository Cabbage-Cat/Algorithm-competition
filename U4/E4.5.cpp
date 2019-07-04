#include <bits/stdc++.h>
using namespace std;

int r,c,n;
struct Command{
    char s[5];
    int r1,c1,r2,c2;
    int A,index[12];
}Cmd[10000];

int exeCmd(int& r0,int& c0){
    for (int i=0;i<n;i++){
        if (Cmd[i].s[0] == 'E'){
            if (Cmd[i].r1 == r0 && Cmd[i].c1 == c0){
                r0 = Cmd[i].r2;c0 = Cmd[i].c2;
            }
            else if (Cmd[i].r2 == r0 && Cmd[i].c2 == c0){
                r0 = Cmd[i].r1;c0 = Cmd[i].c1;
            }
        }else{
            int dr=0,dc=0;
            for (int j=0;j<Cmd[i].A;j++){
                int x = Cmd[i].index[j];
                if (Cmd[i].s[0] == 'I'){
                    if (Cmd[i].s[1] == 'R' && x<=r0) dr++;
                    if (Cmd[i].s[1] == 'C' && x<=c0) dc++;
                }else{
                    if (Cmd[i].s[1] == 'R' && x==r0) return 0;
                    if (Cmd[i].s[1] == 'C' && x==c0) return 0;
                    if (Cmd[i].s[1] == 'R' && x<r0) dr--;
                    if (Cmd[i].s[1] == 'C' && x<c0) dc--;
                }
            }
            r0+=dr;c0+=dc;
        }
    }
        return 1;
}
int main(){
    int c0,r0,q,kase=0;
    while (scanf("%d%d%d",&r,&c,&n)==3 && r){
        memset(Cmd,0,sizeof(Cmd));
        for (int i=0;i<n;i++){
            scanf("%s",Cmd[i].s);
            if (Cmd[i].s[0] == 'E'){
                scanf("%d%d%d%d",&Cmd[i].r1,&Cmd[i].c1,&Cmd[i].r2,&Cmd[i].c2);
            }else{
                scanf("%d",&Cmd[i].A);
                for (int j=0;j<Cmd[i].A;j++){
                    scanf("%d",&Cmd[i].index[j]);
                }
            }
        }
        if (kase>0) printf("\n");
        printf("Spreadsheet #%d\n",++kase);

        scanf("%d",&q);
        while (q--){
            scanf("%d%d",&r0,&c0);
            printf("Cell data in (%d,%d) ",r0,c0);
            if (exeCmd(r0,c0)) printf("moved to (%d,%d)\n",r0,c0);
            else printf("GONE\n");            
        }
    }
    return 0;
}