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
 
int v[maxn], seg[4*maxn];
 
void build(int i,int l,int r){
    if(l==r){
        seg[i] = v[l];
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md);
    build(2*i+1,md+1,r);
    seg[i] = max(seg[2*i],seg[2*i+1]);
}
 
void update(int i,int l,int r,int x,int d){
    if(l>x||r<x)return;
    if(l==r){
        seg[i] -= d;
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,d);
    update(2*i+1,md+1,r,x,d);
    seg[i] = max(seg[2*i],seg[2*i+1]);
}
 
int query(int i,int l,int r,int x){
    if(l==r){
        return seg[i]>=x?l:0;
    }
    int md = (l+r)/2;
    if(seg[2*i]>=x)return query(2*i,l,md,x);
    else return query(2*i+1,md+1,r,x);
}
 
 
int main(){_
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>v[i];
    }    
    build(1,1,n);
    for(int i=1;i<=m;++i){
        int x;cin>>x;
        int res = query(1,1,n,x);
        cout<<res<<" \n"[i==m];
        if(res)update(1,1,n,res,x);
    }
}
