#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int q; cin>>q;
	
	//build prefixsum 2d table
	vector<vector<int>> prefixarr(n+1,vector<int>(n+1));
	for(int i = 1 ; i <= n ; i++) {
	    for(int j = 1 ; j <= n ; j++) {
	       char c; cin>>c;
	       prefixarr[i][j] = (c == '*') + prefixarr[i][j-1] + prefixarr[i-1][j] - prefixarr[i-1][j-1];
	    }
	}
	
	//subtract left and side above but since we subtracted the top left twice, we need to add it once
    while(q--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int k = prefixarr[x2][y2]-prefixarr[x2][y1-1]- prefixarr[x1-1][y2] + prefixarr[x1-1][y1-1];
        cout<<k<<"\n";
    }
    return 0;
}
