#ifndef DATACOSULTA_H
#define DATACOSULTA_H

// Write your header file here.
#include <string>
#include <iostream>
#include "Fecha.h"

using std::string;

class DataConsulta {
    private:
        Fecha fechaConsulta;
        string motivo;
        
    public:
        DataConsulta(Fecha fechaConsulta, string motivo); //Constructor de la clase
        Fecha getFecha();  
        string getMotivo();        
};

#endif