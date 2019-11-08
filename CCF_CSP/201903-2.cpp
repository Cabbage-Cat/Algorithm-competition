#include <iostream>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

map<char,int> pq;
int main(){
    pq['+'] = 1; pq['-'] = 1;
    pq['x'] = 2; pq['/'] = 2;
    int n; cin >> n;
    string s;
    for (int i=0;i<n;i++){
        cin >> s;
        stringstream ss(s);
        stack<int> num;
        stack<char> fuhao;
        int x; char c;
        ss >> x; num.push(x);
        while (ss >> c){
            fuhao.push(c);
            ss >> x;
            num.push(x);
        }    

        stack<int> res;
        stack<char> f;
        res.push(num.top()); num.pop();

        while (!fuhao.empty()){
            char ff = fuhao.top(); fuhao.pop();
            if (f.empty() || pq[f.top()] <= pq[ff]){
                f.push(ff);
                res.push(num.top()); num.pop();
            }
            else{
                while (!f.empty() && pq[f.top()] > pq[ff]){
                    char f1 = f.top(); f.pop();
                    int y = res.top(); res.pop(); int x = res.top(); res.pop();
                    if (f1 == '+') res.push(y+x);
                    if (f1 == '-') res.push(y-x);
                    if (f1 == 'x') res.push(y*x);
                    if (f1 == '/') res.push(y/x);
                }
                f.push(ff);
                res.push(num.top()); num.pop();
            }
        }

        while (!f.empty()){
            char f1 = f.top(); f.pop();
            int y = res.top(); res.pop(); int x = res.top(); res.pop();
            if (f1 == '+') res.push(y+x);
            if (f1 == '-') res.push(y-x);
            if (f1 == 'x') res.push(y*x);
            if (f1 == '/') res.push(y/x);
        }

        if (res.top() == 24)
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}