#include <bits/stdc++.h>
using namespace std;
struct gold{ int x; double num; gold(int x,double num):x(x),num(num){} 
  bool operator < (const gold& u)const { return num > u.num; }
};
struct prize{ int x; double num; prize(int x,double num):x(x),num(num){} 
  bool operator < (const prize& u)const { return num > u.num; }
};
struct gold_percent{ int x; double per; gold_percent(int x,double per):x(x),per(per){}
  bool operator < (const gold_percent& u)const { return per > u.per; }
};
struct prize_percent{ int x; double per;prize_percent(int x,double per):x(x),per(per){} 
  bool operator < (const prize_percent& u)const { return per > u.per; }
};
struct Node{
  double gold_sum,prize_sum,people_sum;
};
vector<Node> ns;
vector<gold> g;
vector<prize> p;
vector<gold_percent> g_per;
vector<prize_percent> p_per;
int m_contry[1000000];
int main(){
  int n,m;
  double a,b,c;
  while (~scanf("%d%d",&n,&m)){
    Node x;
    for (int i=0;i<n;i++){
      scanf("%lf%lf%lf",&a,&b,&c); 
      x.gold_sum = a; x.prize_sum = b; x.people_sum = c;
      ns.push_back(x);
    }
    int num;
    for (int i=0;i<m;i++){
      scanf("%d",&num); x = ns[num]; m_contry[i] = num;
      g.push_back(gold(num,x.gold_sum));
      p.push_back(prize(num,x.prize_sum));
      g_per.push_back(gold_percent(num,x.gold_sum/x.people_sum));
      p_per.push_back(prize_percent(num,x.prize_sum/x.people_sum));
    }
    sort(g.begin(),g.end());
    sort(p.begin(),p.end());
    sort(g_per.begin(),g_per.end());
    sort(p_per.begin(),p_per.end());
    

  }
  return 0;
}