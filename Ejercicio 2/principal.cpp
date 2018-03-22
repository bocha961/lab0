/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: joaquin
 *
 * Created on 21 de marzo de 2018, 10:30 PM
 */

#include <cstdlib>

#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

/*
 * 
 */
int main() {
    A a(5);
    B b(10);
    C c(15);
    
    a.b = &b;
    a.c = &c;
    
    b.a = &a;
    b.c = &c;
    
    c.a = &a;
    c.b = &b;
            
    a.imprimir();
    b.imprimir();
    c.imprimir();

    return 0;
}

