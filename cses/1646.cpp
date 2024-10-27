#include <bits/stdc++.h>
using namespace std;
long long v[210000],prefix[210000];
int n,q;
int main(int argc, char const *argv[])
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+v[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
    return 0;
}
