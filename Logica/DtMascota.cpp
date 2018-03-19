#include "../Cabezales/DtMascota.h"

DtMascota::DtMascota(string nombre, Genero genero, float peso, float racionDiario){
    this->nombre         = nombre;
    this->genero         = genero;
    this->peso           = peso;
    this->racionDiaria   = racionDiaria;
}

DtMascota::~DtMascota() {
}



string DtMascota::getNombre(){
    return this->nombre;
}

Genero DtMascota::getGenero(){
    return this->genero;
}

float DtMascota::getPeso(){
    return this->peso;
}

float DtMascota::getRacionDiaria(){
    return this->racionDiaria;
}
