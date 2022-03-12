#include <iostream>
#include <bits/stdc++.h>
using namespace  std;
#define int long long int

struct Tree{
    int lb, rb;
    int sum=0,  metka1=-1e10;
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
    int n, k;
    cin>>n>>k;
    int ans=0;
    Tree tree(0, n);
    while(k--){
        
        for(int i=0; i<n; i++){
            tree.add(i, 1);
        }
        vector<int> mas(n, 1);
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            tree.add(a-1, 0);
            ans+=tree.get_sum(0, a-1);
        }
    }
    cout<<ans<<endl;
    
    





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

