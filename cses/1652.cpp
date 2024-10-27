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
 
ll v[maxn];
 
ll seg[4*maxn], lazy[4*maxn];
int n,q;
void build(int i=1,int l=1,int r=n){
    if(l==r){
        seg[i] = v[l];
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md);build(2*i+1,md+1,r);
    seg[i] = seg[2*i]+seg[2*i+1];
}
 
void flush(int i,int l,int r){
    if(lazy[i]==0)return;
    seg[i] += lazy[i]*ll(r-l+1);
    if(l!=r)lazy[2*i]+=lazy[i],lazy[2*i+1]+=lazy[i];
    lazy[i] = 0;
}
 
void update(int i,int l,int r,int x,int y,ll delta){
    flush(i,l,r);
    if(l>y||r<x)return;
    if(x<=l&&r<=y){
        lazy[i] += delta;
        flush(i,l,r);
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,y,delta);
    update(2*i+1,md+1,r,x,y,delta);
    seg[i] = seg[2*i] + seg[2*i+1];
}
 
ll query(int i,int l,int r,int x){
    flush(i,l,r);
    if(l>x||r<x)return 0;
    if(l==r)return seg[i];
    int md = (l+r)/2;
    return query(2*i,l,md,x) + query(2*i+1,md+1,r,x);
}
 
 
int main(){_
    cin>>n>>q;
 
    for(int i=1;i<=n;++i)cin>>v[i];    
 
    build();
    
    for(int i=1;i<=q;++i){
        int o;cin>>o;
        if(o==1){
            int a,b,u;cin>>a>>b>>u;
            update(1,1,n,a,b,ll(u));
        }else{
            int k;cin>>k;
            cout<<query(1,1,n,k)<<endl;
        }
    }
}
