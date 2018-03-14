#ifndef PERRO_H
#define PERRO_H

#include "Mascota.h"
#include "Utils.h"

class Perro : public Mascota{
    Private:
        RazaPerro raza;
        bool vacunaCachorro;
        
    Public:
        Perro();
        float obtenerRacionDiaria();
        
        RazaPerro getRazaPerro();
        void setRazaPerro(RazaPerro razaNueva);
        bool getVacunaCachorro();
        void setVacunaCachorro(bool vacunaNueva);
        
};


#endif