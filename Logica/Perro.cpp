#include "../Cabezales/Perro.h"
#include "../Cabezales/Mascota.h"

Perro::Perro (string nombre, float peso, Genero genero, RazaPerro raza, bool vacunaCachorro) : Mascota(nombre, peso, genero){
	this->raza = raza;
	this->vacunaCachorro = vacunaCachorro;
}
Perro::~Perro(){}

float Perro::obtenerRacionDiaria(){
    return this->getPeso() * 0.025;
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
void Perro::setVacunaCachorro(bool vacuna) {
	this->vacunaCachorro = vacuna;
}

