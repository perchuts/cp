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
bool mark[maxn][2];
int dfs(int u,int p,bool mode){
    if(mark[u][mode])return dp[u][mode];
    mark[u][mode] = 1;
    if(mode){
        dp[u][1] = 1;
        for(auto v:g[u])if(v!=p)dp[u][1] += dfs(v,u,0);
    }else{
        int tot = 0;
        for(auto v:g[u])tot += dfs(v,u,0);
        dp[u][0] = tot;
        for(auto v:g[u]){
            if(v==p)continue;
            int cur = dfs(v,u,0);
            ckmax(dp[u][0], tot - cur + dfs(v,u,1));
        }
    }
    return dp[u][mode];
}   
 
int main(){_
    int n;cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }    
    cout<<dfs(1,1,0)<<endl;    
    // for(int i=1;i<=n;++i)cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
}
