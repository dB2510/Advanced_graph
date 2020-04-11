#include<bits/stdc++.h>
using namespace std;

// ZERO BASED INDEXING

struct fenwikTree {
    // Seperate array to construct bit and store fenwik tree
    vector<int>bit;
    int n; // Size of tree

    fenwikTree(int n){
        this->n = n;
        bit.assign(n,0); // Assigning all the elements to 0
    }

    fenwikTree(vector<int>a) : fenwikTree(a.size()) {
        for(int i=0;i<a.size();i++) 
        add(i,a[i]);
    }

    int sum(int r) {
        int ret=0;
        for(;r>=0;r=(r&(r+1)) - 1)
        ret+=bit[r];
        return ret;
    }

    int sum(int l,int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx,int delta) {
        // Here what we are doing is that the data from 
        // the input array will be stored in bit[its index's least unset bit]
        // for example: arr[1] will be in bit[1],bit[3],bit[7]...
        // arr[2] will be in bit[2], bit[3], bit[7]...
        for(;idx<n;idx = idx | (idx+1))
        bit[idx] += delta;
    }
};

struct fenwikTreeMin {
    vector<int>bit;
    int n;
    const int INF = (int)1e9;

    fenwikTreeMin(int n) {
        this->n = n;
        bit.assign(n,INF);
    }

    fenwikTreeMin(vector<int>a) : fenwikTreeMin(a.size()) {
        for(int i=0;i<a.size();i++)
        update(i,a[i]);
    }

    int getMin(int r) { 
        int ret=INF;
        for(;r>=0;r=(r&(r+1))-1)
        ret=min(ret,bit[r]);
        return ret;
    }

    void update(int idx,int val) {
        for(;idx<n;idx=idx | (idx+1))
        bit[idx]=min(bit[idx],val);
    }
};

// ONE BASED INDEXING

struct fenwikTreeOneBased {
    vector<int>bit;
    int n;

    fenwikTreeOneBased(int n) {
        this->n = n+1;
        bit.assign(n+1,0);
    }

    fenwikTreeOneBased(vector<int>a) : fenwikTreeOneBased(a.size()) {
        for(int i=0;i<a.size();i++)
        add(i,a[i]);
    }

    int sum(int r) {
        int ret=0;
        for(++r;r>0;r-=(r&(-r)))
        ret+=bit[r];
        return ret;
    }

    // Range query
    int sum(int l,int r)
    {
        return sum(r) - sum(l-1);
    }

    // Point Update
    void add(int idx,int delta) {
        for(++idx;idx<n;idx+=(idx&(-idx)))
        bit[idx]+=delta;
    }

    // Point Query
    int point_query(int idx) {
        int ret=0;
        for(++idx; idx>0 ; idx-=(idx&(-idx)))
        ret+=(bit[idx]);
        return ret;
    }

    // Range sum
    void range_sum(int l,int r,int val)
    {
        add(l, val);
        add(r+1, -val);
    }
};

int main() {
    int n=5;
    fenwikTreeOneBased fen(n);
    fen.range_sum(0,3,5);
    cout<<fen.point_query(3)<<endl;
}