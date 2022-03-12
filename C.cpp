#include <iostream>
#include <bits/stdc++.h>
using namespace  std;
#define int long long int

struct Tree{
    int lb, rb;
    int mx = 0, mn=0,  metka1=-1e10;
    Tree *l = 0, *r = 0;
    Tree (int _lb, int _rb) {
        lb = _lb, rb = _rb;
        if (lb + 1 < rb) {
            int t = (lb + rb) / 2;
            l = new Tree(lb, t);
            r = new Tree(t, rb);
        }
    }
    void add (int k, int x) {
        if (l) {
            if (k < l->rb)
                l->add(k, x);
            else
                r->add(k, x);
            mn = min(r->mn, l->mn);
            mx = max(r->mx, l->mx);
        }
        else mn=mx=x;
    }
    int get_min (int lq, int rq) {
        if (lb >= lq && rb <= rq)
            return mn;
        if (max(lb, lq) >= min(rb, rq))
            return 1e9;
        return min(l->get_min(lq, rq) , r->get_min(lq, rq));
    }
    int get_max (int lq, int rq) {
        if (lb >= lq && rb <= rq)
            return mx;
        if (max(lb, lq) >= min(rb, rq))
            return -1e9;
        return max(l->get_max(lq, rq) , r->get_max(lq, rq));
    }
};


void solve(){
    int n, m;
    cin>>n>>m;
    Tree tree(0, n);
    while(m--){
        int x;
        cin>>x;
        if(x==1){
            int a, b;
            cin>>a>>b;
            cout<<tree.get_max(a-1, b) - tree.get_min(a-1, b)<<endl;
        }
        else{
            int a,c;
            cin>>a>>c;
            tree.add(a-1, c);
        }
    }
    





};




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef _MY
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while (t--){
        solve();
    }


}

