#ifndef MASCOTA_H
#define MASCOTA_H
#include "Utils.h"

using std::string;

class Mascota{
    private:
        string nombre;
        float peso;
        Genero genero;
    
    public:
        Mascota(); 
        virtual float obtenerRacionDiaria() = 0;
        Genero getGenero();
        void setGenero(Genero genero);
        
};

#endif