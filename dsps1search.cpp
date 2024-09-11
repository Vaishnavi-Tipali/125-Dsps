#include <iostream>
using namespace std;

void linear_search(int a[], int n) {
    int key, flag = 0;
    cout << "Linear search\n" << endl;
    cout << "Enter key element: ";
    cin >> key;
    
    for (int i = 0; i < n; i++) {
        if (key == a[i]) {
            flag = 1;
            cout << "Key element " << key << " is found at position " << i << endl;
            return;
        }
    }
    cout << "Key element is not found" << endl;
}

void binary_search(int a[], int n) {
    int low = 0, high = n - 1, mid, key;
    cout << "Binary search\n" << endl;
    cout << "Enter key element: ";
    cin >> key;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            cout << "Key element " << key << " is found at position " << mid << endl;
            return;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Key element is not found" << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* a = new int[n]; // Dynamically allocate array
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Array elements are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    int ch, k;
    do {
        cout << "1. Linear search\n2. Binary search\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                linear_search(a, n);
                break;
            case 2:
                // Ensure the array is sorted before performing binary search
                cout << "Make sure the array is sorted before performing binary search." << endl;
                binary_search(a, n);
                break;
            default:
                cout << "Wrong choice" << endl;
        }

        cout << "Do you want to continue? Press 1 for yes, 0 for no: ";
        cin >> k;
    } while (k == 1);

    delete[] a; // Free dynamically allocated memory
    return 0;
}

