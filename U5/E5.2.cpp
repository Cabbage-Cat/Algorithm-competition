#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
const int maxn = 30;
vector<int> pile[maxn];
int n;
void find_above(int x,int& p,int &h){
    for (p=0;p<n;p++){
        for (h=0;h<pile[p].size();h++)
            if (pile[p][h]==x) return;
    }
}
void clear_above(int p,int h){
    _for(i,h+1,pile[p].size()){
        int tmp = pile[p][i];
        pile[tmp].push_back(tmp);
    }
    pile[p].resize(h+1);
}

void pile_over(int p,int h,int to){
    _for(i,h,pile[p].size()){
        int tmp = pile[p][i];
        pile[to].push_back(tmp);
    }
    pile[p].resize(h);
}

void print(){
    _for(i,0,n){
        printf("%d:",i);
        _for(j,0,pile[i].size()) printf(" %d",pile[i][j]);
        printf("\n");
    }
}
int main(){
    int a,b;
    string s1,s2;
    cin >> n;
    _for(i,0,n) pile[i].push_back(i);
    int pa,ha,pb,hb;
    while (cin>>s1>>a>>s2>>b){
        find_above(a,pa,ha);find_above(b,pb,hb);
        if (pa==pb) continue;
        if (s2=="onto") clear_above(pb,hb);
        if (s1=="move") clear_above(pa,ha);
        pile_over(pa,ha,pb);
    }
    print();
    return 0;
}

