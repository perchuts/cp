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
 
vector<int>g[maxn];
 
ll dp[maxn][2], subt[maxn], n;
 
ll dfs1(int u,int p){
    subt[u] = 1ll;
    for(auto v:g[u]){
        if(v==p)continue;
        dp[u][0] += dfs1(v,u);
        subt[u] += subt[v];
    }
    dp[u][0] += subt[u] - 1ll;
    return dp[u][0];
}
 
void dfs2(int u,int p){
    if(u!=p)dp[u][1] = dp[p][1] + dp[p][0] - dp[u][0] - subt[u] + (n - subt[u]);
    for(auto v:g[u]){
        if(v==p)continue;
        dfs2(v,u);
    }
}
 
int main(){_
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }    
    dfs1(1,1);dfs2(1,1);
    for(int i=1;i<=n;++i){
        cout<<dp[i][0]+dp[i][1]<<" \n"[i==n];
    }
}
