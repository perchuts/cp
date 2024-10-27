#include <bits/stdc++.h>
#define sz(x) (int) x.size()
using namespace std;

#define endl '\n'
#define fast_io cin.tie(0)->sync_with_stdio(0);
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

ll fexp(ll b, ll e) {
  ll ans = 1, p = b;
  while (e) {
    if (e&1) ans = ans * p % mod;
    e /= 2, p = p * p % mod;
  }
  return ans;
}

template<int p> struct mod_int {
  ll expo(ll b, ll e) {
    ll ret = 1;
    while (e) {
      if (e&1) ret = ret * b % p;
      e /= 2, b = b * b % p;
    }
    return ret;
  }
  ll inv(ll b) { return expo(b, p - 2); }

  using m = mod_int;
  int v;
  mod_int() : v(0) {}
  mod_int(ll v_) {
    if (v_ >= p or v_ <= -p) v_ %= p;
    if (v_ < 0) v_ += p;
    v = v_;
  }
  m& operator +=(const m& a) {
    v += a.v;
    if (v >= p) v -= p;
    return *this;
  }
  m& operator -=(const m& a) {
    v -= a.v;
    if (v < 0) v += p;
    return *this;
  }
  m& operator *=(const m& a) {
    v = v * ll(a.v) % p;
    return *this;
  }
  m& operator /=(const m& a) {
    v = v * inv(a.v) % p;
    return *this;
  }
  m operator -() { return m(-v); }
  m& operator ^=(ll e) {
    if (e < 0) {
      v = inv(v);
      e = -e;
    }
    v = expo(v, e%(p-1));
    return *this;
  }
  bool operator ==(const m& a) { return v == a.v; }
  bool operator !=(const m& a) { return v != a.v; }

  friend m operator +(m a, m b) { return a += b; }
  friend m operator -(m a, m b) { return a -= b; }
  friend m operator *(m a, m b) { return a *= b; }
  friend m operator /(m a, m b) { return a /= b; }
  friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<mod> mint;

vector<mint> convolution(vector<mint> a, vector<mint> b) {
    int n = sz(a), m = sz(b);
    vector<mint> ans(n+m-1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
           ans[i+j] += a[i] * b[j]; 
        }
    }
    return ans;
}

int32_t main() {
  fast_io;
  string s; cin >> s;
  int n = (int)s.size();
  vector<int> cnt(26);
  vector<mint> fat(n+1), ifat(n+1);
  fat[0] = 1;
  for (int i = 1; i <= n; ++i) fat[i] = fat[i-1] * i;
  ifat[n] = mint(1) / fat[n];
  for (int i = n - 1; i >= 0; --i) ifat[i] = ifat[i+1] * (i+1);
  auto c = [&] (int a, int b) {
    return fat[a] * ifat[b] * ifat[a-b];
  };
  for (auto& x : s) cnt[x-'a']++;
  vector<mint> dp(1);
  dp[0] = 1;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 0) continue;
    vector<mint> Q(cnt[i]);
    for (int j = 0; j < cnt[i]; ++j) Q[j] = ifat[cnt[i] - j] * c(cnt[i]-1, j);
    auto ndp = convolution(dp, Q);
    swap(dp, ndp);
  }
  mint ans = 0;
  for (int i = 1; i < (int)dp.size(); ++i) {
     mint val = dp[i] * fat[n - i];
     if (i&1) ans = ans + val;
     else ans = ans - val;
  }
  mint tot = fat[n];
  for (int i = 0; i < 26; ++i) tot /= fat[cnt[i]];
  ans = tot - ans;
  cout << ans.v << endl;

}
