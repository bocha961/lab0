#ifndef PERRO_H
#define PERRO_H

#include "Mascota.h"
#include "Utils.h"

class Perro : public Mascota{
    private:
        RazaPerro raza;
        bool vacunaCachorro;
        
    public:
        Perro(string nombre, float peso, Genero genero, RazaPerro raza, bool vacunaCachorro) : Mascota(string nombre, float peso, Genero genero);
		~Perro();
        float obtenerRacionDiaria();
        
        RazaPerro getRazaPerro();
        void setRazaPerro(RazaPerro raza);
        bool getVacunaCachorro();
        void setVacunaCachorro(bool vacuna);
        
};


#endif
