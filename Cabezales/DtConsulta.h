#ifndef DTCOSULTA_H
#define DTCOSULTA_H

// Write your header file here.
#include <string>
#include <iostream>
#include "DtFecha.h"

using namespace std;

class DtConsulta {
    private:
        DtFecha fechaConsulta;
        string motivo;

    public:
        DtConsulta(DtFecha *fechaConsulta, string motivo); //Constructor de la clase
        ~DtConsulta();
        DtFecha getFecha();
        string getMotivo();
};

#endif
