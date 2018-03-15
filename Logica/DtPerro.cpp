#include "../Cabezales/DtPerro.h"

void DtPerro::DtPerro(RazaPerro raza, bool vacunaCachorro){
    this->raza           = raza;
    this->vacunaCachorro = vacunaCachorro;
}

RazaPerro DtPerro::getRazaPerro(){
    return this->raza;
}

bool DtPerro::getVacunaCachorro(){
    return this->vacunaCachorro;
}
