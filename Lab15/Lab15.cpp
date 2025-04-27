#include <iostream>
using namespace std;


void printarray(int array[], int size) {
    cout << "Array of divisors: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter an integer n: ";
    cin >> n;

    int count = 0;
    for (int i = 1; i <= abs(n); i++) {
        if (n % i == 0) {
            count++;
        }
    }

    int* divisors = new int[count];
    int index = 0;
    for (int i = 1; i <= abs(n); i++) {
        if (n % i == 0) {
            divisors[index] = i;
            index++;
        }
    }
    printarray(divisors, count);

    for (int i = 0; i < count / 2; i++) {
        int temp = divisors[i];
        divisors[i] = divisors[count - 1 - i];
        divisors[count - 1 - i] = temp;
    }
    printarray(divisors, count);

    delete[] divisors;
}
