#include <iostream>
#include <vector>

using namespace std;

void printMemVec(const vector<int>& vec) { 
    cout << "Vector - Each int is worth " << sizeof(vec[0]) << " bytes\n";
    for (int i = 0; i < vec.size(); i++) { 
        cout << vec[i] << " ";
    }
    cout << endl;
}

void incVecBy10(vector<int>& vec) {  
    for (int i = 0; i < vec.size(); i++) {  
        vec[i] += 10;
    }
}

int main() {
    const int size = 5;
    vector<int> vec(size);

    for (int i = 0; i < size; i++) {
        vec[i] = 100 + i;
    }

    cout << "Before Increment:\n";  
    printMemVec(vec);

    incVecBy10(vec);

    cout << "After Increment:\n";  
    printMemVec(vec);

    return 0;
}
