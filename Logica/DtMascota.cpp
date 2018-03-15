#include "../Cabezales/DtMascota.h"

void DtMascota::DtMascota(string nombre, Genero genero, float peso, float racionDiario){
    this->nombre         = nombre;
    this->genero         = genero;
    this->peso           = peso;
    this->racionDiario   = racionDiaria;
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
    return this->racionDaria;
}
