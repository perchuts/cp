#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast_io cin.tie(0)->sync_with_stdio(0);
#define int ll
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

string to_string(int n, int x) {
	string s;
	for (int i = 0; i < n; i++)
		s += '0' + (x >> i & 1);
	return s;
}

int eval(string s) {
	set<string> st;
	
	int n = s.size();
	for (int mask = 1; mask < (1<<n); mask++) {
		string t;
		for (int i = 0; i < n; i++) if (mask >> i & 1)
			t += s[i];
		st.insert(t);
	}
	
	return st.size();
}

using T = pair<int, int>;

//int fast_eval(string s) {
//	int n = s.size();
//	vector dp(n + 1, 1);
//	auto nxt = get_next(s);
//	dp.push_back(0);
//
//	for (int i = n - 1; i >= 0; --i) {
//		for (int j : {0, 1}) {
//			int to = nxt[i][j];
//			if (to != n) {
//				dp[i] += dp[to + 1];
//			}
//		}
//	0
//
//	return dp[0] - 1;
//}

inline T get_right(int n, int s) {
	vector dp(n + 1, 1);
	dp.push_back(0);

	vector nxt(2, n);
	for (int i = n - 1; i >= 0; --i) {
		if (s >> i & 1) nxt[1] = i;
		else nxt[0] = i;
		for (int j : {0, 1}) {
			if (nxt[j] != n) {
				dp[i] += dp[nxt[j] + 1];
			}
		}
	}

	return T{dp[nxt[0] + 1], dp[nxt[1] + 1]};
}

inline T get_left(int n, int s) {
	vector dp(n + 2, T{0, 0});
	dp[n] = dp[n + 1] = T{1, 1};

	vector nxt(2, n);
	for (int i = n - 1; i >= 0; --i) {
		if (s >> i & 1) nxt[1] = i;
		else nxt[0] = i;

		if (nxt[0] == n) dp[i].first += 1;
		else {
			dp[i].first += dp[nxt[0] + 1].first;
			dp[i].second += dp[nxt[0] + 1].second;
		}

		if (nxt[1] == n) dp[i].second += 1;
		else {
			dp[i].first += dp[nxt[1] + 1].first;
			dp[i].second += dp[nxt[1] + 1].second;
		}
	}

	return dp[0];
}

const int H = 15;
const int MAX = 30;
const int B = 2600;

int best[B][B];
int str[B][B];
int ans = 31;
int who;

inline void update(int n1, int s1, int n2, int s2) {
	if (ans > n1 + n2) {
		ans = n1 + n2;
		who = (s2 << n1) + s1;
	}
}

int32_t main() {
    fast_io;

	int k; cin >> k;

	for (int n = 1; n <= MAX-H; n++) {
		for (int mask = 0; mask < (1<<n); mask++) {
			auto [x, y] = get_right(n, mask);
			if (best[x][y] == 0) {
				best[x][y] = n;
				str[x][y] = mask;
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int s = 0; s < (1<<i); s++) {
			auto [x, y] = get_right(i, s);

			if (x + y == k) {
				cout << to_string(i, s) << endl;
				return 0;
			}

			auto [a, b] = get_left(i, s);
			int rem = k - x - y;

			if (a >= b) {
				for (int x = 0; x < B && a*x <= rem; x++) {
					int y = (rem - a*x);
					if (y % b) continue;
					y /= b;
					if (y >= B) continue;

					if (best[x][y]) {
						update(i, s, best[x][y], str[x][y]);
					}
				}
			} else {
				for (int y = 0; y < B && b*y <= rem; y++) {
					int x = (rem - b*y);
					if (x % a) continue;
					x /= a;
					if (x >= B) continue;

					if (best[x][y]) {
						update(i, s, best[x][y], str[x][y]);
					}
				}
			}
		}
	}

	string s = to_string(ans, who);

	cout << s << endl;
	//cerr << fast_eval(s) << endl;
	cerr << ans << endl;
}
