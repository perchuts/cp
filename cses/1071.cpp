#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  int T;
  long long int x,y;
  cin>>T;
  for(int w=0;w<T;w++){
    cin>>x>>y;
    long long int c = max(x,y);
    if(c%2){
      if(x>y){
      cout<<(c-1)*(c-1)+y;
    }else if(y>x){
    cout<<c*c-x+1;
    }else{
      cout<<c*c-c+1;
    }
    }
    else{
    if(x>y){
    cout<<c*c-y+1;
  }else if(y>x){
    cout<<(c-1)*(c-1)+x;
  }else{
    cout<<c*c-c+1;
  }
  }
  cout<<endl;
}
return 0;
}
