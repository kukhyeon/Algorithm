#include <iostream>
#include <algorithm>
using namespace std;

class Linked_list {
    static const int MX = 100005;
    int dat[MX], pre[MX], nxt[MX];
    int unused = 1;
public:
    Linked_list() { // pre�� nxt ��� -1�� �ʱ�ȭ, -1�� �ش� ��尡 �������� ������ �ǹ��Ѵ�.
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
        dat[unused] = data; // unused(������ �ּ�)�� ������ ����
        pre[unused] = prev; // unused�� ���� ����Ʈ ����
        nxt[unused] = nxt[prev]; // ���Ӱ� �����ϴ� ������ ���� ����Ʈ�� nxt��, ���� �����ϴ� ������ ���� ����Ʈ�� pre�̴�.

        if (nxt[prev] != -1) pre[nxt[prev]] = unused; // ���� ���� �����Ϸ��� ����Ʈ�� ���� ����Ʈ�� �����Ѵٸ�, ���� ����Ʈ�� pre�� ���ο� ����Ʈ
        nxt[prev] = unused; // ���� ����Ʈ�� ���ο� ����Ʈ�� ����
        unused++; // �ٸ� �ε��� ����� ���� unused ����
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
