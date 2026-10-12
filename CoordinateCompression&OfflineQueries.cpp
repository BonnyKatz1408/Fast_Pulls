#include <bits/stdc++.h>
#define read(x) int x; cin>>x
#define mod 1000000007
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define print(x) cout<<x<<" "
#define printarr(arr) for(auto &a:arr) cout<<a<<" "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sortarr(arr) sort(arr.begin(),arr.end())
using namespace std;
using ll = long long;
 

vector<int> arr;
vector<int> seg; //base node contains an extra variable freq
map<int,int> mp;  //stores frequencies of salaries
vector<int> coords; 

void build(int node, int l, int r) {
    //base case
    if( l == r ) {
        
        /*coords[l] returns the exact salary amount and mp finds the frequency
            of that salary
        */
        seg[node] = mp[coords[l]];
        return;
    }

    int mid = (l+r)/2;

    //build left child range
    build( node * 2 , l , mid );
    //build right child range
    build( node*2 + 1 , mid + 1 , r ); 

    seg[node] = seg[node*2] + seg[node*2+1];

}


void update(int node, int l, int r, int index, int value) {
    //base case
    //when updating we need to handle 2 cases
    // 1) update the freq in the older one
    // 2) update the freq in the newer one
    if(l == r) {
        seg[node] += value;
        return;
    }
    // do we have to go left or right in the ranges
    int mid = (l+r)/2;
    //go left if index is smaller than mid
    if( index <= mid) {
        update(node*2, l, mid,index, value);
    } else {
        update(node*2+1, mid+1, r, index,value);
    }
    //rebuild tree of way back
    seg[node] = seg[node*2] + seg[node*2+1];
}


int query(int node, int l, int r, int ql, int qr) {
    //if outside current range
    if(r < ql || l > qr ) return 0;
    //if inside current range
    if(ql<=l && r<=qr) return seg[node];
    //if partially fits
    int mid = (l+r)/2;
    return query(node*2,l,mid,ql,qr) + query(node*2+1,mid+1,r,ql,qr);
}

struct queries{
    char c;
    int l, r;
};

int main() {

    fast_io;
    read(n); read(q);

    arr.resize(n);

    // //common pitfall, seg tree is based on coords not on arr so this wrong XXXX
    // seg.resize(4*n);

    for(auto &a:arr) {
        cin>>a;
        mp[a]++;
    }
     
    coords = arr;
    vector<queries> qs;
    
    for(int i = 0; i < q; i++) {
        //add any missing salary ranges that werent originally given in the coords array
        char type; cin>>type; 
        read(left); read(right);
        queries temp;
        temp.c = type;
        temp.l = left;
        temp.r = right;
        qs.push_back(temp);
        
        coords.push_back(left);
        coords.push_back(right);
    }
     

    //sort in non decreasing order
    sort(coords.begin(),coords.end());
    /*unique points to next unique element compared to current, internally
        edits the array such that given 10,20,20,50,80,80
        //duplicates are moved to the end, since the array is sorted
        10 20 50 80 50 80    
                    ^

        at the end the iterator points to 50
        erase erases all elements from 50 to end
    */
    coords.erase(unique(coords.begin(),coords.end()),coords.end());
    
    //resize seg tree
    int k = coords.size();
    seg.resize(4*k);

    //build the tree from compressed indexes
    //explicitly converting coords.size() into int because it is size_t(which is unsigned integer data type)
    build(1,0, k-1);

    // but what about the mapping???
    /* we can create an external map for O(1)
        or just use upper/lower bound to find the index 
        of the current mapping in O(logN)
        both works
    */

    //store all salary queries because you dont know how many range are possible
    for(auto &p: qs) {
        
        if(p.c == '?' ) {
            //find index of left and right
            int indexleft = lower_bound(coords.begin(),coords.end(), p.l) - coords.begin();
            int indexright = upper_bound(coords.begin(), coords.end(), p.r) - coords.begin() - 1;
            cout<<query(1,0,k-1,indexleft,indexright) << "\n";
            
        } else { 
            
            int emp = p.l - 1;
            int oldsalary = arr[emp];
            //subtract old salary freq
            //find compressed index
            int indexold = lower_bound(coords.begin(),coords.end(),oldsalary) - coords.begin();
            update(1,0,k-1,indexold,-1);
            //add new salary freq
            //find new index
            arr[emp] = p.r;
            int indexnew = lower_bound(coords.begin(),coords.end(),p.r) - coords.begin();
            update(1,0,k-1,indexnew,1);
        }
    }
    return 0;
}
