#include <iostream>
#include <algorithm>

using namespace std;

int binarysearch(int start, int end, int *arr, int target){
    int mid;
    while (end - start > 0)  // 주어진 범위[start,end]에서 탐색하도록 한다. start == end이면 반복 종료
    {
        mid = (start + end) / 2;  // 주어진 범위의 중간 위치를 계산한다

        if (arr[mid] < target) // 찾고자 하는 값보다 작으면 오른쪽으로 한 칸만 더 시작 구간 갱신
            start = mid + 1;

        else  // 찾고자 하는 값보다 크면 거기까지 끝 구간 갱신
            end = mid;
    }
    return end + 1; // 찾는 구간에 없는 경우 가장 마지막 +1 위치 전달
}

int main(){
    int n; cin >> n;
    int *arr = new int[n];
    int *len = new int[n];
    int k=0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }


    len[0]= arr[0];

    for(int i=1; i<n; i++){
        if(len[k] < arr[i]){
            len[k+1] = arr[i]; k++;
        }else{
            int index = binarysearch(0, k, len, arr[i]);
            len[index-1]=arr[i];
        }
    }

    int count=0;
    for(int i=0; len[i]!=NULL; i++)
        count++;

    cout << count;
    return 0;
}