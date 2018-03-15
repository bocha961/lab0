#include <iostream>
#include <array>
#include "../Cabezales/Socio.h"
#include "../Cabezales/Consulta.h"
#include "../Cabezales/DtConsulta.h"
#include "../Cabezales/DtGato.h"
#include "../Cabezales/DtMascota.h"
#include "../Cabezales/DtPerro.h"
#include "../Cabezales/Fecha.h"
#include "../Cabezales/Gato.h"
#include "../Cabezales/Mascota.h"
#include "../Cabezales/Perro.h"
#include "../Cabezales/Utils.h"

const int MAX_SOCIOS = 100;
std::array <Socio, MAX_SOCIOS + 1> coleccionSocios;

void agregarMascota(string ci, const DtMascota *dtMascota){
     if(dtMascota == Gato)
     new perro/gato
}


void registrarSocio(string ci, string nombre, const dtMascota *dtMascota){
    if(!llenaColeccion(coleccionSocios)){ 
        Socio *nuevoSocio = new Socio(ci, nombre);
        
        //Usar fecha del sistema (ni idea como gg ekide)
        
        //try
        agregarMascota(ci, dtMascota);
        // Esta funcion deberia determinar si es Perro o Gato
        
        //cuando termina de cargar el objeto Socio, lo deberia agregar a la coleccion
        //deberia tener una operacion para agregar a la coleccion de socios
        agregar_a_coleccion(nuevoSocio); //IMPLEMENTAR
        
    };    
};


int main(){
  
  cout << " 1 Registrar Socio";
  cout << "1 Perro 2 Gato";
  cout << "ingrese datos de su mascota";
  DtPerro // se carga el DT correspondiente
  DtGato
  if(Perro)
   registrarSocio(ci, nombre, dtPerro);
  else
  registrarSocio(ci, nombre, dtGato);
    
  
  
  
    
    
    
    
    
    
    
    return 0;
}