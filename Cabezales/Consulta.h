#ifndef CONSULTA_H
#define CONSULTA_H

#include "DtFecha.h"

using std::string;

class Consulta{
    private:
        DtFecha fechaConsulta;
        string motivo;

    public:
        Consulta(DtFecha fecha, string motivo); //Constructor por defecto
		~Consulta();

        void setFecha(DtFecha fecha);
        DtFecha getFecha();
        void setMotivo(string motivo);
        string getMotivo();

};

#endif
