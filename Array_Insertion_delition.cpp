#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size, int element, int position) {
    if (position > size || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

void deleteElement(int arr[], int& size, int position) {
    if (position >= size || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int size ;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    displayArray(arr, size);

    // Insertion
    int element , position ;
    cout << "Enter the element to insert and its position: ";
    cin >> element >> position;
    insertElement(arr, size, element, position-1);
    cout << "Array after insertion: ";
    displayArray(arr, size);

    // Deletion
    cout<< "Enter the position to delete: ";
    cin >> position;
    deleteElement(arr, size, position-1);
    cout << "Array after deletion: ";
    displayArray(arr, size);

    return 0;
}
