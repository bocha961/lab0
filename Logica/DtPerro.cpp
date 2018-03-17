#include "../Cabezales/DtPerro.h"
#include "../Cabezales/DtMascota.h"

DtPerro::DtPerro(string nombre, float peso, Genero genero, RazaPerro raza, bool vacunaCachorro) : DtMascota(nombre, peso, genero, peso * 0.025){
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
