#include <iostream>
#include "mrtx.hpp"

int main() {
    // Create matrices
    mrtx A;
    A.matrix = {{1.0, 2.0}, {3.0, 4.0}};

    mrtx B;
    B.matrix = {{5.0, 6.0}, {7.0, 8.0}};

    //fetch a mamber
     std::cout<<"the first member of A is"<<A[0,1] <<"\n";




    // Addition
    mrtx C = A+B;
    mrtx c=A-B;
    std::cout<<"A-B:\n";
    c.show();
    std::cout << "A + B:\n";
    C.show();

    // Multiplication
    mrtx D = A*B;
    std::cout << "A * B:\n";
    D.show();

    // Tensor Product - useful for quantum
    mrtx T = A.tns(B);
    std::cout << "A ⊗ B:\n";
    T.show();


    //scaler multiplication
    mrtx scl;
    scl=A.scale(3);
    std::cout<<"A * 3:\n";
    scl.show();

    //identity matrix
    mrtx i;
    i=mrtx::I(5);
    std::cout<<"identity matrix(5*5):\n";
    i.show();

    //zeros
    mrtx z;
    z=mrtx::zeros(3,4);
    std::cout<<"zero matrix(3*4):\n";
    z.show();


    //conjugate
    mrtx cj= A.Cj();
    std::cout<<"conjugate of A:\n";
    cj.show();

    //transpose
    mrtx trans=A.T();
    std::cout<<"transpose of A:\n";
    trans.show();

	//adjoint
    mrtx adj=A.dagger();
    std::cout<<"adjoint of A:\n";
    adj.show();

	//if unitary

    if(A.isUn())
    std::cout << "U is unitary\n";
}
