/* 백준 16283 Farm */
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a, b, n, w;
    int x =-1, count=0;
    
    cin >> a >> b >> n >> w;
    
    for(int i=1; i<=n-1; i++){
        if( a*i+b*(n-i) ==w){
            x = i; count++;
        }
    }
    
    if(x==-1 || count>1) cout<<"-1";
    else cout << x <<" "<< n-x;
    
    
    return 0;
}
