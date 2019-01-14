#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        vector<int> v;
        for (int i = 1; i <= N; ++i)
            v.push_back(i);
        int seq[101];
        int res[101];
        for (int i = 0; i < N; ++i)
            scanf("%d", seq + i);
        int check=1;
        for (int i = N - 1; i >= 0; --i)
        {
            int to = seq[i];
            if (to >= v.size())
            {
                printf("IMPOSSIBLE");
                check = 0;
                break;
            }
            res[i] = v[to];
            v.erase(v.begin() + to);
        }
        if (check)
            for (int i = 0; i < N; ++i)
                printf("%d ", res[i]);
        printf("\n");
        
        
    }
}
