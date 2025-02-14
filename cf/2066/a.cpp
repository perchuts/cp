#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
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
    vector<vector<int>> vals(n+1);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        vals[v[i]].pb(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (sz(vals[i]) == 0) {
            cout << "? " << i << " " << (i == 1 ? 2 : 1) << endl;
            int x; cin >> x;
            if (x == 0) {
                cout << "! A" << endl;
            } else {
                cout << "! B" << endl;
            }
            return;
        }
    }
    int i = vals[1][0]+1, j = vals[n][0]+1;
    cout << "? " << i << ' ' << j << endl;
    int x; cin >> x;
    if (x > n-1) {
        cout << "! B" << endl;
        return;
    }
    if (x < n-1) {
        cout << "! A" << endl;
        return;
    }
    cout << "? " << j << ' ' << i << endl;
    cin >> x;
    if (x == 0) {
        cout << "! A" << endl;
    } else {
        cout << "! B" << endl;
    }
}

int32_t main(){_
    int t = 1; cin >> t;
    while(t--) solve();
}
