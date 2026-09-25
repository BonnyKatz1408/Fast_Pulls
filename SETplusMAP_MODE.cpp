#include<template.hpp>
 
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    unordered_map < int, int > mp;
    set < pair < int, int >> st; // negative freq,element
    vector < int > nums(n);
    for (int & a: nums) cin >> a;
 
    //first window
    for (int i = 0; i < k; i++) {
        if (mp.contains(nums[i])) {
            st.erase({
                -mp[nums[i]],
                nums[i]
            });
        }
        mp[nums[i]]++;
        st.insert({
            -mp[nums[i]],
            nums[i]
        });
    }
    cout << (st.begin() -> second) << " ";
 
    //remaining windows
    for (int i = k; i < n; i++) {
 
        if (mp.contains(nums[i - k])) {
            st.erase({
                -mp[nums[i - k]],
                nums[i - k]
            });
            mp[nums[i - k]]--;
 
            if (mp[nums[i - k]] > 0)
                st.insert({
                    -mp[nums[i - k]],
                    nums[i - k]
                });
        }
 
        //new updates
        if (mp.contains(nums[i])) {
            st.erase({
                -mp[nums[i]],
                nums[i]
            });
        }
        mp[nums[i]]++;
        st.insert({
            -mp[nums[i]],
            nums[i]
        });
        cout << (st.begin() -> second) << " ";
 
    }
 
 
    return 0;
}