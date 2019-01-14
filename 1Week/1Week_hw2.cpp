#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, w, l;
    cin >> n >> w >> l;

    queue<int> q;

    int sum, count;
    sum = 0; count = 0;
    for(; n>0; n--) {
    int tmp; cin >> tmp;
        while (true) {
            if (q.empty()) { // 비어 있을 때
                q.push(tmp);
                count++;
                sum += tmp;
                break;
            }else if (q.size() == w) { // q가 비어있지 않을 때, 최대 건널 수 있는 수 만족 시
                sum -= q.front(); // 제일 처음에 건넌 트럭> 다리 건너기 완료
                q.pop();
            }else { // q가 비어있지 않을 때, 아직 w 만족이 아닌 경우
                if (sum + tmp > l) { // 다리 하중을 넘은 경우
                    q.push(0);
                    count++;
                }else { //  아직 안넘은 경우
                    q.push(tmp);
                    count++;
                    sum += tmp;
                    break;
                }
            }
        }
    }

    cout << count + w << endl;
    return 0;
}
