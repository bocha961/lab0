#include <iostream>
#include "../Cabezales/Consulta.h"

void Consulta::Consulta(){}

void Consulta::setFecha(Fecha fecha){
    this.fechaConsulta = fecha;
}
Fecha Consulta::getFecha(){
    return this.fechaConsulta
}

void Consulta::setMotivo(string motivo){
    this.motivo = motivo;
}
string Consulta::getMotivo(){
    return this.motivo;
}

