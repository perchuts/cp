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
    vector<int> vals(5);
    for (auto& x : vals) cin >> x;
    int K = 1001;
    vector dp(K+1, vector(32, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= K-200; ++i) {
        for (int j = 0; j < 32; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (i % 10 == 0) for (int k = 0; k < 5; ++k) {
                if (j >> k & 1) {}
                else dp[i+vals[k]][j+(1<<k)] |= dp[i][j];
            }
        }
    }
    for (int i = 1; ; ++i) {
        if (dp[i][31]) {
            cout << i << endl;
            exit(0);
        }
    }
}

int32_t main(){_
    int t = 1; //cin >> t;
    while(t--) solve();
}
