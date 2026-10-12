#include<template.hpp>

int main() {
    
    //fast io and inputs
    fast_io;

    read(d); read(k);
    read(x); read(a); read(b); read(c);



    //actual input generation
	vector<ll> arr(n);
	arr[0] = x;
	for(int i = 1; i < n; i++) {
	    arr[i] = (a*arr[i-1]+b)%c;
	}

    /*prefix and suffix arrays, they store the numbers from 0 -> k-1
        
        [3,0,1,8,2,4,7,6]
        k = 5

        divide the arrays into parts of k size from both suffix and prefix
        for prefix =  [3,0,1,8,2] [4,7,6]
        for suffix =  [3.0,1] [8,2,4,7,6]

        so we need the OR of the Window 

        [3,0,1,8,2] 
        [0,1,8,2,4]
        [1,8,2,4,7]
        [8,2,4,7,6]


              0  1  2  3  4  0  1  2
              0  1  2  3  4  5  6  7  

        pre = 3  3  3  11 11 4  7  7

              2  1  0  4  3  2  1  0
              0  1  2  3  4  5  6  7

        suf = 3  1  1  15 7  7  7  6 

        pref[0+5-1] = 4 =  [ 3 | 0 | 1 | 8 | 2 ] 
        suf[0]      = 0 =  [ 3 | 1 | 1 ]


        window  = 0,1,8,2,4
        pref[1+5-1] = 5 =  [ 4 ]
        suffix[1]   = 1 =  [ 0 |  ]



        // 0%5= pref[0]





    */
    vector<int> pref(n), suff(n);
























}