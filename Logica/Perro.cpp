#include "../Cabezales/Perro.h"
#include "../Cabezales/Mascota.h"

Perro::Perro (string nombre, float peso, Genero genero, RazaPerro raza, bool vacunaCachorro) : Mascota::Mascota(nombre, peso, genero){
	this->raza = raza;
	this->vacunaCachorro = vacuna;
}
~Perro::perro(){}

float Perro::obtenerRacionDiario(){
    return (this->peso) * 0.025;
}

RazaPerro Perro::getRazaPerro(){
    return this->raza;
}
void Perro::setRazaPerro(RazaPerro raza){
    this->raza = raza;
}

bool Perro::getVacunaCachorro(){
    return this->vacunaCachorro;
}
void setVacunaCachorro(bool vacuna){
    this->vacunaCachorro = vacuna;
}
