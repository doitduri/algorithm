#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> point;

bool inside(point p);

int n=0, m=0;
point direction[4]= { {make_pair(-1, 0)}, {make_pair(0, -1)}, {make_pair(0, 1)}, {make_pair(1, 0)}};


int main(){
    scanf("%d %d", &n, &m);

    int **map = new int*[n];
    bool **visited = new bool*[n];
    for(int i=0; i<n; i++) {
        map[i] = new int[m];
        visited[i] = new bool[m];
    }

    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            visited[i][j] = false;
        }
    }


    queue<point> q;
    int distance=0;
    point goal = make_pair(n-1,m-1);

    q.push(make_pair(0,0));
    visited[0][0] = true;

    while(!q.empty()){
        point f=q.front();
        if(f==goal)
            cout << distance;
        q.pop();




        distance ++;
    }

    cout << "-1";
    return 0;
}


bool inside(point p){ // n = row, m = column
    return (p.first <n && p.first>=0) && (p.second >=0 && p.second<m);
}
