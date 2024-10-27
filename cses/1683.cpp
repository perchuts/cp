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
const int maxn = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
vector<int>g[maxn], gr[maxn], order;
 
int k, kingdom[maxn];
 
bool vis[maxn];
 
void dfs(int u){
    vis[u] = 1;
    for(auto v:gr[u])
        if(!vis[v]) dfs(v);
    order.pb(u);
}
 
void dfs2(int u){
    kingdom[u] = k, vis[u] = 1;
    for(auto v:g[u])
        if(!kingdom[v]) dfs2(v);
}
 
int main(){_
    int n,m;cin>>n>>m;
 
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), gr[v].pb(u);
    }
 
    // 1 -> 2 -> 3 -> 4 -> 5
    // |----<----|    |-<--|
 
    // 1 <- 2 <- 3 <- 4 <- 5
    // |---->----|    |->--|
 
    for(int i=1;i<=n;++i)
        if(!vis[i]) dfs(i);
 
    reverse(all(order));
 
    for(int i=0;i<n;++i)
        if(!kingdom[order[i]]) ++k, dfs2(order[i]);
 
    cout<<k<<endl;
    
    for(int i=1;i<=n;++i)cout<<kingdom[i]<<" \n"[i==n];
}
