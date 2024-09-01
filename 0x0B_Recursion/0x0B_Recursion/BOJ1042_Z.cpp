//S1
#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;

void recursion(int N, int r, int c, int row, int col) {
    if (N == 0) { 
        cout << cnt << endl;
        return;
    }

    int power = pow(2, N - 1); 
    int blockSize = power * power; 

    if (r < row + power && c < col + power) {
        recursion(N - 1, r, c, row, col);
    }
    else if (r < row + power && c >= col + power) {
        cnt += blockSize;
        recursion(N - 1, r, c, row, col + power);
    }
    else if (r >= row + power && c < col + power) {
        cnt += 2 * blockSize;
        recursion(N - 1, r, c, row + power, col);
    }
    else {
        cnt += 3 * blockSize;
        recursion(N - 1, r, c, row + power, col + power);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    recursion(N, r, c, 0, 0);
    return 0;
}
