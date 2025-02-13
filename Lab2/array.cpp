#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

void printMemArr(const int * arr, int size) { 
    printf("Array - Each int is worth %lu bytes \n", sizeof(arr[0]));
    for(int i = 0; i < size; i++) { 
        cout << arr[i] << " ";
    }
    cout << endl;
}

void incArrBy10(int * arr, int size) {  
    for(int i = 0; i < size; i++) {  
        arr[i] += 10;
    }
}

int main() {
    const int size = 5;
    int arr[size];

    for(int i = 0; i < size; i++) {
        arr[i] = 100 + i;
    }

    std::cout << "Before Increment:\n";  
    printMemArr(arr, size);

    incArrBy10(arr, size);

    cout << "After Increment:\n";  
    printMemArr(arr, size);

    return 0;
}
