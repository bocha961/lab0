/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   B.h
 * Author: joaquin
 *
 * Created on 21 de marzo de 2018, 10:51 PM
 */

#ifndef B_H
#define B_H

class A;
class C;

class B {
public:
    A* a;
    C* c;
    B(int valor);
    
    void imprimir();
   /* int* getInt();
    void setInt(int* valor);*/
    
private:
    int b;
};

#endif /* B_H */

