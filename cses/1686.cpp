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
 
ll v[maxn], v2[maxn], dp[maxn];
 
vector<int>g[maxn], gr[maxn], order, g2[maxn];
 
int cmp[maxn], vis[maxn], cur, in[maxn];
 
void dfs(int u){
    vis[u] = 1;
    for(auto v:gr[u])
        if(!vis[v]) dfs(v);
    order.pb(u);
}
 
void dfs2(int u){
    cmp[u] = cur;
    for(auto v:g[u]){
        if(!cmp[v]) dfs2(v);
    }
}
 
int main(){_
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i];    
    
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), gr[v].pb(u);
    }
 
    for(int i=1;i<=n;++i)
        if(!vis[i]) dfs(i);
    
    reverse(all(order));
 
    for(auto u:order){
        if(!cmp[u]) ++cur, dfs2(u);
    }
 
    for(int i=1;i<=n;++i){
        int act = cmp[i];
        v2[act] += v[i];
        for(auto x:g[i]){
            if(cmp[x]!=act)g2[cmp[x]].pb(act);
        }
    }
 
    queue<int>q;
 
    for(int i=1;i<=cur;++i){
        
        sort(all(g2[i]));
        g2[i].erase(unique(all(g2[i])), end(g2[i]));
        for(auto x:g2[i])in[x]++;
        vis[i] = 0, dp[i] = v2[i];
    }
 
    for(int i=1;i<=cur;++i)
        if(!in[i]) q.push(i);
 
    ll ans = 0;
 
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        ckmax(ans, dp[u]);
        for(auto v:g2[u]){
            --in[v];
            ckmax(dp[v], dp[u] + v2[v]);
            if(!in[v])q.push(v);
        }
    }
 
    cout<<ans<<endl;
}   
