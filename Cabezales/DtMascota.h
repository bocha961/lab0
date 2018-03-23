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

        string getNombre() const;
        Genero getGenero() const;
        float getPeso() const;
        float getRacionDiaria() const;
    	friend ostream& operator << (ostream &o,const DtMascota &p);
};

#endif
