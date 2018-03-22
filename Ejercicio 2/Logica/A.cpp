/* 
 * File:   A.cpp
 * Author: joaquin
 * 
 * Created on 21 de marzo de 2018, 10:51 PM
 */
#include <iostream>
#include "A.h"

using std::cin;
using std::cout;
using std::endl;

A::A(int valor) {
    this->a = valor;
}

void A::imprimir(){
    cout << "A: " << this->a << endl;
}

/*int A::getInt(){
    return this->a;
}
void A::setInt(int* valor){
    this->a = valor;
}*/


