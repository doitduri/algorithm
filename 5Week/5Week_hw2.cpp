#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int min_height(){
    int n;
    cin >> n;
    int *log = new int[n];
    for (int i = 0; i < n; i++) cin >> log[i];
    sort(log, log + n);

    deque<int> q;

    int min = 0;
    q.push_front(log[n-1]);
    n -= 1;

    while(n>2){
        int f = q.front();
        int b = q.back();
        if(log[n-1]>log[n-2]) {
            q.push_back(log[n - 1]);
            q.push_front(log[n-2]);
        } else {
            q.push_back(log[n-2]);
            q.push_front(log[n-1]);
        }

        int m1=min, m2 = min;
        m1 = max(abs(f-q.front()),m1);
        m2 = max(m2,abs(b-q.back()));
        min = max(m1,m2);
        n -= 2;
    }
    if(n==1) {
        int f = q.front();
        int b = q.back();
        q.push_back(log[n-1]);
        int m1 = min, m2= min;
        m1 = max(abs(f-q.front()),m1);
        m2 = max(m2,abs(b-q.back()));
        min = max(m1,m2);
    }

    return min;
}
int main(){
    int t;
    scanf("%d", &t);

    int *ans = new int[t];
    for(int i=0; i<t; i++)
        ans[i] = min_height();

    for(int i=0; i<t; i++) {
        cout << ans[i];
        if(i!= t-1) cout << "\n";
    }
    return 0;
}