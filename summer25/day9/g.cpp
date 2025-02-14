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
	vector<int> nim(n+1);
	vector<int> freq(231);
	for (int i = 3; i <= n; ++i) {
		vector<int> foi(512);
		for (int j = 1; j < i; ++j) {
			if (j + j == i) continue;
			foi[nim[j]^nim[i-j]] = 1;
		}
		for (int j = 0; ; ++j) {
			if (foi[j] == 0) { nim[i] = j; break; }
		}
		freq[nim[i]]++;
	}
	int ans = 0;
	for (int i = 0; i <= 230; ++i) ans += freq[i] * freq[i];
	for (int i = 0; i <= 230; ++i) cout << i << ' ' << freq[i] << endl;
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
