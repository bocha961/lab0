#include <iostream>
#include "../Cabezales/Consulta.h"
#include "../Cabezales/DtFecha.h"


Consulta::Consulta(DtFecha *fecha, string motivo){
	this->fechaConsulta = fecha;
	this->motivo = motivo;
}
Consulta::Consulta(){}
Consulta::~Consulta(){
    delete this->fechaConsulta;
}

void Consulta::setFecha(DtFecha *fecha){
    this->fechaConsulta = fecha;
}
DtFecha* Consulta::getFecha(){
    return this->fechaConsulta;
}

void Consulta::setMotivo(string motivo){
    this->motivo = motivo;
}
string Consulta::getMotivo(){
    return this->motivo;
}

