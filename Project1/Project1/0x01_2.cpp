#include <iostream>
using namespace std;

int func2(int arr[], int N) {
    int i = 0;
    int j = N - 1;
    while (i < j) {
        if (arr[i] + arr[j] > 100) {
            j--;
        }
        else if (arr[i] + arr[j] < 100) {
            i++;
        }
        else { // 두 원소의 합이 100이면
            return 1;
        }
    }
    return 0;
}

int main() {
    int arr1[] = { 1, 52, 48 };
    int arr2[] = { 50, 42 };
    int arr3[] = { 4, 13, 63, 87 };

    cout << func2(arr1, 3) << endl; // 결과: 1
    cout << func2(arr2, 2) << endl; // 결과: 0
    cout << func2(arr3, 4) << endl; // 결과: 0

    return 0;
}
