#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    int *passport = new int[n];
    
    for(int i=0; i<n; i++)
        scanf("%d", &passport[i]);
    
    vector<int> check;
    check.push_back(passport[0]);
    vector<int>::iterator it = check.begin();
    int size =1;
    
    for(int i=1; i<n; i++){
        if(check.back() > passport[i]){
            if(size>1) {
                it++;
            }
            check.push_back(passport[i]);
            size+=1;
            //          cout << "push back  "<< passport[i] << " " <<size<<endl;
        }else if(*it > passport[i]){ // 갱신
            check.pop_back();
            check.push_back(passport[i]);
            //          cout << "update  "<< passport[i] << " " <<size<<endl;
        }
        
    }
    
    if(k == size)
        cout << "YES";
    else cout << "NO";
    
    //   cout << "\n" << size << " " << k;
    return 0;
}

