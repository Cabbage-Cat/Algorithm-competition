#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;

int readint(){
    int x; scanf("%d",&x); return x;
}
int T,n,t1,t2,t3,t4,t5,Q;
typedef struct{
    vector<string> command;
    int cmdindex=0;
}Program;
int var[26];
Program programcache[1024];
deque<int> waitdeque;queue<int> blockqueue;
bool plock;
void run(int idx){
    int q = Q;
    while (q>0){
        Program &p = programcache[idx];
        string &cmd = p.command[p.cmdindex];
        if (cmd[2]=='='){
            q-=t1;
            int v = cmd.size()==6?(cmd[4]-'0')*10+(cmd[5]-'0'):cmd[4]-'0';
            var[cmd[0]-'a']=v;
        }
        else if (cmd[0]=='p'){
            q-=t2;
            cout << idx+1 <<": "<<var[cmd[6]-'a'] << '\n';
        }
        else if (cmd[0]=='l'){
            if (plock){
                blockqueue.push(idx);
                return;
            }
            else plock = true;
            q-=t3;
        }
        else if (cmd[0]=='u'){
            q-=t4;
            plock = false;
            if (!blockqueue.empty()){
                int b = blockqueue.front(); blockqueue.pop();
                waitdeque.push_front(b);
            }
        }
        else {
            q-=t5;
            return;
        }
        p.cmdindex++;
    }
    waitdeque.push_back(idx);
}
int main(){
    cin >> T;
    while (T--){
        cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q; getchar();
        memset(programcache,0,sizeof(programcache));memset(var,0,sizeof(var));
        waitdeque.clear();
        
        _for(i,0,n){
            string s;
            while (getline(cin,s)){
                programcache[i].command.push_back(s);
                if (s=="end") break;
            }
            waitdeque.push_back(i);
        }
        plock = false;
        while (!waitdeque.empty()){
            int pidx = waitdeque.front();waitdeque.pop_front();
            run(pidx);
        }
        if (T) cout << endl;
    }
    return 0;
}