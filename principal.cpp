#include <iostream>
#include "../Cabezales/Socio.h"


void registrarSocio(string ci, string nombre, const dtMascota& dtMascota){
    Socio nuevoSocio = new Socio();
    nuevoSocio.setNombre(nombre);
    nuevosocio.setCi(ci);
    //Usar fecha del sistema (ni idea como gg ekide)
    
    
    agregarMascota(ci, dtMascota);
    
    //cuando termina de cargar el objeto Socio, lo deberia agregar a la coleccion
    //deberia tener una operacion para agregar a la coleccion de socios
    agregar_a_coleccion(nuevoSocio); //IMPLEMENTAR
    
    
}

int main(){
    
    Socio coleccionSocios[MAX_SOCIOS];
    
    
    
    
    
    
    
    return 0;
}