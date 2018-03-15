#ifndef DATAPERRO_H
#define DATAPERRO_H

// Write your header file here.
#include "Utils.h"

class DataPerro : public DataMascota {
    private: 
        RazaPerro raza;
        bool vacunaCachorro;
    
    public:
        DataPerro(RazaPerro raza, bool vacunaCachorro);
        RazaPerro getRazaPerro();
        bool getVacunaCachorro();        
};


#endif