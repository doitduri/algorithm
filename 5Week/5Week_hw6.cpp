#include <iostream>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int *desk = new int[n];

    for(int i=0; i<n; i++) scanf("%d", &desk[i]);

    long long longtimedesk=0, shortdesk=0;
    for(int i=0; i<n; i++) {
        if (longtimedesk < desk[i])
            longtimedesk = desk[i];
    }

    longtimedesk *= m;

    while(shortdesk < longtimedesk){
        long long mid = (shortdesk+longtimedesk)/2;
        long long  sum=0;

        for(int i=0; i<n; i++){
            sum += mid/desk[i];
        }
//        cout << sum << "/ mid "<< mid<<" ";
        if(sum < m) shortdesk = mid+1;
        else longtimedesk = mid;
//        cout << shortdesk << " "<< longtimedesk << endl;
    }

    cout << shortdesk;

    return 0;
}