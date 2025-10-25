#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void countingSort(int arr[], int n, int place) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);

    for (int place = 1; maxVal / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

int main() {
    int n;
    int arr[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            cout << "Error: Only non-negative numbers are supported.\n";
            return 1;
        }
    }

    radixSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
