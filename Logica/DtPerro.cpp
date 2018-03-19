#include "../Cabezales/DtPerro.h"
#include "../Cabezales/DtMascota.h"

DtPerro::DtPerro(string nombre, Genero genero, float peso,  RazaPerro raza, bool vacunaCachorro) : DtMascota(nombre, genero, peso,  (float)(peso * 0.025)){
    this->raza           = raza;
    this->vacunaCachorro = vacunaCachorro;
}

DtPerro::~DtPerro(){}

RazaPerro DtPerro::getRazaPerro(){
    return this->raza;
}

bool DtPerro::getVacunaCachorro(){
    return this->vacunaCachorro;
}
