#include <iostream>
#include <algorithm>

using namespace std;

int search(int n, int c, int* dp){
    if(n%2 ==0 && n%3 ==0)
        return min(dp[n/2], dp[n/3])+1;
    else if(n%3==0)
        return min(dp[n/3], dp[n-1]) +1;
    else if(n%2 ==0)
        return min(dp[n/2], dp[n-1])+1;
    else
        return dp[n-1]+1;
}

int main(){
    int n;
    cin >> n;
    int *dp = new int[n+1];

    dp[1]=0; dp[2]=1; dp[3]=1;

    for(int i=4, count=0; i<=n && n>3; i++){
        dp[i] = search(i, count, dp);
    }

    cout << dp[n];

    return  0;
}