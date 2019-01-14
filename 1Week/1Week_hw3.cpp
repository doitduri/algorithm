#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n;
    
    cin>>n;
    int* number = new int[n];
    
    for(int i=0; i<n; i++)
        cin >> number[i];
    
    sort(number, number+n);
    
    int a = max({number[0]*number[n-1], number[n-1]*number[n-2], number[0]*number[1]});
    int b = max({number[n-1]*number[n-2]*number[n-3], number[0]*number[1]*number[2],
        number[0]*number[n-1]*number[n-2], number[0]*number[1]*number[n-1]});
    cout << max(a,b);
    return 0;
}
