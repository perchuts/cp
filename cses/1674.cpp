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
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int subt[5*maxn];
vector<int>g[5*maxn];
 
int dfs(int u,int p){
    subt[u] = 0;
    for(auto v:g[u]){
        if(v==p)continue;
        subt[u] += dfs(v,u)+1;
    }
    return subt[u];
}
int main(){_
    int n;cin>>n;
    for(int i=2;i<=n;++i){
        int x;cin>>x;
        g[x].pb(i), g[i].pb(x);
    }    
    dfs(1,1);
    for(int i=1;i<=n;++i)cout<<subt[i]<<" \n"[i==n];
}
