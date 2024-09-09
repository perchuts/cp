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
	int n, a, b; cin >> n >> a >> b;
	vector p(n+1, vector(6*n+1, 0.0));
	p[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 6 * i; ++j) {
			for (int val = 1; val <= min(j, 6ll); ++val) {
				p[i][j] += p[i-1][j-val];
			}
			p[i][j] /= 6.0;
		}
	}
	double ans = 0;
	for (int i = a; i <= b; ++i) ans += p[n][i];
	cout << fixed << setprecision(6) << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
