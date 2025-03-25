#include <iostream>
using namespace std;

#include "vector"
#include <math.h>

// Developed in Linux
// g++ -Wall -Wunused-but-set-variable QuadraticFunction.cpp -o QuadraticFunction.out -lm
// ./QuadraticFunction.out

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

    static int determineXInterceptors(float delta) {
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

    float calcXVertex() {
        float xVertex = - (bTerm / (2 * aTerm));

        return xVertex;
    }

    vector<float> calcQuadraticRoots() {
        vector<float> roots(2);
        roots[0] = NULL;
        roots[1] = NULL;

        float numXInterceptors = this->determineXInterceptors(this->delta);

        if (numXInterceptors == 0) {
            return roots;
        }

        float positiveRoot = (- this->bTerm + sqrt(this->delta)) / 2 * this->aTerm;

        roots[0] = positiveRoot;

        if(numXInterceptors == 2) {
            float negativeRoot = (- this->bTerm - sqrt(this->delta)) / 2 * this->aTerm;
            roots[1] = negativeRoot;
        }

        return roots;
    }
};


int main() {
    float aTerm = 0;
    float bTerm = 0;
    float cTerm = 0;
    float delta = 0;
    float xVertex = 0;
    float yVertex = 0;
    vector<float> quadraticRoots(2);
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

    if (! QuadraticFunction::validateTerms(aTerm, bTerm, cTerm)) {
        cout << "Terms of operation cannot be 0!!" << endl;
        return 0;
    }


    QuadraticFunction func = QuadraticFunction(aTerm, bTerm, cTerm);

    delta = func.getDelta();
    xVertex = func.calcXVertex();
    yVertex = func.calcY(xVertex);
    quadraticRoots = func.calcQuadraticRoots();
    numXInterceptors = QuadraticFunction::determineXInterceptors(delta);

    printf("X Vertex: %.4f \n", xVertex);
    printf("Y Vertex: %.4f \n", yVertex);
    
    if (numXInterceptors == 1) {
        printf("Quadratic roots: X1 = %.4f", quadraticRoots[0]);
    } else if (numXInterceptors == 2) {
        printf("Quadratic roots: X1 = %.4f X2 = %.4f", quadraticRoots[0], quadraticRoots[1]);
    } else {
        printf("The quadratic function hasn't quadratic root.");
    }

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




