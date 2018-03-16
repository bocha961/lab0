#ifndef DATAMASCOTA_H
#define DATAMASCOTA_H

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
        ~DtMascota();

        string getNombre();
        Genero getGebero();
        float getPeso();
        float getRacionDiaria();
};

#endif
