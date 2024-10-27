#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
 
vector<string> gray_code(int n){
    if(n==1)return {"0","1"};
    vector<string> last = gray_code(n-1), ans;
    for(auto x:last)ans.pb(x+'0');
    reverse(all(last));
    for(auto x:last)ans.pb(x+'1');
    return ans;
}
 
 
int main(){_
    int n;cin>>n;
    vector<string>solve = gray_code(n);
    for(auto x:solve)cout<<x<<endl;
}
