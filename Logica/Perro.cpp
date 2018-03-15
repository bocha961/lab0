#include "../Cabezales/Perro.h"

void Perro::Perro(){}

float Perro::obtenerRacionDiario(){
    return (this.peso) * 0.025;
}

RazaPerro Perro::getRazaPerro(){
    return this.raza;
}
void Perro::setRazaPerro(RazaPerro raza){
    this.raza = raza;
}

bool Perro::getVacunaCachorro(){
    return this.vacunaCachorro;
}
void setVacunaCachorro(bool vacuna){
    this.vacunaCachorro = vacuna;
}