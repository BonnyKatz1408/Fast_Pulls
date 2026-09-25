#include<template.hpp>

int main() {

    //fast_io and input
    fast_io;
	int n,k;
	cin>>n>>k;

    //input arr
	vector<int> arr(n);
	for(int &a:arr) cin>>a;

    //missing set and non missing map
	set<int> st;
	unordered_map<int,int> mp;

    //insert into missing set
	for(int i = 0; i <= n+1 ; i++) st.insert(i);

    //create initial window
	for(int i = 0; i < k ;i++) {
	    mp[arr[i]]++;
	    st.erase(arr[i]);
	}
	cout<<(*st.begin())<<" ";

    //calculate for removing windows
	for(int i = k; i < n; i++ ) {
	    
	    mp[arr[i-k]]--;
	    if(mp[arr[i-k]] == 0 ) {
	        st.insert(arr[i-k]);
	    }
	    mp[arr[i]]++;
	    st.erase(arr[i]);
	    cout<<(*st.begin())<<" ";
	}

	return 0;

}


//TC: O (N Log N)       //N intial input into set, log n to insert and remove
//SC: O (N)             //N for set 
//TC: O (1)             //QUERY 