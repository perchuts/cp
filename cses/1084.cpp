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
 
 
int main(){_
    int n,m,k;cin>>n>>m>>k;
    vector<int>v(n), ap(m);
    for(auto& x:v)cin>>x;    
    for(auto& x:ap)cin>>x;    
    sort(all(v)), sort(all(ap));
    int l1 = 0, l2 = 0, ans = 0;
    while(l1<n&&l2<m){
        if(abs(v[l1]-ap[l2])<=k)l1++,l2++, ++ans;
        else{
            if(v[l1]<ap[l2])++l1;
            else l2++;
        }
    }
    cout<<ans<<endl;
}
