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

void printGame(vector<int> v) {
    vector<char> cc = {'A', 'B', '.'};
    for (auto z : v) cout << cc[z];
    cout << endl;
}

vector<vector<int>> solve(int n, string s){
    vector<int> v;
    for (int i = 0; i < 2*n; ++i) {
        char c = s[i];
        if (c == 'A') v.pb(0);
        else if (c == 'B') v.pb(1);
        else v.pb(2);
    }
    if (n <= 3) {
        map<vector<int>, vector<int>> mv;
        queue<vector<int>> q;
        q.push(v), mv[v] = v;
        while (!q.empty()) {
           auto vv = q.front();
           q.pop();
           int a = -1, b = -1;
           for (int i = 0; i < 2*n; ++i) {
                if (vv[i] == 0) a = i;
                if (b == -1 and vv[i] == 1) b = i;
           }
           if (a <= b) {
                vector<vector<int>> ans;
                while (vv != v) {
                    ans.pb(vv);
                    vv = mv[vv];
                }
                reverse(all(ans));
                return ans;
           }
           auto in = vv;
           int pos = -1;
           for (int j = 0; j < 2 * n; ++j) {
               if (in[j] == 2) {
                   assert(in[j+1] == 2);
                   pos = j;
                   break;
               }
           }
           assert(pos != -1);
           for (int j = 0; j < 2*n - 1; ++j) {
               if (in[j] != 2 and in[j+1] != 2) {
                   auto in2 = in;
                   in2[j] = in2[j+1] = 2;
                   in2[pos] = in[j], in2[pos+1] = in[j+1];
                   if (!mv.count(in2)) mv[in2] = in, q.push(in2);
               }
           }
        }
        cout << -1 << endl;
        exit(0);
    }
    else {
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
                        if (v[j-1] == 2) move(2*n-5);
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
            move(n-3), move(n-1);
        } else if (pos == 2*n-1) {
           if (v[2*n-2] == 2) move(2*n-5);
           move(2*n-2);
           for (int j = n; j < 2*n; ++j) if (v[j] == 0) pos = j;
           move(n-2), move(pos);
        } else {
            move(n-2), move(pos);
        }
        return moves;
    }
    return vector<vector<int>>();
}

int32_t main(){_
    int n; cin >> n;
    string s; cin >> s;
    auto ans = solve(n, s);
    cout << sz(ans) << endl;
    for (auto x : ans) printGame(x);
}
