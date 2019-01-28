#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

string palindrome(int i, int n){
    string tmp = "";

    while(n>=i){
        tmp.insert(0, to_string(n%i));
        n=n/i;
    }
//    cout << i<< " "<< tmp<<endl;
    return tmp;
}

bool check(string s){
    string rv = s;
    reverse(rv.begin(), rv.end());
//    cout<< s << " "<< rv<<" "<< s.compare(rv)<<endl;
    if(s.compare(rv) ==0)
        return true;
    else return false;
}

int main(){
    int t;
    scanf("%d", &t);
    int *ans = new int[t];
    for(int k=0; k<t; k++){
        int n; scanf("%d", &n);

        for(int i=2; i<=64; i++) {
            if (check(palindrome(i, n))) {
                ans[k] = 1;
                break;
            }
        }
        if(ans[k]!=1) ans[k]=0;
    }

    for(int i=0; i<t; i++){
        printf("%d", ans[i]);
        if(i!= t-1) printf("\n");
    }
    return 0;
}