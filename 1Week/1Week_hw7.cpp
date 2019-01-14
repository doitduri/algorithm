#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n, median = 0;
    cin >> n;
    
    int *house = new int[n];
    for(int i=0; i<n; i++) {
        cin >> house[i];
        median += house[i];
    }
    
    sort(house, house+n);
    
    int a, b, mid = n/2;
    a = abs(median/n - house[mid]);
    b = abs(median/n - house[mid+1]);
    
    mid  = a>b?mid+1:mid;
    cout << house[mid] << " ";
    
    int sum=0;
    for(int i=0; i<n; i++){
        if(i != mid)
            sum += abs(house[mid]- house[i]);
    }
    cout << median;
    return 0;
}
