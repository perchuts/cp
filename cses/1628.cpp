#include <bits/stdc++.h>
// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
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
 
void solve(){
 	int n, x; cin >> n >> x;
	vector<int> v(n), vv;
	for (auto& y : v) cin >> y;
	ll ans = 0;
	for (int i = 1; i < (1 << n/2); ++i) {
		int s = 0;
		for (int j = 0; j < n/2; ++j) {
			if ((i>>j)&1) s += v[j];
			if (s > x) break;
		}
		if (s > x) continue;
		if (s == x) { ans++; continue; }
		vv.pb(s);
	}
	sort(all(vv));
	vector<ii> vv2;
	for (int i = 0, j = 0; i < sz(vv); i = j) {
		while (j != sz(vv) and vv[i] == vv[j]) j++;
		vv2.pb({vv[i], j-i});
	}
	for (int i = 1; i < (1<<(n-n/2)); ++i) {
		int s = 0;
		for (int j = 0; j < n-n/2; ++j) {
			if ((i>>j)&1) s += v[n/2+j];
			if (s > x) break;
		}
		if (s > x) continue;
		if (s == x) { ans++; continue; }
		int l = 0, r = sz(vv2)-1, a = -1;
		while (l <= r) {
			int md = l + (r-l+1)/2;
			if (vv2[md].first <= x-s) a = md, l = md+1;
			else r = md-1;
		}
		if (a != -1 and vv2[a].first == x-s) ans += vv2[a].second;
	}
	cout << ans << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
