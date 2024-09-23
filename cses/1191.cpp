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
	vector<int> v(2*n), p(2*n+1);
	for (int i = 0; i < n; ++i) cin >> v[i], v[i+n] = v[i];
	for (int i = 1; i <= 2*n; ++i) p[i] = p[i-1] + v[i-1];
	vector bl(20, vector(2*n+2, 0));
	for (int i = 0; i < 20; ++i) bl[i][2*n+1] = 2*n+1;
	for (int i = 1; i <= 2*n; ++i) {
		int l = i, r = 2*n;
		while (l <= r) {
			int md = l + (r-l+1)/2;
			if (p[md] - p[i-1] <= k) bl[0][i] = l = md+1;
			else r = md-1;
		}
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= 2*n; ++j) {
			bl[i][j] = bl[i-1][bl[i-1][j]];
		}
	}
	int ans = n;
	for (int i = 1; i <= n; ++i) {
		int cur = i, cur_ans = 0;
		for (int j = 19; j >= 0; --j) {
			if (bl[j][cur] < i + n) cur_ans += (1 << j), cur = bl[j][cur];
		}
		ckmin(ans, cur_ans+1);
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
