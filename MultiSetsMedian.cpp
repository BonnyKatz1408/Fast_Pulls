#include <bits/stdc++.h>
#define read(x) int x; cin>>x
#define mod 1000000007
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define print(x) cout<<x<<" "
#define printarr(arr) for(int i = 0; i < arr.size();i++) cout<<arr[i]<<" "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sortarr(arr) sort(arr.begin(),arr.end())
using namespace std;
using ll = long long;

multiset<int> lo,hi;

void balance() {
    while(lo.size() > hi.size()+1) {
        int k = *lo.rbegin();
        lo.erase(lo.find(k));
        hi.insert(k);
    }
    while(hi.size() > lo.size()) {
        int k = *hi.begin();
        lo.insert(k);
        hi.erase(hi.find(k));
    }
}
void rem(int x) {
    if(lo.find(x) != lo.end()) {
        lo.erase(lo.find(x));
    } else {
        hi.erase(hi.find(x));
    }
    balance();
}

void add(int x) {
    if(lo.empty() || *lo.rbegin() >= x) lo.insert(x);
    else hi.insert(x);
    balance();
}

int median() {
    return *lo.rbegin();
}
int main() {
    fast_io;
    read(n); read(k);
    vector<int> arr(n);
    for(auto &a:arr) cin>>a;
    for(int i = 0; i < k; i++) add(arr[i]);
    print(median());
    for(int i = k; i < n; i++) {
        rem(arr[i-k]);
        add(arr[i]);
        print(median());
    }
    return 0;
    
}
 