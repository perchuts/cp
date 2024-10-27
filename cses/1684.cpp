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
bool vis[maxn], can[maxn];
int cmp[maxn], cur;
 
void dfs(int u){
    vis[u] = 1;
    for(auto v:gr[u]) if(!vis[v]) dfs(v);
    order.pb(u);
}
 
void dfs2(int u){
    cmp[u] = cur;
    for(auto v:g[u]) if(!cmp[v]) dfs2(v);
}
 
void dfs3(int u){
    vis[u] = 1, can[u^1] = 0;
    for(auto v:g[u]) if(!vis[v]) dfs3(v);
}
 
int main(){_
    int n,m;cin>>n>>m;
    swap(n,m);
 
    for(int i=1;i<=m;++i){
        bool a,b;int x,y;char op;cin>>op>>x;
        a = (op=='-');
        cin>>op>>y;
        b = (op=='-');
        x *= 2, y *= 2;
        g[x^a^1].pb(y^b), g[y^b^1].pb(x^a);
        gr[b^y].pb(x^a^1), gr[a^x].pb(y^b^1);
    }    
 
    for(int i=2;i<=2*n+1;++i) if(!vis[i]) dfs(i);
 
    reverse(all(order));
 
    for(int i=0;i<2*n;++i){
        int u = order[i];
        if(!cmp[u]) ++cur, dfs2(u);
    }
 
    bool possible = 1;
 
    for(int i=2;i<=2*n;i+=2){
        possible &= cmp[i] != cmp[i^1];
    }
 
    if(!possible) cout<<"IMPOSSIBLE"<<endl;
    else{
        //find any possible truth assignment.
        for(int i=2;i<=2*n+1;++i) can[i] = 1, vis[i] = 0;
 
        for(int i=0;i<2*n;++i){
            int u = order[i];
            if(!vis[u]&&can[u]) dfs3(u);
        }
 
        for(int i=1;i<=n;++i){
            cout<<(vis[2*i]?"+ ":"- ");
        }
 
        cout<<endl;
    }
}
