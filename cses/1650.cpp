#include <bits/stdc++.h>
#define maxn (int)(2*1e5+10)
using namespace std;
int n,q,root;
int v[maxn],blocks[500];
 
void build(){
    root = ceil(sqrt(n));
    for(int i=0;i<n;i++){
        if(!(i%root))blocks[i/root]=v[i];
        else
            blocks[i/root]^=v[i];
    }
}
 
int query(int l,int r){
    int ans;
    if(!(l%root)&&l+root-1<=r){
        ans = blocks[l/root];
        l+=root;
    }else{
        ans=v[l++];
    }
    for(int i=l;i<=r;){
        if(!(i%root)&&i+root-1<=r){
            ans^=blocks[i/root];
            i+=root;
        }else{
            ans^=v[i++];
        }
    }
    return ans;
 
}
int main(int argc, char const *argv[])
{
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l-1,r-1)<<endl;
    }
    return 0;
}
