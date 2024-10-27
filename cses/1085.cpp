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
 
ll v[maxn];
int n,k;
bool possible(ll x){
    int i = 1, cur = 1;
    ll sum = 0;
    while(i<=n){
        if(v[i]>x)return 0;
        sum += v[i];
        if(sum>x)++cur, sum = v[i];
        ++i;
    }
    return cur<=k;
}
 
int main(){_
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>v[i];
    if(k==1){
        ll ans = 0;
        for(int i=1;i<=n;++i)ans += v[i];
        cout<<ans<<endl;
        return 0;
    }
    ll l = 0, r = 1e15, ans;
    while(l<=r){
        ll md = l + (r-l+1ll)/2;
        if(possible(md))ans = md, r = md-1ll;
        else l = md+1ll;
    }
    cout<<ans<<endl;
}
