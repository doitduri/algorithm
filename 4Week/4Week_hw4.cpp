#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> point;
int m=1000;

bool inside(point p){ // m = row, n = column
    return (p.first <m && p.first>=0) && (p.second >=0 && p.second<m);
}

int main(){
    int n, dir=0;
    // index info) 우 0 / 상 1 / 좌 2 / 하 3
    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};
    bool ans=true;
    cin >> m >> n;
    point robot;
    robot.first = 0; robot.second=0;

    string cmd;
    int key;

    while(n--){
        cin >> cmd >> key;
        if(cmd == "TURN"){
            if(key) dir = (dir+3)%4;
            else dir = (dir+1)%4;

        }else if(cmd == "MOVE" && ans){
            robot.first += (x[dir]*key);
            robot.second += (y[dir]*key);
            if(!inside(make_pair(robot.first, robot.second)))
                ans = false;
        }
    }

    if(ans==true)
        cout << robot.first << " "<< robot.second;
    else
        cout << "-1";
    return 0;
}