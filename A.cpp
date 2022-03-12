#include <iostream>
#include <bits/stdc++.h>
using namespace  std;
#define int long long int

struct Tree{
    int lb, rb;
    int sum = 0, metka=0;
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
        sum += x;
        if (l) {
            if (k < l->rb)
                l->add(k, x);
            else
                r->add(k, x);
        }
    }
    /*void push(){
        if(metka){
            mn+=metka;
            if(l){
                l->metka+=metka;
                r->metka+=metka;
            }
        }
        metka=0;
    }*/
    /*void upd (int lq, int rq, int x) {
        if (lq <= lb && rb <= rq){
            metka += x;
            push();
        }
        else if (l && max(lb, lq) < min(rb, rq)) {
            l->upd(lq, rq, x);
            r->upd(lq, rq, x);
            mn=min(l->mn, r->mn);
        }
    }*/
    void upd(int k, int x){
        if (l) {
            if (k < l->rb)
                l->upd(k, x);
            else
                r->upd(k, x);
            sum=l->sum+r->sum;
        }
        else sum=x;

    }
    int get_sum (int lq, int rq) {
        if (lb >= lq && rb <= rq)
            return sum;
        if (max(lb, lq) >= min(rb, rq))
            return 0;
        return l->get_sum(lq, rq) + r->get_sum(lq, rq);
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
            cout<<tree.get_sum(a-1, b)<<endl;
        }
        else{
            int a,b;
            cin>>a>>b;
            tree.upd(a-1, b);
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

