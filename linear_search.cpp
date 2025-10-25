#include <bits/stdc++.h>
using namespace std;

int linearSearch(int n, int arr[], int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int result = linearSearch(n, arr, target);
    if (result != -1) {
        cout << "Found at index " << result << "." << endl;
    } else {
        cout << "Not found." << endl;
    }

    return 0;
}
