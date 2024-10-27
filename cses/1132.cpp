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
int dp[maxn][2];
//calcula descendo
int dfs1(int u,int p){
    int best = 0;dp[u][0] = 0;
    for(int i=0;i<sz(g[u]);++i){
        int v = g[u][i];
        if(v==p)continue;
        dp[v][1] = dp[u][0]+1;
        ckmax(dp[u][0], dfs1(v,u)+1);
    }
    for(int i=sz(g[u])-1;i>=0;--i){
        int v = g[u][i];
        if(v==p)continue;
        ckmax(dp[v][1], best+1);
        ckmax(best,dp[v][0]+1);
    }
    return dp[u][0];
}
 
void dfs2(int u,int p){
    if(u!=p)ckmax(dp[u][1], dp[p][1]+1);
    for(auto v:g[u]){
        if(v==p)continue;
        dfs2(v,u);
    }
}
 
int main(){_
    int n;cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }    
    dfs1(1,1);dfs2(1,1);
    for(int i=1;i<=n;++i)cout<<max(dp[i][0],dp[i][1])<<" \n"[i==n];
}
