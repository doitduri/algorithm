#include <iostream>
using namespace std;

int sum (int w[], int a, int b){
    int sum=0;
    for(int i=a; i<=b; i++)
        sum += w[i];
    return sum;
}

int main(){
    int t, k;

    int *w = new int[501];
    int **dp = new int*[501];
    for(int i=0; i<501; i++) dp[i] = new int[501];

    scanf("%d", &t);

    while(t--){
        scanf("%d", &k);

        for(int i=1; i<=k; i++)
            scanf("%d", &w[i]);

        for(int diff=0; diff<k; diff++){
            for(int i=1, j=i+diff; j<=k; i++, j=i+diff){
                int min = -1;

                for(int m=i; m<j; m++){
                    if(min<0 || dp[i][m]+dp[m+1][j]<min)
                        min = dp[i][m]+dp[m+1][j];
                }

                int s = sum(w,i,j);
                if(i==j) dp[i][j]=0;
                else dp[i][j]= min + s;

            }
        }

        printf("%d\n", dp[1][k]);
    }

    return 0;
}