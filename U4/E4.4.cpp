#include <bits/stdc++.h>
using namespace std;

int code[8][1<<8];
char readchar(){
    for (;;){
        char c = getchar();
        if (c!='\n' && c!='\r')
            return c;
    }
}

int readint(int l){
    int r = 0;
    while (l--){
        r = r*2 + (readchar() - '0');
    }
    return r;
}

int readcode(){
    code[1][0] = readchar();
    for (int l = 2;l<8;l++){
        for (int i=0;i<(1<<l)-1;i++){
            char c = getchar();
            if (c == EOF)
                return 0;
            if (c == '\n' || c == '\r')
                return 1;
            
            code[l][i] = c;
        }
    }
    return 1;
}


int main(){
    while (readcode()){
        for (;;){
            int len = readint(3);
            if (len == 0)
                break;
            
            for (;;){
                int v = readint(len);
                if (v == (1<<len) - 1)
                    break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}