#include <iostream>
#include "../Cabezales/Consulta.h"

Consulta::Consulta(){}

void Consulta::setFecha(DtFecha fecha){
    this->fechaConsulta = fecha;
}
DtFecha Consulta::getFecha(){
    return this->fechaConsulta;
}

void Consulta::setMotivo(string motivo){
    this->motivo = motivo;
}
string Consulta::getMotivo(){
    return this->motivo;
}

