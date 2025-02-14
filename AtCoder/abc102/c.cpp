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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int l = -1e10, r = 1e10;
    auto f = [&] (int b) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += abs(a[i-1] - (b+i));
        return ans;
    };
    while (r-l >= 3) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if (f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    int ans = 1e18;
    for (int i = l; i <= r; ++i) ckmin(ans, f(i));
    cout << ans << endl;
}

int32_t main(){_
    int t = 1; //cin >> t;
    while(t--) solve();
}
