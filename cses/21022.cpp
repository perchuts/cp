#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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

struct node {
	bool appear = 0, mark = 0;
	int link = 0, par = 0, c;
	vector<int> go = vector<int>(26, -1);
	node(){}
};


vector<int> solve(string S, vector<string> words){
	int h = 0;
	vector<node> trie(1000);
	vector<int> vis(1000), vis2(1000);
	for (auto s : words) {
		int cur = 0;
		for (auto x : s) {
			if (trie[cur].go[x-'a'] == -1) trie[cur].go[x-'a'] = ++h, trie[h].par = cur, trie[h].c = x-'a';
			cur = trie[cur].go[x-'a'];
		}
		trie[cur].appear = 1;
	}
	for (int i = 0; i < 26; ++i) if (trie[0].go[i] == -1) trie[0].go[i] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u != 0 and trie[u].par != 0) trie[u].link = trie[trie[trie[u].par].link].go[trie[u].c];
		for (int i = 0; i < 26; ++i) {
			if (trie[u].go[i] > 0) {
				q.push(trie[u].go[i]);
				continue;
			}
			trie[u].go[i] = trie[trie[u].link].go[i];
		}
	}
	int cur = 0;
	for (auto x : S) {
		cur = trie[cur].go[x - 'a'];
		q.push(cur);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis2[u] = trie[u].mark = true;
		if (vis2[trie[u].link] == false) {
			vis2[trie[u].link] = true;
			q.push(trie[u].link);
		}
		//if (vis2[trie[u].par] == false) {
		//	vis2[trie[u].par] = true;
		//	q.push(trie[u].par);
		//}
	}
	vector<int> ans;
	for (auto x : words) {
		cur = 0;
		for (auto y : x) cur = trie[cur].go[y-'a'];
		ans.pb(trie[cur].mark);
	}
	return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
int32_t main(){_
	int tt = 1;
	while (true) {
		int n = rnd(1, 100);
		string S;
		for (int i = 0; i < n; ++i) S.pb(char('a'+rnd(0,3)));
		vector<string> words(rnd(1, 10));
		for (auto& x : words) {
			int m = rnd(1, 5);
			for (int i = 0; i < m; ++i) x.pb(char('a'+rnd(0,3)));
		}
		auto my = solve(S, words);
		vector<int> ans;
		for (auto w : words) {
			bool ok = 0;
			for (int i = 0; i <= sz(S) - sz(w); ++i) {
				ok |= (w == S.substr(i, sz(w)));
			}
			ans.pb(ok);
		}
		if (my != ans) {
			cout << "Wrong answer on test " << tt << endl;
			cout << S << endl;
			cout << sz(words) << endl;
			for (auto x : words) cout << x << endl;
			cout << "Your output:" << endl;
			for (auto x : my) cout << (x ? "YES" : "NO") << endl;
			cout << "Correct answer:" << endl;
			for (auto x : ans) cout << (x ? "YES" : "NO") << endl;
			exit(0);
		}
		cout << "Accepted on test " << tt++ << endl;
			
	}
}
