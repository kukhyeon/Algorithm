#include <iostream>
#include <algorithm>
using namespace std;

class Linked_list {
    static const int MX = 100005;
    int dat[MX], pre[MX], nxt[MX];
    int unused = 1;
public:
    Linked_list() { // pre와 nxt 모두 -1로 초기화, -1은 해당 노드가 존재하지 않음을 의미한다.
        fill(pre, pre + MX, -1);
        fill(nxt, nxt + MX, -1);
    }
    void traverse() {
        int cur = nxt[0];
        while (cur != -1) {
            cout << dat[cur] << ' ';
            cur = nxt[cur];
        }
        cout << "\n\n";
    }

    void insert(int data, int prev) {
        dat[unused] = data; // unused(임의의 주소)에 데이터 삽입
        pre[unused] = prev; // unused에 이전 리스트 연결
        nxt[unused] = nxt[prev]; // 새롭게 삽입하는 원소의 이전 리스트의 nxt는, 새로 삽입하는 원소의 다음 리스트의 pre이다.

        if (nxt[prev] != -1) pre[nxt[prev]] = unused; // 만약 새로 삽입하려는 리스트의 다음 리스트가 존재한다면, 다음 리스트의 pre는 새로운 리스트
        nxt[prev] = unused; // 이전 리스트와 새로운 리스트를 연결
        unused++; // 다른 인덱스 사용을 위해 unused 증가
    }

    void erase(int idx) {
        nxt[pre[idx]] = nxt[idx];
        if (nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
    }
};

const int Linked_list::MX;

int main() {
    Linked_list ll;
    return 0;
}
