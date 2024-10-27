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
 
ll v[maxn], seg[4*maxn];
vector<int>g[maxn];
ii tempo[maxn];
int t, n, q, quem[maxn];
 
int dfs(int u,int p){
    tempo[u].first = ++t, quem[t] = u;
    int fim = t;
    for(auto v:g[u]){
        if(v==p)continue;
        fim = dfs(v,u);
    }
    return tempo[u].second = fim;
}
 
void build(int i,int l,int r){
    if(l==r){
        seg[i] = v[quem[l]];
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md), build(2*i+1,md+1,r);
    seg[i] = seg[2*i]+seg[2*i+1];
}
 
void update(int i,int l,int r,int x,ll d){
    if(l>x||r<x)return;
    if(l==r){
        seg[i] = d;
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,d), update(2*i+1,md+1,r,x,d);
    seg[i] = seg[2*i]+seg[2*i+1];
}
 
ll query(int i,int l,int r,int x,int y){
    if(l>y||r<x)return 0;
    if(x<=l&&r<=y)return seg[i];
    int md = (l+r)/2;
    return query(2*i,l,md,x,y) + query(2*i+1,md+1,r,x,y);
}
 
 
int main(){_
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
 
    dfs(1,1);
    build(1,1,n);
 
    while(q--){
        int op;cin>>op;
        if(op==1){
            int u;ll x;cin>>u>>x;
            update(1,1,n,tempo[u].first,x);
        }else{
            int u;cin>>u;
            cout<<query(1,1,n,tempo[u].first,tempo[u].second)<<endl;
        }
    }
    
}
