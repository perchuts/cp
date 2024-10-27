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
const int logn = 20;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int par[maxn][logn], lvl[maxn];
 
vector<int>g[maxn];
 
void dfs(int u,int p){
    par[u][0] = p, lvl[u] = lvl[p]+1;
    for(int i=1;i<logn;++i){
        if(par[u][i-1])par[u][i] = par[par[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v!=p)dfs(v,u);
    }
}
 
int lca(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    int dist = 0;
    for(int i=logn-1;~i;--i){
        if(lvl[par[u][i]]>=lvl[v])u = par[u][i], dist += (1<<i);
    }
    if(u==v)return dist;
    for(int i=logn-1;~i;--i){
        if(par[u][i]!=par[v][i])u = par[u][i], v = par[v][i], dist += (1<<(i+1));
    }
    return dist+2;
}
 
int main(){_
    int n,q;cin>>n>>q;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1,0);
    while(q--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}
