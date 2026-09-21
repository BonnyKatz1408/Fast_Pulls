#include<template.hpp>

vector<ll> seg;
vector<ll> arr;
vector<ll> lazy; // lazy propgation array

void build(int node, int l, int r) {
    //base case
    if(l == r) {
        seg[node] = arr[l];
        return;
    }
    //fill the node with values
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(2*node+1,mid+1,r);
}

void update(int node, int l, int r, int ql, int qr, ll val) {
    if(r < ql || l > qr) return; //outside current range
    if(ql <= l && r <= qr) {    //inside current range
        lazy[node] += val;
        return;
    }

    int mid = (l+r)/2;
    update(node*2,l,mid,ql,qr,val);
    update(node*2+1,mid+1,r,ql,qr,val);

}

ll query(int node, int l, int r, int idx) {
    if( l == r ) return seg[node] + lazy[node];
    int mid = (l+r)/2;
    if(idx <= mid) return lazy[node] + query(node*2,l,mid,idx);
    return lazy[node] + query(node*2+1,mid+1,r,idx);
}


int main () {

    //fast_io and input 
    fast_io;
    read(n); read(q);
    arr.resize(n);

    for(int i = 0; i < n ; i++) {
        ll k; cin>>k;
        arr[i] = k;
    }

    //intialise segment tree and lazy 
    seg.resize(4*n);
    lazy.resize(4*n);

    //build segment tree
    build(1,0,n-1);

    while(q--) {
        int type,a,b,u;
        cin>>type;
        if(type==1) {
            cin>>a>>b>>u;
            a--;
            b--;
            update(1,0,n-1,a,b,u);
        } else {
            cin>>a;
            a--;
            cout<<query(1,0,n-1,a)<<"\n";
        }
    }


    return 0;
}   
