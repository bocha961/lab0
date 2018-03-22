/* 
 * File:   B.cpp
 * Author: joaquin
 * 
 * Created on 21 de marzo de 2018, 10:51 PM
 */
#include <iostream>
#include "B.h"

using std::cin;
using std::cout;
using std::endl;

B::B(int valor) {
    this->b = valor;
}

void B::imprimir(){
    cout << "B: " << this->b << endl;
}

/*int* B::getInt(){
    return this->b;
}
void B::setInt(int* valor){
    this->b = valor;
}*/

