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

int solve(int n, int k){
	int turn = 0, cur = n;
	vector<int> prox;
	while ((turn && k > (cur+1)/2) || (!turn && k > cur/2)) {
		prox.pb(turn);
		int nturn = cur % 2;
		if (turn) k -= (cur+1)/2, cur /= 2;
		else k -= cur/2, cur = (cur+1)/2;
		turn ^= nturn;
	}
	reverse(all(prox));
	if (turn) k = 2 * k - 1;
	else k *= 2;
	for (int i = 0; i < sz(prox); ++i) {
		if (prox[i]) {
			k = 2 * k;
		} else {
			k = 2 * k - 1;
		}
	}
	return k;
}

int32_t main(){_
	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}
