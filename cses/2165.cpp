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
vector<ii>ans;
void solve(int atual,int aux,int objetivo,int quantos){
    if(quantos==1){
        ans.pb({atual,objetivo});
        return;
    }
    solve(atual,objetivo,aux,quantos-1);
    solve(atual,aux,objetivo,1);
    solve(aux,atual,objetivo,quantos-1);
}
 
int main(){_
    int n;cin>>n;
    solve(1,2,3,n);
    cout<<sz(ans)<<endl;
    for(auto [x,y]:ans)cout<<x<<" "<<y<<endl;
}
