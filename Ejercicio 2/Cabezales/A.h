/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A.h
 * Author: joaquin
 *
 * Created on 21 de marzo de 2018, 10:51 PM
 */

#ifndef A_H
#define A_H

class B;
class C;

class A {
public:
    B* b;
    C* c;
    A(int valor);
    
    void imprimir();
   /* int getInt();
    void setInt(int valor);*/
    
private:
    int a;
};

#endif /* A_H */

