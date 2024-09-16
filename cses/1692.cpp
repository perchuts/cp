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

vector<int> de_brujin(int n, int k, int lim) {
	vector<int> l = {0}, ret; // l eh lyndon word
	while (true) {
		if (l.size() == 0) {
			l.push_back(0);
		}
		if (n % l.size() == 0) for (int i : l) {
			ret.push_back(i);
			if (ret.size() == n+lim-1) return ret;
		}
		int p = l.size();
		while (l.size() < n) l.push_back(l[l.size()%p]);
		while (l.size() and l.back() == k-1) l.pop_back();
		if (l.size()) l.back()++;
	}
	return ret;
}
void solve(){
 	int n; cin >> n;
	auto ans = de_brujin(n, 2, (1<<n));
	for (auto x : ans) cout << x;
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
