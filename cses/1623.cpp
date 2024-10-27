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
 
ll v[maxn];
int main(){_
    int n;cin>>n;
    ll tot = 0, ans = 1e10;
    for(int i=1;i<=n;++i)cin>>v[i], tot += v[i];    
 
    for(int i=0;i<(1<<n);++i){
        ll cur = 0;
        for(int j=0;j<n;++j)cur += ((i>>j)&1)?v[j]:0;
        ckmin(ans,abs(2*cur-tot));
    }
    
    cout<<ans<<endl;
}
