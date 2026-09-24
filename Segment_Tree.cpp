#include<template.hpp>

//why 4*n, because its safe, 2*n works sometimes but other times it doesnt
vector<int> segment_tree;
vector<int> arr;


void build(int node, int l, int r) {

    if(l==r) {      //base case
        segment_tree[node] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;  
    build(2*node,l,mid);            //recursively build the left and the right of the tree
    build(2*node+1,mid+1,r);

    segment_tree[node] = min(segment_tree[2*node],segment_tree[2*node+1]);   //store the minimum//whatever when it returns;
}


//resolving queries
// start at root, 0, n-1 basically look through the whole tree, starting at the root,
// now what is ql , qr ?, ql qr is the actual range that we are trying to calculate in
int query(int node, int l, int r, int ql, int qr) {s
    if(r < ql || l > qr) return INT_MAX;  //outside current range; 
    //but how did we get in a range outside? //2*nodes
    //completely inside
    if(ql <= l && r <= qr) return segment_tree[node];

    //partially inside;
    int mid = (l+r)/2;

    return min(query(2*node,l,mid,ql,qr),query(2*node+1,mid+1,r,ql,qr));
}

//updating
void update(int node, int l, int r, int idx, int val) {

    //reached the element
    if(l==r) {
        arr[idx] = val;
        segment_tree[node] = val;
        return;
    }

    //divide into two parts again for efficent search
    int mid = (l + r)/2;

    // find index and go deeper into the tree
    if(idx <= mid) {
        update(2*node,l,mid,idx,val);
    } else {
        update(2*node+1,mid+1,r,idx,val);
    }

    //fix the tree on your way back
    segment_tree[node] = min(segment_tree[2*node],segment_tree[2*node+1]);
}



int main() {

    //input and fast-io
    fast_io;
    read(n);
    read(q);

    arr.resize(n);
    while(auto &a:arr) cin>>a;

    segment_tree.resize(4*n);
    //recursively build the tree
    build(1,0,n-1);



    return 0;
}