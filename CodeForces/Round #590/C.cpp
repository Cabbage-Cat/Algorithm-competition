#include <bits/stdc++.h>
using namespace std;

int main(){
	int q; cin >> q;
	for (int i=0;i<q;i++){
		int n; string s[2];
		cin >> n >> s[0] >> s[1];
		int pos = 0;
		int row = 0;
		for (pos=0;pos<n;pos++){
			if (s[row][pos] >= '3'){
				if (s[row^1][pos]<'3') break;
				row^=1;
			}
		}
		if (row==1 && pos==n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}