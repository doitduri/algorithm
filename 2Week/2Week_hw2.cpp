#include <iostream>
#include <vector>

using namespace std;

vector<int> num_vec;
int* visited;

typedef struct NODE {
    int value;
    NODE* next_node;
}NODE;

void makeCycle(NODE** node_arr, int node_arr_size) {
    // 노드들 연결
    for (int i = 1; i <= node_arr_size; i++) {
        node_arr[i]->next_node = node_arr[num_vec[i - 1]];
    }
}

int getCycleNum(NODE** node_arr, int node_arr_size) {
    int cycleNum = 0;
    for (int i = 1; i <= node_arr_size; i++) {
        // visited가 = 이면 싸이클 갯수를 늘려준다.
        if (visited[i] == 0) {
            visited[i] = 1;
            cycleNum++;
            NODE* sub_node = node_arr[i]->next_node;
            
            // 다음 노드값과 시작 노드 값이 같을때까지 수행
            while (  (node_arr[i]->value) != (sub_node->value)  ) {
                visited[sub_node->value] = 1;
                visited[((sub_node->next_node)->value)] = 1;
                sub_node = sub_node->next_node;
            }
        }
        else {
            continue;
        }
    }
    
    return cycleNum;
}


int main() {
    int test_case;
    cin >> test_case;
    
    for (int k = 0; k < test_case; k++) {
        int one_case;
        NODE** node_arr;
        
        cin >> one_case;
        
        num_vec.clear();
        int sub;
        // 숫자 차례대로 받아오기
        for (int i = 0; i < one_case; i++) {
            cin >> sub;
            num_vec.push_back(sub);
        }
        
        // n+1 개를 할당하고 0번째 인덱스는 버린다.
        // 노드를 동적 생성한다.
        node_arr = (NODE**)malloc(sizeof(NODE*)*(one_case + 1));
        for (int i = 1; i <= one_case; i++) {
            node_arr[i] = (NODE*)malloc(sizeof(NODE));
            node_arr[i]->value = i;
            node_arr[i]->next_node = NULL;
        }
        // visited 초기화
        visited = (int*)malloc(sizeof(int)*(one_case + 1));
        for (int i = 1; i <= one_case; i++) {
            visited[i] = 0;
        }
        
        // 사이클 만들기
        makeCycle(node_arr, one_case);
        // 사이클 개수 얻기
        cout << getCycleNum(node_arr, one_case) << "\n";
        
        delete node_arr;
        delete visited;
    }
    
    return 0;
}
