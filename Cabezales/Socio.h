#ifndef SOCIO_H
#define SOCIO_H

#include <string>
#include <vector>
#include "Mascota.h"
#include "Consulta.h"
#include "Fecha.h"

using std::string;

class Socio{
    Private:
        string ci, nombre;
        Fecha fechaIngreso;
        Mascota mascotas[10];
        Consulta consultas[20];

    Public:
        Socio();
        
        void setCI(string ci);
        string getCI();
        void setNombre(string nombre);
        string getNombre();
        void setFechaIngreso(Fecha fechai);
        Fecha getFecha();
        Consulta[] getConsulta(Fecha fechaCons, string motivo);
        agregarMascota(DtMascota dtMascota)
        vector<Consulta> getConsultas();
};



#endif