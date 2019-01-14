#include <iostream>
using namespace std;

long long stock(int n){
    long long *arr = new long long[n];
    
    for(int i=0; i<n; i++) cin >> arr[i];
    
    long long max = 0;
    long long stockcount=0;
    for(int i=n-1; i>=0; i--){
        if(max<arr[i]){
            max = arr[i];
        }else {
            stockcount += (max - arr[i]);
        }
    }
    return stockcount;
}
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n; cin >> n;
        
        cout << stock(n) << endl;
    }
    
    return 0;
}
