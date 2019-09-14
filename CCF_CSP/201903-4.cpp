#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int is_send;
    int target;
}cmd;

typedef queue<cmd> process;

int main(){
    int T,n;
    string s;
    getline(cin,s);
    stringstream ss(s);
    ss >> T >> n;

    vector<process> p;

    while (T--){
        p.clear();
        p.resize(n);
        string line;
        for (int i=0;i<n;i++){
            getline(cin,line);
            stringstream ss(line);
            string command;
            while (ss >> command){
                cmd c1;
                c1.is_send = command[0] - 'R';
                c1.target = command[1] - '0';
                p[i].push(c1);
            }
        }
        
        for (int i=0;i<8;i++){
            for (int j=0;j<n;j++){
                if (!p[j].empty()){
                    cmd c1 = p[j].front();
                    if (!p[c1.target].empty() && c1.is_send == !p[c1.target].front().is_send){
                        p[j].pop(); p[c1.target].pop();
                    }
                }
            }
        }

        int lock = 0;
        for (int i=0;i<n;i++)
            if (!p[i].empty()){
                lock = 1;
                break;
            }

        cout << lock << endl;
    }
    return 0;
}