#ifndef DTMASCOTA_H
#define DTMASCOTA_H

// Write your header file here.
#include "Utils.h"

using std::string;

class DtMascota {
    private:
        string nombre;
        Genero genero;
        float peso;
        float racionDiaria;

    public:
        DtMascota(string nombre, Genero genero, float peso, float racionDiaria);
        virtual ~DtMascota();

        string getNombre();
        Genero getGenero();
        float getPeso();
        float getRacionDiaria();
};

#endif
