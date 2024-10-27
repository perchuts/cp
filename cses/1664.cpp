#include <bits/stdc++.h>
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
const int maxn = 1e6+23;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
    int n, q; cin >> n >> q;
    vector<ii> intr(n);
    vector<vector<int>> st(18, vector<int>(maxn, maxn-1));
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        ckmin(st[0][l], r);
    }
    for (int i = maxn-2; i; --i) ckmin(st[0][i], st[0][i+1]);
    for (int i = 1; i < 18; ++i) {
        for (int j = 0; j < n; ++j) {
            st[i][j] = st[i-1][st[i-1][j]];
        }
    }
    for (int __ = 0, l, r; __ < q; ++__) {
        cin >> l >> r;
        int ans = 0, cur = l;
        for (int i = 17; i >= 0; --i) {
            if (st[i][cur] < r) ans += (1 << i), cur = st[i][cur];
        }
        if (st[0][cur] <= r) ans++;
        cout << ans << endl;
    }   

}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
