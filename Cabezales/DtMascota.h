#ifndef DATAMASCOTA_H
#define DATAMASCOTA_H

// Write your header file here.
#include "Utils.h"

using std::string;

class DataMascota {
    private:
        string nombre;
        Genero genero;
        float peso;
        float racionDiaria;
    
    public:
        DataMascota(string nombre, Genero genero, float peso, float racionDiaria);
        string getNombre();
        Genero getGebero();
        float getPeso();
        float getRacionDiaria();    
};

#endif