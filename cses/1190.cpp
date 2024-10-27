#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 2e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
vector<ll>v;
struct node{
    ll tot, pr, suf, best;
}seg[4*maxn];
 
int n,m;
 
void upd(int i){
    node l = seg[2*i], r = seg[2*i+1];
    seg[i].pr = max(l.pr,l.tot+r.pr);
    seg[i].suf = max(r.suf,r.tot+l.suf);
    seg[i].best = max({l.best,r.best,l.suf+r.pr,seg[i].pr,seg[i].suf});
    seg[i].tot = l.tot+r.tot;
}
 
void build(int i=1,int l=1,int r=n){
    if(l==r){
        seg[i].tot = v[l], seg[i].best =  seg[i].pr = seg[i].suf = max(0ll,v[l]);
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md);build(2*i+1,md+1,r);
    upd(i);
}
 
void update(int i,int l,int r,int x,ll y){
    if(l>x||r<x)return;
    if(l==r){
        seg[i].tot = y, seg[i].best =  seg[i].pr = seg[i].suf = max(0ll,y);
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,y);update(2*i+1,md+1,r,x,y);
    upd(i);
}
 
 
int main(){_
    cin>>n>>m;
    v.resize(n+1);
    for(int i=1;i<=n;++i)cin>>v[i];
    build();
    for(int i=1;i<=m;++i){
        int idx;ll x;cin>>idx>>x;
        update(1,1,n,idx,x);
        cout<<seg[1].best<<endl;
    }
}
