#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int ll
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
void solve(){
    int n; cin >> n;
    int ans = 1e18;
    vector<int> v(n), pos(n);
    for (auto& x : v) cin >> x;
    iota(all(pos), 0); sort(all(pos), [&] (int a, int b) {
        return v[a] < v[b];
    });
    for (auto& x : pos) ++x;
    for (int i = 0; i < n; ++i) v[pos[i]-1] = i+1;
    vector<int> bit(n+1);
    auto insert = [&] (int x) {
        while (x <= n) bit[x]++, x += x&(-x);
    };      
    auto query = [&] (int x) {
        int a = 0;
        while (x) {
            a += bit[x];
            x -= x & (-x);
        }
        return a;
    };
    auto clean = [&] () {
        for (int i = 1; i <= n; ++i) bit[i] = 0;
    };        
	for (int i = 0; i < n; ++i) ans += query(v[i]), insert(v[i]);
	clean();
	ans = min(ans, n * (n-1) / 2 - ans);
    cout << ans << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
