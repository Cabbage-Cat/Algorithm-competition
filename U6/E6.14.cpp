#include <bits/stdc++.h>
using namespace std;

struct Node {
	int r,c,dir;
	Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir) {}
};
const int maxn=10;

const char* dirs = "NESW";
const char* turns = "FLR";
int get_dir(char c)	{ return strchr(dirs,c)-dirs; }
int get_turn(char c) { return strchr(turns,c)-turns; }

int has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
Node p[maxn][maxn][4];

int r0,c0,dir,r1,c1,r2,c2;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

Node walk(const Node& u,int turn){
	int dir = u.dir;
	if (turn == 1) dir = (dir+3) % 4;
	if (turn == 2) dir = (dir+1) % 4;
	Node p = Node(u.r+dr[dir],u.c+dc[dir],dir);
	return p;
}

bool inside(int r,int c){
	return r>0 && r<10 && c>0 && c<10;
}

bool read_case(){
	char s1[100],s2[100];
	if (scanf("%s%d%d%s%d%d",s1,&r0,&c0,s2,&r2,&c2) != 6) return false;
	printf("%s\n",s1);
	dir = get_dir(s2[0]);
	r1 = r0 + dr[dir];
	c1 = c0 + dc[dir];

	memset(has_edge,0,sizeof(has_edge));
	for (;;){
		int r,c;
		scanf("%d",&r);
		if (r==0) break;
		scanf("%d",&c);
		while (scanf("%s",s1)==1 && s1[0]!='*'){
			int d = get_dir(s1[0]);
			for (int i=1;i<strlen(s1);i++){
				int t = get_turn(s1[i]);
				has_edge[r][c][d][t] = 1;
			}
		}
	}
	return true;
}

void print_ans(Node& u){
	vector<Node> nodes;
	for (;;){
		nodes.push_back(u);
		if (d[u.r][u.c][u.dir]==0) break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0,c0,dir));

	int cnt = 0; int l = nodes.size()-1;
	for (;l>-1;l--){
		if (cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)",nodes[l].r,nodes[l].c);
		if (++cnt % 10 == 0) printf("\n");
	}
	if (nodes.size()%10) printf("\n");
}
void solve(){
	queue<Node> q;
	memset(d,-1,sizeof(d));
	memset(p,0,sizeof(p));
	Node u(r1,c1,dir);
	q.push(u);
	d[u.r][u.c][u.dir] = 0;

	while (!q.empty()){
		Node u = q.front(); q.pop();
		if (u.r == r2 && u.c == c2) { print_ans(u); return; }
		for (int i=0;i<3;i++){
			Node v = walk(u,i);
			if (has_edge[u.r][u.c][u.dir][i] && inside(v.r,v.c) &&
				d[v.r][v.c][v.dir]<0){
					d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
					p[v.r][v.c][v.dir] = u;
					q.push(v);
				}
		}
	}
	printf("  No Solution Possible\n");


}

int main(){
	while (read_case()){
		solve();
	}
	return 0;
}