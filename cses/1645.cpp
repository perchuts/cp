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
 
bool ckmin(int& a, int b){ return b < a ? a = b, true : false; }
bool ckmax(int& a, int b){ return b > a ? a = b, true : false; }
 
int v[2*maxn];
int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    stack<ii>st;
    for(int i=1;i<=n;i++){
        while(!st.empty()){
            if(st.top().first<v[i]){
                cout<<st.top().second<<" ";
                break;
            }
            else st.pop();
        }
        if(st.empty())cout<<0<<" ";
        st.push({v[i],i});
    }
    cout<<endl;
}
