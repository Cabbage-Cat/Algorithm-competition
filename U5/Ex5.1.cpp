#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
const int maxn = 1000;
vector<string> LineWords[maxn];
size_t WordLen[maxn],LineCnt;

int main(){
    string line,word;
    LineCnt=0;
    while(getline(cin,line)){
        stringstream ss(line);
        size_t wi=0;
        while (ss >> word){
            WordLen[wi] = max(WordLen[wi],word.size());
            wi++;
            LineWords[LineCnt].push_back(word);
        }
        LineCnt++;
    }

    _for(i,0,LineCnt){
        const auto& ws = LineWords[i];
        _for(j,0,ws.size()) cout<<left<<setw(j<ws.size()-1?WordLen[j]+1:0)<<ws[j];
        cout << endl;
    }
    return 0;
}