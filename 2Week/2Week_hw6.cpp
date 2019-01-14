#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> point;

void bfs(int **map, point p);
bool inside(point p);

int n=0, m=0;
point direction[4]= { {make_pair(-1, 0)}, {make_pair(0, -1)}, {make_pair(0, 1)}, {make_pair(1, 0)}};

int main(){
    cin >> m >> n;

    int **map = new int*[m];
    for(int i=0; i<m; i++) map[i] = new int[n];

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%1d", &map[i][j]);

    // -1 : 전류 전달됨, 0: 흰색타일(전류 흐를 수 있음), 1: 검정타일(전류 통과 못함)
    for(int i=0; i<n; i++){
        if(map[0][i] == 0){
            map[0][i] = -1;
            bfs(map, make_pair(0, i));
        }
    }


    bool able = false;
    for(int i=0; i<n; i++){
        if(map[m-1][i]== -1){
            able=true; break;
        }
    }

    if(able) cout << "YES"; else cout << "NO";


    return 0;
}

void bfs(int **map, point p){
    queue<point> q;

    q.push(p); // outside에서 전류 전달 받은 격자

    while(!q.empty()){
        point f=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            point next = make_pair(f.first+direction[i].first, f.second+direction[i].second);

            if(inside(next) &&  map[next.first][next.second] ==0){
                map[next.first][next.second] = -1;
                q.push(next);
            }
        }
    }
}

bool inside(point p){ // m = row, n = column
    return (p.first <m && p.first>=0) && (p.second >=0 && p.second<n);
}
