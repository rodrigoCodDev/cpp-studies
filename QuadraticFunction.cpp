#include <iostream>
using namespace std;

#include <math.h>

// Developed in Linux

int determineXInterceptors(float delta) {
    int numXInterceptors = 0;

    if (delta < 0) {
        numXInterceptors = 0;

    } else if (delta == 0) {
        numXInterceptors = 1;

    } else {
        numXInterceptors = 2;

    }

    return numXInterceptors;
}

class QuadraticFunction {
private:
    float delta = 0;
    float aTerm = 0;
    float bTerm = 0;
    float cTerm = 0;

    void calcDelta() {
        this->delta = pow(bTerm, 2) - 4 * aTerm * cTerm;
    }

public:
    QuadraticFunction(float aTerm, float bTerm, float cTerm) {
        // todo: configure validation and exception
        this->aTerm = aTerm;
        this->bTerm = bTerm;
        this->cTerm = cTerm;
        calcDelta();
    }

    float getDelta() {
        return delta;
    }

    float calcY(float x) {
        float value = 0;
        value = aTerm * pow(x, 2) + bTerm * x + cTerm;

        return value;
    }

    
    static bool validateTerms(float a, float b, float c) {
        int calc = a * b * c;

        if (calc == 0) {
            return false;
        }

        return true;
    }

    float calcXVertex() {
        float xVertex = - (bTerm / (2 * aTerm));

        return xVertex;
    }
};


int main() {
    float aTerm = 0;
    float bTerm = 0;
    float cTerm = 0;
    float delta = 0;
    float xVertex = 0;
    float yVertex = 0;
    int numXInterceptors = 0;

    cout << "QUADRATIC FUNCTION" << endl;
    cout << "-------------------" << endl;

    cout << endl;
    
    cout << "f(x) = ax² + bx + c" << endl;
    cout << "Enter the 'a': ";
    cin >> aTerm;

    cout << "Enter the 'b': ";
    cin >> bTerm;

    cout << "Enter the 'c': ";
    cin >> cTerm;

    if (not QuadraticFunction::validateTerms(aTerm, bTerm, cTerm)) {
        cout << "Terms of operation cannot be 0!!" << endl;
        return 0;
    }


    QuadraticFunction func = QuadraticFunction(aTerm, bTerm, cTerm);
    
    delta = func.getDelta();
    xVertex = func.calcXVertex();
    yVertex = func.calcY(xVertex);
    numXInterceptors = determineXInterceptors(delta);

    printf("X Vertex: %f \n", xVertex);
    printf("Y Vertex: %f \n", yVertex);

    return 0;
}

enum Concave {
    CONCAVE_UP,
    CONCAVE_DOWN
};

Concave determineConcave(float aTerm) {
    if (aTerm > 0) {
        return CONCAVE_UP;

    }
    
    return CONCAVE_DOWN;
}




