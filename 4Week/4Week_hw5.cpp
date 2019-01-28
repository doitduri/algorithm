#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

int bf=0;

bool cmp(int a, int b){
    if(abs(bf-a)==0) return true;
    else return (abs(bf-a) < abs(bf-b));

}

int main(){

    int t;
    cin >> t;
    vector<pair<int, int>> anw;

    while(t--) {
        {
            int n;
            cin >> n;
            vector<vector<int>> cafe(100000);
            vector<pair<int, int>> location;

            for (int i = 0; i < n; i++) {
                int x, y;
                cin >> x >> y;
                cafe[x].push_back(y);
            }

            for (int i = 0; i < cafe.size(); i++) {
                vector<int>::iterator it = cafe[i].begin();
                if (cafe[i].size() > 0) {

                    sort(cafe[i].begin(), cafe[i].end(), cmp);
                    bf=cafe[i].back();

                    bf = cafe[i].back();


                    it = cafe[i].begin();
                    while (it != cafe[i].end()) {
                        location.push_back(make_pair(i, *it));
                        ++it;
                    }
                }
            }
            int m;
            cin >> m;
            while (m--) {
                int tmp;
                cin >> tmp;
                anw.push_back(make_pair(location[tmp - 1].first, location[tmp - 1].second));
//                cout << location[tmp-1].first << " "<< location[tmp-1].second<<"\n";
            }

        }
    }

    for(int i=0; i<anw.size(); i++) {
        cout << anw[i].first << " " << anw[i].second;
        if(i!=anw.size()-1) cout << "\n";
    }
    return 0;
}
