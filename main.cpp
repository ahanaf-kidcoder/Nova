#include <iostream>
#include "mrtx.hpp"

int main() {
    // Create matrices
    mrtx A;
    A.matrix = {{1.0, 2.0}, {3.0, 4.0}};

    mrtx B;
    B.matrix = {{5.0, 6.0}, {7.0, 8.0}};

    // Addition
    mrtx C = A.add(B);
    std::cout << "A + B:\n";
    C.show();

    // Multiplication
    mrtx D = A.multiply(B);
    std::cout << "A * B:\n";
    D.show();

    // Tensor Product - useful for quantum
    mrtx T = A.tensor(B);
    std::cout << "A ⊗ B:\n";
    T.show();

    return 0;
}
