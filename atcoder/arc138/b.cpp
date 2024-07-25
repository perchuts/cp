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
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	if (v[0] != 0) {
		cout << "No" << endl;
		return;
	}
	vector<int> suf(n);
	for (int i = n - 2; i >= 0; --i) suf[i] = suf[i+1] + (v[i] != v[i+1]);
 	for (int i = 0; i < n; ++i) {
		// vou fazer i + 1 operacoes do segundo tipo
		if (i == n - 1) {
			cout << "Yes" << endl;
			return;
		}
		int need = suf[i+1] + v.back();
		if (i+1 >= need) {
			cout << "Yes" << endl;
			return;
		}
		if (i != n - 1 && v[i+1] == v[i]) break;
	}
	cout << "No" << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
