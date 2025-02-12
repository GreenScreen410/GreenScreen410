#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, zero = 1, one = 0;
        cin >> N;

        while (N--) {
            int temp = one;
            one = zero + one;
            zero = temp;
        }

        cout << zero << " " << one << "\n";
    }

    return 0;
}
