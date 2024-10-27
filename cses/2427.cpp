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
    vector<char> cc = {'A', 'B', '.'};
    auto printGame = [&] (vector<int> v) {
        for (auto z : v) cout << cc[z];
        cout << endl;
    };
    vector<int> v;
    for (int i = 0; i < 2*n; ++i) {
        char c; cin >> c;
        if (c == 'A') v.pb(0);
        else if (c == 'B') v.pb(1);
        else v.pb(2);
    }
    if (n <= 3) {

    } else {
        vector<vector<int>> moves;
        auto move = [&] (int x) {
            for (int i = 0; ; ++i) {
                if (v[i] == 2) {
                    swap(v[i], v[x]), swap(v[i+1], v[x+1]);
                    moves.pb(v);
                    return;
                }
            }
            assert(false);
        };
        for (int i = 0; i < n-2; ++i) {
            if (v[i] == 2 or v[i+1] == 2) move(2*n-2);
            if (v[i] == 0) continue;
            assert(v[i] == 1);
            for (int j = i+2; ; ++j) {
                if (v[j] == 0) {
                    if (j == 2*n-1) {
                        move(2*n-2);
                        j = i+1;
                        continue;
                    }
                    move(i);
                    move(j);
                    break;
                }
            }
        }
        if (v[n-2] == 2 or v[n-1] == 2) move(2*n-2);
        int pos = 0;
        for (int j = n-2; j < 2*n; ++j) {
            if (v[j] == 0) pos = j;
        }
        // caso 1: pos == n-2
        // nesse caso, ganhamos de graca!
        if (pos == n-2) {
            // win
        } else if (pos == n-1) {
            // ABA
            int space = -1;
            for (int j = n; j < 2*n; ++j) {
                if (v[j] == 2) {
                    space = j;
                    break;
                }
            }
            assert(space != -1);
            if (space == n) {}
            else if (space == n+1) move(2*n-2), move(n);
            else move(n); 
            move(n-2);
            move(n-1);
        } else if (pos == 2*n-1) {
           move(2*n-2);
           for (int j = n; j < 2*n; ++j) if (v[j] == 0) pos = j;
           move(n-2), move(pos);
        } else {
            move(n-2), move(pos);
        }
        cout << sz(moves) << endl;
        for (auto x : moves) printGame(x); 
    }
}

int32_t main(){_
    solve();
    return 0;
    vector<vector<vector<int>>> inputs(10);
    const int LIM = 6;
    vector<int> pot(3*LIM, 1);
    vector<char> cc = {'A', 'B', '.'};
    auto printGame = [&] (vector<int> v) {
        for (auto z : v) cout << cc[z];
        cout << endl;
    };
    for (int i = 1; i < 3*LIM; ++i) pot[i] = pot[i-1] * 3;
    for (int i = 1; i <= LIM; ++i) {
        for (int j = 0; j < pot[2*i+2]; ++j) {
            vector<int> vals;
            int a = 0, b = 0, cur = j, prev = -1, ok = 0;
            for (int k = 0; k < 2 * i + 2; ++k) {
                if (cur % 3 == 0) a++;
                else if (cur % 3 == 1) b++;
                vals.pb(cur%3);
                if (prev == 2 and cur % 3 == 2) ok = 1;
                prev = cur % 3, cur /= 3;
            }
            if (a == b and a == i and ok) inputs[i].pb(vals);
        }
    }
    map<vector<int>, int> dist;
    map<vector<int>, vector<int>> mv;
    for (int i = 1; i <= LIM; ++i) {
        queue<vector<int>> q;
        for (auto in : inputs[i]) {
            int a = 0, b = -1;
            for (int j = 0; j < 2 * i + 2; ++j) {
                if (in[j] == 0) a = j;
                if (in[j] == 1 and b == -1) b = j; 
            }
            assert(b != -1);
            if (a <= b) q.push(in), dist[in] = 0;
        }
        while (!q.empty()) {
            auto in = q.front();
            q.pop();
            int pos = -1;
            for (int j = 0; j < 2 * i + 1; ++j) {
                if (in[j] == 2) {
                    assert(in[j+1] == 2);
                    pos = j;
                    break;
                }
            }
            assert(pos != -1);
            for (int j = 0; j < 2 * i + 1; ++j) {
                if (in[j] != 2 and in[j+1] != 2) {
                    auto in2 = in;
                    in2[j] = in2[j+1] = 2;
                    in2[pos] = in[j], in2[pos+1] = in[j+1];
                    if (!dist.count(in2)) dist[in2] = dist[in]+1, q.push(in2), mv[in2] = in;
                }
            }
        }
    }
    cout << "end" << endl;
    int tt; cin >> tt;
    for (int __ = 0; __ < tt; ++__) {
        int n = rnd(1, LIM), x = rnd(0, sz(inputs[n])-1);
        auto cur = inputs[n][x];
        cout << n+1 << endl;
        printGame(cur);
        if (dist.count(cur) == false) {
            cout << "Impossible" << endl;
        } else {
            cur = mv[cur];
            while (dist.count(cur)) printGame(cur), cur = mv[cur];
        }
        cout << endl;
    }
}
