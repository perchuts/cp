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
 
ll best[maxn];
 
int main(){_
    int n;cin>>n;
    vector<pair<ii,ll>>v;
    for(int i=1;i<=n;++i){
        ll c;int x,y;cin>>x>>y>>c;
        v.pb({{y,x},c});
    }    
    v.pb({{-inf,-inf},0});
    sort(all(v));
    for(int i=1;i<=n;++i){
        int melhor = upper_bound(all(v),make_pair(make_pair(v[i].first.second-1,inf),ll(0))) - begin(v);
        best[i] = best[i-1]; 
        ckmax(best[i], best[melhor-1]+v[i].second);
    } 
    cout<<best[n]<<endl;
}
