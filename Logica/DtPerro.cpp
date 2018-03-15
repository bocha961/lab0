#include "../Cabezales/DtPerro.h"

void DataPerro::DataPerro(RazaPerro raza, bool vacunaCachorro){
    this.raza           = raza;
    this.vacunaCachorro = vacunaCachorro;
}

RazaPerro DataPerro::getRazaPerro(){
    return this.raza;
}

bool DataPerro::getVacunaCachorro(){
    return this.vacunaCachorro;
}