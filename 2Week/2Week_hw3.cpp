#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    
    int arr[1001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    sort(arr, arr + n);
    for (int i = n; i >= 0; i--) if (arr[n - i] >= i) {
        cout << i;
        break;
    }
    return 0;
}
