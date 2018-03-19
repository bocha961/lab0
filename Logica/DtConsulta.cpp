#include "../Cabezales/DtConsulta.h"


DtConsulta::DtConsulta(DtFecha fechaConsulta, string motivo){
    this->fechaConsulta = fechaConsulta;
    this->motivo = motivo;
}

DtConsulta::~DtConsulta(){
}

DtFecha DtConsulta::getFecha(){
    return this->fechaConsulta;
}

string DtConsulta::getMotivo(){
    return this->motivo;
}



