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
 
void solve() {
	int n, m; cin >> n >> m;
	if (n * m % 3 or min(n, m) == 1) {
		cout << "NO" << endl;
		return;
	}
	int swp = 0;
	if (n % 3) swp = 1, swap(n, m);
	vector<vector<char>> grid(n, vector<char>(m, 'Z'));	
	auto printAns = [&] () {
		cout << "YES" << endl;
		if (swp) {
			for (int j = 0; j < m; ++j) {
				for (int i = 0; i < n; ++i) {
					cout << grid[i][j];
				}
				cout << endl;
			}
		} else {
			for (auto x : grid) {
				for (auto y : x) cout << y;
				cout << endl;
			}
		}
	};
	if (n * m % 6) {
		if (m % 3 == 0 and m > n) swap(n, m), swp ^= 1;
		grid = vector(n, vector(m, 'Z'));
		if (min(n, m) <= 3) {
			// faca o L
			cout << "NO" << endl;
			return;
		}
		// ok, we know that it is possible
		auto placePiece = [&] (int x, int y, int type, int code) {
			char c = char('E'+code);
			grid[x][y] = c;
			if (type == 0) {
				grid[x-1][y] = grid[x][y-1] = c;
			} else if (type == 1) {
				grid[x-1][y] = grid[x][y+1] = c;
			} else if (type == 2) {
				grid[x+1][y] = grid[x][y+1] = c;
			} else {
				grid[x+1][y] = grid[x][y-1] = c;
			}
		};
		int st;
		if (n % 9 == 0) st = 0;
		else {
			st = (n % 9 == 3 ? 12 : 6);
			for (int i = 0; i < st; i += 2) {
				int a, b;
				if (i % 4) a = 5, b = 6;
				else a = 7, b = 8;
				placePiece(i, 2, 2, a);
				placePiece(i+1, 4, 0, b);
			}
			for (int i = 0; i < st; i += 3) {
				int a, b;
				if (i % 6) a = 9, b = 10;
				else a = 11, b = 12;
				placePiece(i, 0, 2, a);
				placePiece(i+2, 1, 0, b);
			}
		} 		
		for (int i = st; i < n ; i += 9) {
			placePiece(i, 0, 2, 0), placePiece(i, 4, 3, 0);
			placePiece(i+1, 2, 1, -1);
			placePiece(i+2, 1, 1, 1), placePiece(i+2, 3, 2, 3);
			placePiece(i+3, 0, 1, 3);
			placePiece(i+4, 2, 0, 2), placePiece(i+4, 4, 0, 0);
			placePiece(i+5, 0, 1, 1), placePiece(i+5, 4, 3, 1);
			placePiece(i+6, 0, 2, 2), placePiece(i+6, 2, 1, 0);
			placePiece(i+7, 4, 3, 3);
			placePiece(i+8, 1, 0, 1), placePiece(i+8, 2, 1, 2);
		}
		// now guess what, m just turned even
		for (int i = 5; i < m; i += 2) {
			char a, b;
			if ((i>>1) & 1) a = 'A', b = 'B';
			else a = 'C', b = 'D';
			for (int j = 0; j < n; j += 3) {
				grid[j][i] = grid[j+1][i] = grid[j][i+1] = a;
				grid[j+1][i+1] = grid[j+2][i] = grid[j+2][i+1] = b;
			}
		}
		// in memory: 10 minutes of my time below
		//for (int i = 0; i < n; i += 9) {
		//	int st;
		//	if (i & 1) st = 10;
		//	else st = 18;
		//	// LESGOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		//	placePiece(i, 0, 2, st), placePiece(i+1, 2, 0, st+1);
		//	placePiece(i, 4, 3, st), placePiece(i+2, 3, 1, st+2);
		//	placePiece(i, 6, 3, st+2), placePiece(i+2, 5, 1, st+1);
		//	placePiece(i+2, 1, 3, st+2), placePiece(i+3, 2, 1, st);
		//	placePiece(i+4, 0, 1, st), placePiece(i+4, 3, 3, st+1);
		//	placePiece(i+5, 0, 2, st+1), placePiece(i+6, 2, 1, st);
		//	placePiece(i+7, 1, 1, st+2);
		//	placePiece(i+8, 0, 1, st), placePiece(i+8, 3, 0, st+1);
		//	placePiece(i+3, 4, 2, st+3), placePiece(i+4, 6, 0, st+4);
		//	placePiece(i+5, 4, 2, st+5), placePiece(i+6, 6, 0, st+6);
		//	placePiece(i+7, 4, 2, st+3), placePiece(i+8, 6, 0, st+4);
		//}
		// now we simply extracted 7 stuff from this nigga, can solve for n * m % 6 == 0
		printAns();
		return;
	} 	
	if (m % 2) {
		assert(n % 6 == 0);
		for (int i = 0; i < n; i += 2) {
			char a, b;
			if ((i>>1) & 1) a = 'A', b = 'B';
			else a = 'C', b = 'D';
			grid[i][0] = grid[i][1] = grid[i+1][0] = a;
			grid[i+1][1] = grid[i+1][2] = grid[i][2] = b;
		}
		for (int i = 3; i < m; i += 2) {
			char a, b;
			if ((i>>1) & 1) a = 'Y', b = 'Z';
			else a = 'W', b = 'X';
			for (int j = 0; j < n; j += 3) {
				grid[j][i] = grid[j+1][i] = grid[j][i+1] = a;
				grid[j+1][i+1] = grid[j+2][i] = grid[j+2][i+1] = b;
			}
		}
	} else {
		for (int i = 0; i < m; i += 2) {
			char a, b;
			if ((i>>1) & 1) a = 'A', b = 'B';
			else a = 'C', b = 'D';
			for (int j = 0; j < n; j += 3) {
				grid[j][i] = grid[j+1][i] = grid[j][i+1] = a;
				grid[j+1][i+1] = grid[j+2][i] = grid[j+2][i+1] = b;
			}
		}
	}
	printAns();
}
 
int32_t main() {_
	int t = 1; cin >> t;
	while(t--) solve();
}
