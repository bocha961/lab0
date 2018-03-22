/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C.h
 * Author: joaquin
 *
 * Created on 21 de marzo de 2018, 10:52 PM
 */

#ifndef C_H
#define C_H

class A;
class B;

class C {
public:
    A* a;
    B* b;
    C(int valor);
    
    void imprimir();
   /* int* getInt();
    void setInt(int* valor);*/
    
private:
    int c;
};

#endif /* C_H */

