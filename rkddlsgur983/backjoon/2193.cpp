// BOJ #2193 이친수 - DP, 피보나치
#include <iostream>

using namespace std;

int main() {

    int n;
    long arr[91];
    cin >> n;

    arr[0] = 0, arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-2] + arr[i-1];
    }

    cout << arr[n];

    return 0;
}