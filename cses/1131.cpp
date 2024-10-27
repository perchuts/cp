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
bool vis[maxn];
int dist[maxn];
int main(){_
    int n;cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }    
    queue<int>q;
    int best = 1;
    q.push(1);
    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = 1, best = u;
        for(auto v:g[u]){
            if(!vis[v])q.push(v);
        }
    }
    q.push(best);
    int ans = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        ckmax(ans,dist[u]);
        for(auto v:g[u]){
            if(!dist[v]&&v!=best){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    cout<<ans<<endl;
}
