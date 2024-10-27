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
 
int subt[maxn], n;
vector<int>g[maxn];
 
int dfs(int u,int p){
    subt[u] = 1;
    for(auto v:g[u]){
        if(v==p)continue;
        subt[u] += dfs(v,u);
    }
    return subt[u];
}
 
int centroid(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        if(subt[v]>n/2)return centroid(v,u);
    }
    return u;
}
 
int main(){_
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }    
    dfs(1,1);
    cout<<centroid(1,1)<<endl;
}
