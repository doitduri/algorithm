#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct indegee{
    int value;
    int index;
};
bool indcmp(const indegee &c1, const indegee &c2){
    if(c1.value < c2.value)
        return true;
    else
        return false;
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> city(n+1);
    indegee *ind = new indegee[n];
    
    for(int i=0; i<n; i++) {
        city[i].push_back(-1);
        ind[i].value = 0;
        ind[i].index = i;
    }
    for(int i=0; i<m; i++){
        int c1, c2;
        cin >> c1 >> c2;
        city[c1].push_back(c2); city[c2].push_back(c1);
        ind[c1].value += 1; ind[c2].value += 1;
    }
    
    for(int i=0; i<n; i++){
        vector<int>::iterator it = city[i].begin();
        while(it != city[i].end()){
            if( (ind[i].value > ind[*it].value) && (*it > -1)){
                //                cout << i << ": "<< *it<<endl;
                city[i].erase(it--);
            }
            it++;
        }
    }
    sort(ind, ind+n, indcmp);
    
    queue<int> q;
    int dist[n];
    
    for(int i=0; i<n; i++){
        q.push(ind[i].index);
        dist[i] = 1;
    }
    
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        
        if (dist[u] != -1) {
            for (vector<int>::iterator it = city[u].begin(); it != city[u].end(); it++){
                if (dist[*it] <= dist[u])
                    dist[*it] = dist[u]+1;
            }
        }
        //                cout << "\n"<< u << " "<< dist[u];
    }
    
    int max =0;
    for (int i = 0; i < n; i++)
        max = max<dist[i]?dist[i]:max;
    
    
    cout <<max;
    
    return 0;
}

