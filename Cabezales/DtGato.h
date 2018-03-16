#ifndef DATAGATO_H
#define DATAGATO_H

// Write your header file here.
#include <string>
#include "Utils.h"
#include "DtMascota.h"

class DtGato : public DtMascota {
    private:
        TipoPelo tipoPelo;

    public:
        DtGato(string nombre, Genero genero, float peso, TipoPelo tipoPelo);
        ~DtGato();
        TipoPelo getTipoPelo();
};

#endif
