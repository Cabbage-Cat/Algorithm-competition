#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}

void print(const string &s,int len,char extra){
    cout << s;
    _for(i,0,len-s.length())
        cout << extra;
}

const int maxcol = 60;
string words[100+5];
int n;
int main(){
    while (scanf("%d",&n)==1 && n){
        print("",maxcol,'-'); printf("\n");
        int m=0;
        _for(i,0,n){
            cin >> words[i];  
            m = max(m,(int)words[i].length());
        }
        sort(words,words+n);
        int col = (maxcol - m)/(m+2) + 1;
        int row = (n-1)/col + 1;
        _for(i,0,row){
            _for(j,0,col){
                int index = i+j*row;
                if (index<n) j==col-1? print(words[index],m+2,' '): print(words[index],m,' ');
            }
            printf("\n");
        } 
    }
    return 0;
}