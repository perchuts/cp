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
 
ii v[maxn];
 
int main(){_
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>v[i].second>>v[i].first;    
    sort(v+1,v+1+n);
    multiset<int>s;
    for(int i=1;i<=k;++i)s.insert(0);
    int ans = 0;
    for(int i=1;i<=n;++i){
        auto it = s.upper_bound(v[i].second);
        if(it==begin(s))continue;
        it = prev(it), ++ans;
        s.erase(it);
        s.insert(v[i].first);
    }
    cout<<ans<<endl;
}
