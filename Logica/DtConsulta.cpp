#include "../Cabezales/DtConsulta.h"


DtConsulta::DtConsulta(DtFecha fechaConsulta, string motivo){
    this->fechaConsulta = fechaConsulta;
    this->motivo = motivo;
}

DtFecha DtConsulta::getFecha(){
    return this->fecha;
}

string DtConsulta::getMotivo(){
    return this->motivo;
}



