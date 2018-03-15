#ifndef DATAPERRO_H
#define DATAPERRO_H

// Write your header file here.
#include "Utils.h"

class DtPerro : public DtMascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;

    public:
        DtPerro(RazaPerro raza, bool vacunaCachorro);
        RazaPerro getRazaPerro();
        bool getVacunaCachorro();
};


#endif
