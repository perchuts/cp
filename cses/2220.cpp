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
	int a, b; cin >> a >> b;
	auto calc = [] (int x) -> int {
		if (x < 0) return 0ll;
		vector<int> digits;
		int cur = x;
		while (cur) digits.pb(cur % 10), cur /= 10;
		reverse(all(digits));
		int lst = -1, ans = 0, pt = 1;
		for (int i = 0; i < sz(digits); ++i) ans += pt, pt *= 9;
		for (int i = 0; i <= sz(digits); ++i) {
			if (i == sz(digits)) {
				ans++;
				break;
			}
			int tmp = digits[i] - (lst < digits[i]);
			for (int j = i+1; j < sz(digits); ++j) tmp *= 9;
			ans += tmp;
			if (digits[i] == lst) break;
			lst = digits[i];
		}		
		return ans;
	};
	cout << calc(b) - calc(a-1) << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
