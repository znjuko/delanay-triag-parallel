//
// Created by znjuko on 14.05.2020.
//

#include <iostream>
#include "point.cpp"
#include "line.cpp"
#include "triangle.cpp"
#include "tetrahedron.cpp"
#include "DeterminantSolver.cpp"

using namespace std;



int main() {

    std::vector<std::vector<float>> newVec(4);

    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            if (i == j ) {
                newVec[i].push_back(1);
            } else {
                newVec[i].push_back(0);
            }
        }
    }

    float val = Solve44(newVec);
    std :: cout << val << endl;

    return 0;
}