#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long closenumber(){
    long long n, k;
    cin >> n >> k;
    
    long long **student = new long long*[4];
    for(int i=0; i<4; i++) student[i] = new long long[k];
    long long *first = new long long[(k*k)+1];
    long long *second = new long long[(k*k)+1];
    long long index = 0;
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < k; j++) cin >> student[i][j];
    
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            first[index] = student[0][i] + student[1][j];
            second[index] = student[2][i] + student[3][j];
            index++;
        }
    }
    
    sort(second, second+index);
    
    long long d = first[0]+second[0];
    for(int i=0; i<index; i++){
        int mid, s=0, e=(int)index-1;

        while(s<=e){
            mid = s+e/2;
            long long sum = first[i]+second[mid];
            long long diff1 = abs(n-d), diff2 = abs(n-sum);

            if (diff1 >= diff2) d = diff1 == diff2 ? min(d, sum) : sum;
            if (sum < n) s = mid + 1;
            else e = mid - 1;
        }
    }
    return d;
}

int main(){
    int t;
    cin >> t;
    
    long long *ans = new long long[t];
    
    for(int i=0; i<t; i++)
        ans[i] = closenumber();
    
    for(int i=0; i<t; i++){
        cout << ans[i];
        if(i != t-1) cout << "\n";
    }
    return 0;
}
