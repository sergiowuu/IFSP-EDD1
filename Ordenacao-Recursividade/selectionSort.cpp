#include <iostream>
using namespace std;

void selectionSort(int *a, int n) {
    for(int i = 0; i < n - 1; i++) {
        int iMin = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[iMin]) {
                iMin = j;
            }
        }
        if(iMin != i) {
            swap(a[i], a[iMin]);
        }
    }
}

void print(int t, int *a) {
    for(int i = 0; i < t; ++i) {
        cout << "Elemento " << i << " = " << a[i] << endl;
    }
    cout << "----------------" << endl;    
}

int main(int argc, char** argv) {
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    print(8, v);
    selectionSort(v, 8);
    print(8, v);
    
    return 0;
}