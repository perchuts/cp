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
 
ll v[maxn], n, t;
 
bool impossible(ll x){
    ll tot = 0;
    for(int i=1;i<=n;++i){
        tot += x/v[i];
        if(tot>=t)return 0;
    }
    return 1;
}
 
int main(){_    
    cin>>n>>t;
    for(int i=1;i<=n;++i)cin>>v[i];
    ll l = 1ll, r = 1e18+10ll;
    while(l<r){
        ll md = (l+r)/2;
        if(impossible(md))l = md+1ll;
        else r = md;
    }
    cout<<r<<endl;
}
