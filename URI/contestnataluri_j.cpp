#include <bits/stdc++.h>
#define maxn (int)(1e5+51)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define ll long long
#define pb push_back
#define ull unsigned long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define inf 2000000001
#define mod 1000000007 //998244353
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;


void extendedgcd(ll a,ll b,ll &x,ll &y){
    if(a==0){
        x=0LL,y=1LL;
        return;
    }
    ll x1,y1;
    extendedgcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
}


// this problem = math problem with a keyboard
void solve(){
    ull n;cin>>n;
    ll x1,y1;
    extendedgcd(n,10,x1,y1);
    ull modinverse = (x1+10LL)%10LL;
    cout<<(n*(10ULL-modinverse)+1ULL)/10ULL<<endl;
}


int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t=1;//cin>>t;
    while(t--)solve();
}