#include "../Cabezales/DtPerro.h"

DtPerro::DtPerro(RazaPerro raza, bool vacunaCachorro){
    this->raza           = raza;
    this->vacunaCachorro = vacunaCachorro;
}

~DtPerro(){}

RazaPerro DtPerro::getRazaPerro(){
    return this->raza;
}

bool DtPerro::getVacunaCachorro(){
    return this->vacunaCachorro;
}
