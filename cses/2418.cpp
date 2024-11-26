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
	int n, m, x1, y1, x2, y2; cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	--x1, --y1, --x2, --y2;
	ii st = {x1, y1}, en = {x2, y2};
	int par = (n*m)%2, p1 = (x1+y1)%2, p2 = (x2+y2)%2;
	// trivial NO
	if ((p1^p2) == par) {
		cout << "NO" << endl;
		return;
	}
	string ans;
	bool rotate90 = 0, reverseAns = 0;
	auto rotate = [&] () {
		rotate90 = 1;
		int nx1 = -y1, ny1 = x1, nx2 = -y2, ny2 = x2;
		x1 = nx1, y1 = ny1, x2 = nx2, y2 = ny2;
		swap(n, m);
	};
	auto checkAnswer = [&] () {
		vector<vector<int>> vis(n, vector<int>(m));
		ii cur = st;
		vis[cur.first][cur.second] = 1;
		for (int i = 0; i < sz(ans); ++i) {
			auto x = ans[i];
			if (x == 'L') cur.second--;
			else if (x == 'R') cur.second++;
			else if (x == 'D') cur.first++;
			else cur.first--;
			if (min(cur.first, cur.second) < 0 or cur.first == n or cur.second == m) {
				cout << "Invalid answer: leaving out of grid on step " << i << endl;
				return;
			}		
			if (vis[cur.first][cur.second]) {
				cout << "Invalid answer: cycling on step " << i << endl;
				return;
			}
			vis[cur.first][cur.second] = 1;
		}
		if (cur != en) {
			cout << "Invalid answer: destination does not coincide with (x2, y2): (" << cur.first << ", " << cur.second << ")" << endl;
		}
	};
	auto printAns = [&] () {
		cout << "YES" << endl;
		if (reverseAns){
			reverse(all(ans));
			for (auto& x : ans) {
				if (x == 'L') x = 'R';
				else if (x == 'R') x = 'L';
				else if (x == 'U') x = 'D'; 
				else x = 'U'; 
			}
		}
		if (rotate90) {
			for (auto& x : ans) {
				if (x == 'L') x = 'U';
				else if (x == 'R') x = 'D';
				else if (x == 'U') x = 'R'; 
				else x = 'L'; 
			}
		}
		checkAnswer();
		cout << ans << endl;
	};
	if (y1 == y2 or ((y1 < y2 and x1 < x2) or (y2 < y1 and x2 < x1))) rotate(); 
	if (y1 > y2) reverseAns = 1, swap(x1, x2), swap(y1, y2);
	if (n == 1) {
		if (y1 != 0 or y2 != m-1) {
			cout << "NO" << endl;
			return;
		}
		ans = string(m-1, 'R');
		printAns();
		return;
	}
	assert(min(n, m) > 1);
	// outro caso NO bem funny
	if (n == 3 and x1 == 1 and y2%2 == 0) {
		cout << "NO" << endl;
		return;
	}

}

int32_t main(){_
  int t = 1; cin >> t;
  while(t--) solve();
}
