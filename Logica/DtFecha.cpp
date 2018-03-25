#include "../Cabezales/DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio){
    this->dia    = dia;
    this->mes    = mes;
    this->anio   = anio;
}

DtFecha::~DtFecha() {}

int DtFecha::getDia(){
    return this->dia;
}

int DtFecha::getMes(){
    return this->mes;
}

int DtFecha::getAnio(){
    return this->anio;
}

//devuelve true si fecha1 < fecha2
bool operator<(DtFecha &fecha1, DtFecha &fecha2){
    bool res = false;
    if(fecha1.getAnio() < fecha2.getAnio())
        res = true;
    else if(fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() < fecha2.getMes())
        res = true;
    else if(fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() == fecha2.getMes() 
            && fecha1.getDia() < fecha2.getDia())
        res = true;
    return res;
}