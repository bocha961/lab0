#ifndef DATAGATO_H
#define DATAGATO_H

// Write your header file here.
#include <string>
#include "Utils.h"

class DataGato : public DataMascota {
    private:
        TipoPelo tipoPelo;
        
    public:
        TipoPelo getTipoPelo();
};

#endif