/* 
 * File:   C.cpp
 * Author: joaquin
 * 
 * Created on 21 de marzo de 2018, 10:52 PM
 */
#include <iostream>
#include "C.h"

using std::cin;
using std::cout;
using std::endl;

C::C(int valor) {
    this->c = valor;
}

void C::imprimir(){
   cout << "C: " << this->c << endl;
}

/*int* C::getInt(){
    return this->c;
}
void C::setInt(int* valor){
    this->c = valor;
}*/

