#include <iostream>
using namespace std;

#include "vector"

#include "./libraries/matplotlib-cpp/matplotlibcpp.h"
namespace plt = matplotlibcpp;

// Developed in Linux
// To execute, use:
// g++ LinearFunction.cpp -I/usr/include/python3.12 -lpython3.12 -I$(python3 -c "import numpy; print(numpy.get_include())") -Wno-deprecated-declarations -o program.out
// ./program.out

int main() {
    int size = 0;
    int aTerm = 0;
    int bTerm = 0;

    cout << "LINEAR FUNCTION" << endl;
    cout << "-------------------" << endl;
    
    cout << "Enter the size of vector: ";
    cin >> size;

    cout << endl;
    
    cout << "f(x) = ax + b" << endl;
    cout << "Enter the 'a': ";
    cin >> aTerm;

    cout << "Enter the 'b': ";
    cin >> bTerm;

    vector<int> values(size);

    for (int i = 0; i < values.size(); i++)
    {
        values[i] = aTerm * i + bTerm;
    }
    

    plt::plot(values);
    plt::show();
}