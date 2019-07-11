#include <bits/stdc++.h>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
#define _rep(i,a,b) for (int i=(a);i<=(b);i++)
typedef long long _i64;
using namespace std;

int coeff[3] = {2,3,5};
int main(){
    priority_queue<_i64,vector<_i64>,greater<_i64>> pq;
    set<_i64> s;
    pq.push(1);s.insert(1);

    for (int i=1;;i++){
        _i64 x = pq.top(); pq.pop();
        if (i==1500) {
            printf("The 1500'th ugly number is %d.\n",x);
            break;
        }
        _for(j,0,3){
            _i64 xx = x*coeff[j];
            if (!s.count(xx)){
                s.insert(xx); pq.push(xx);
            }
        }
    }
    return 0;
}