#ifndef MASCOTA_H
#define MASCOTA_H
#include "Utils.h"
#include <string>

using namespace std;

class Mascota{
    private:
        string nombre;
        float peso;
        Genero genero;
    
    public:
        Mascota(string nombre, float peso, Genero genero); 
		~Mascota();

        virtual float obtenerRacionDiaria();
        Genero getGenero();
        void setGenero(Genero genero);
        string getNombre();
        void setNombre(string nombre);
        float getPeso();
        void setPeso(float peso);
        
};

#endif
