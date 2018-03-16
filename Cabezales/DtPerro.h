#ifndef DATAPERRO_H
#define DATAPERRO_H

// Write your header file here.
#include "Utils.h"
#include "DtMascota.h"

class DtPerro : public DtMascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;

    public:
        DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro);
        ~DtPerro();
        RazaPerro getRazaPerro();
        bool getVacunaCachorro();
};


#endif
