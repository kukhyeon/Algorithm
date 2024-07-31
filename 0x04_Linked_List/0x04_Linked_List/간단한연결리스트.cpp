#include <iostream>
#include <algorithm>
using namespace std;

class Linked_list {
    static const int MX = 100005;
    int dat[MX], pre[MX], nxt[MX];
    int unused = 1;
public:
    Linked_list() {
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
};

const int Linked_list::MX;

int main() {
    Linked_list ll;
    return 0;
}
