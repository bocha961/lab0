#incluide "../Laboratorio0/Ej1/Cabezales/Gato.h"
#incluide "../Laboratorio0/Ej1/Cabezales/DtMascota.h"
#incluide "../Laboratorio0/Ej1/Cabezales/Mascota.h"

Gato::Gato(string nombre, float peso, Genero genero, TipoPelo tipoPelo){

}
~Gato::Gato(){
	
}

float Gato::obtenerRacionDiaria(float peso){
    return peso*0.015;
}

void Gato::setTipoPelo(TipoPelo pelo){
    this->tipoPelo= pelo;

}

TipoPelo Gato::getTipoPelo(){
    return this->tipoPelo;
}
