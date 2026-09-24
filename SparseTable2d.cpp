#include<template.hpp>

int main() {

    //fastio and array orders input
    fast_io;
    read(m); read(n);

    //powers
    int k1 = log2(m) + 1;
    int k2 = log2(n) + 1;


    //array
    vector<vector<int>> arr(m,vector<int>(n));

    //2d sparse table 
    vector<vector<vector<vector<int>>>> st(k1, vector<vector<vector<int>>> (k2,vector<vector<int>>(m+1,vector<int>(n+1))));

    //sparse table for each row
    vector<vector<vector<int>>> rowST(m+1,vector<vector<int>>(k1,vector<int>(n+1)));

    //input the array
    for(int i = 0; i < m ; j++ ) {  //current row
        for(int j = 0 ; j < k2 ; j++) { // current power
            for(int l = 0 ; l + (1<<j) <= n ; i++){     //current columns
                if(j == 0) {
                    rowST[i][j][l] = arr[i][j];
                    continue;
                }
                rowST[i][j][l] = min(rowST[i][j-1][l], rowST[i][j-1][l+(1<<(j-1))]); //fill table
            }
        }
    }

    //
    

    for(int i = 0; i < )




        




    return 0;
}