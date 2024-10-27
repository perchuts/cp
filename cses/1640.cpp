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
 
map<int,int>onde;
 
int main(){_
    int n,x;cin>>n>>x;
    for(int i=1;i<=n;++i){  
        int k;cin>>k;
        if(k>=x)continue;
        if(onde[x-k]!=0){
            cout<<i<<" "<<onde[x-k]<<endl;
            return 0;
        }
        onde[k] = i;
    }
    cout<<"IMPOSSIBLE"<<endl;
}
