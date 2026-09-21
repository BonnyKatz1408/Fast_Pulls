#include <template.hpp>
 
int main() {
    
    //input and fast_io
    fast_io;
    read(n); read(q);
    vector<int> arr(n);
    for(auto &a:arr) cin>>a;
    
    // find the largest power of 2 we can fit for current array size
    int max_pow = log2(n)+1;
    vector<vector<int>> st(max_pow,vector<int>(n));
    
    //startin filling table in increasing power of 2;
    //first take only 2^0 ie 1 element
    //then minimum of 2 adjacent numbers
    //then minimum of 4 starting from that particular index
    //so we effectively store the minimum starting from each index
    //
    for(int i = 0; i < max_pow ; i++) {
        for(int j = 0; j+(1<<i) <= n ; j++ ) {
            if(i==0) {
                st[0][j] = arr[j];
                continue;
            }
            st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    //O(1) per query
    // we are dividin in max groups of pow(2)
    // if it divides perfectly we take 2 groups with no common element and take minimum
    // if it doesnt divide perfectly, ie its odd, we divide the elements with a greater power of 2 
    // but take some common elements still solving the query in O(1) time
    
    while(q--) {
        read(x); read(y);
        y--; x--;
        int L = log2(y-x+1);
        cout<<min(st[L][x],st[L][y-(1<<L)+1])<<"\n";
    }
    return 0;
}