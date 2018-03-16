#ifndef GATO_H
#define GATO_H
#include "Mascota.h"
#include "Utils.h"

class Gato : public Mascota{
    private:
        TipoPelo tipoPelo;
    
    public:
        Gato(string nombre, float peso, Genero genero, TipoPelo tipoPelo) : Mascota(string nombre, float peso, Genero genero);
		~Gato();

        float obtenerRacionDiaria();
        TipoPelo getTipoPelo();
        void setTipoPelo(TipoPelo pelo);
        
};

#endif
