#include <iostream>
using namespace std;

int binarysearch(int start, int end, int target, int *arr);
int main(){

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int findnumber;
    cin >> findnumber;

    int c=findnumber, a=0, b=0;
//    cout << findnumber << endl;

    for (int i=n-1; i>=n/2; i--) {
        if(arr[i] < findnumber){
            int index=binarysearch(0, i-1, findnumber-arr[i], arr);
//            cout<< arr[index] << "/ " << arr[i] << "/ ";
            if(c>= findnumber-(arr[i]+arr[index]) && (arr[i]+arr[index]) <= findnumber){
                c =findnumber-(arr[i]+arr[index]);
                a = index; b=i;
//                cout<<arr[a]<<" " << arr[b] ;
            }
//            cout << " c: "<<c << "\n";
        }
    }

    cout << arr[a] << " "<< arr[b];

    return 0;
}

int binarysearch(int start, int end, int target, int *arr){
    int mid;

    while(end-start>=0){
        mid = (start+end)/2;
        if (arr[mid] < target)
            return end;
        else
            return mid;


    }
    return mid;
}
