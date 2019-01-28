//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int sticker(){
//    int n;
//    int **arr = new int*[3];
//    int **score = new int*[3];
//    scanf("%d", &n);
//
//    for(int i=0; i<3; i++) {
//        arr[i] = new int[n+1];
//        score[i] = new int[n+1];
//    }
//
//    for(int i=0; i<3; i++){
//        for(int j=1; j<=n; j++) {
//            if(i<2) scanf("%d", &arr[i][j]);
//            score[i][j] = 0;
//        }
//    }
//    arr[0][0]=0; arr[1][0]=0;
//
////    for(int i=0; i<2; i++){
////        for(int j=0; j<n; j++){
////            cout << arr[i][j] << " ";
////        }
////        cout <<"\n";
////    }
//
//    score[0][1]=arr[0][1];
//    score[1][1]=arr[1][1];
//
//    for(int i=2; i<=n; i++){
//        if(i>0) score[2][i]= max(score[0][i-1], score[1][i-1]);
////        score[0][i] = max(max(score[1][i-1], score[1][i-2]), score[2][i-1])+arr[0][i];
////        score[1][i] = max(max(score[0][i-1], score[0][i-2]), score[2][i-1])+arr[1][i];
//
//        score[0][i] = max(score[1][i - 1], score[1][i - 2]) + arr[0][i];
//        score[1][i] = max(score[0][i - 1], score[0][i - 2]) + arr[1][i];
//
//    }
//
//
////    for(int i=0; i<3; i++){
////        for(int j=0; j<n; j++){
////            cout << score[i][j] << " ";
////        }
////        cout <<"\n";
////    }
//
////    return max(max(score[0][n-1], score[1][n-1]), score[2][n-1]);
//
//    return max(score[0][n], score[1][n]);
//}
//int main(){
//    int t;
//    int *ans = new int[t];
//    scanf("%d", &t);
//
//    for(int i=0; i<t; i++){
//        ans[i] = sticker();
//    }
//
//    for(int i=0; i<t; i++){
//        printf("%d", ans[i]);
//        if( i != t-1) printf("\n");
//    }
//    return 0;
//}


#include <iostream>

#include <algorithm>

using namespace std;



const int MAX = 100000 + 1;



int sticker[MAX][2];

int cache[MAX][2];

int N; //가로의 길이



int maxScore(void)

{

    cache[0][0] = cache[0][1] = 0; //초기값(원래 스티커는 idx=1 부터 시작)

    cache[1][0] = sticker[1][0];

    cache[1][1] = sticker[1][1];

    //위에서 시작하는 것과 아래에서 시작하는 경우를 비교하면 된다

    for (int i = 2; i <= N; i++)

    {

        //그 전칸 대각선을 선택하는 경우 vs 그 전칸 대각선을 선택하지 않고 그 전전칸 대각선을 선택하는 경우

        cache[i][0] = max(cache[i - 1][1], (i - 2 > 0) ? cache[i - 2][1] : 0) + sticker[i][0];

        cache[i][1] = max(cache[i - 1][0], (i - 2 > 0) ? cache[i - 2][0] : 0) + sticker[i][1];

    }

    return max(cache[N][0], cache[N][1]);

}



int main(void)

{

    int test_case;

    cin >> test_case;



    for (int i = 0; i < test_case; i++)

    {

        cin >> N;

        if (N<1 || N>=MAX)

            exit(-1);



        for (int i = 0; i < 2; i++)

            for (int j = 1; j <= N; j++)

                cin >> sticker[j][i];

        cout << maxScore() << endl;

    }

    return 0;

}