#ifndef DATAGATO_H
#define DATAGATO_H

// Write your header file here.
#include <string>
#include "Utils.h"
#include "DtMascota.h"

class DataGato : public DataMascota {
    private:
        TipoPelo tipoPelo;
        
    public:
        DataGato(TipoPelo tipoPelo);
        TipoPelo getTipoPelo();
};

#endif