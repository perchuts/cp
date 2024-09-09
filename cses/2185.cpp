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

void solve(){
 	int n, k; cin >> n >> k;
	vector<int> p(k);
	for (auto& x : p) cin >> x;
	int ans = 0;
	for (int i = 1; i < (1 << k); ++i) {
		int num = 1, ok = 1;
		for (int j = 0; j < k; ++j) {
			if (i >> j & 1) {
				if (p[j] > n / num) {
					ok = 0; break;
				}
				num *= p[j];
			}
		}
		if (ok == 0) continue;
		if (__builtin_popcount(i)&1) ans += n / num;
		else ans -= n / num;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
