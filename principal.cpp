#include <iostream>
#include <array>
#include <ctime>
#include "../Cabezales/Socio.h"
#include "../Cabezales/Consulta.h"
#include "../Cabezales/DtConsulta.h"
#include "../Cabezales/DtGato.h"
#include "../Cabezales/DtMascota.h"
#include "../Cabezales/DtPerro.h"
#include "../Cabezales/DtFecha.h"
#include "../Cabezales/Gato.h"
#include "../Cabezales/Mascota.h"
#include "../Cabezales/Perro.h"
#include "../Cabezales/Utils.h"

using std::string;

const int MAX_SOCIOS = 100;
std::array < (Socio, MAX_SOCIOS + 1 > coleccionSocios;

void agregar_a_coleccion(Socio &agregar) {

    coleccionSocios->end() = agregar;


}

int BuscarSocio(string ci, array coleccion) {
    int i= 0;
    while (i <= tamanio &&  coleccionSocios[i]->CI != ci )
        i++;
    return i;
}

void agregarMascota(string ci, const DtMascota &dtMascota) {
    //busco el socio en la coleccion
    int tamanio = sizeof(coleccionSocios);
    //int i = 0;
    //busca el indice donde esta el socio
    int i = BuscarSocio(ci, coleccionSocios);
    //aca va un try
    if (i <= tamanio) //Si se encuentra el socio, se agrega su mascota
        coleccionSocios[i]->agregarMascota(dtMascota);


};


void registrarSocio(string ci, string nombre, const DtMascota &dtMascota) { //aca?
    //Obtener fecha del sistema
    time_t t1;
    struct tm *tm_t2;

    time(&t1);
    tm_t2 = localtime(&t1);
    int dia = tm_t2->tm_mday;
    int mes = tm_t2->tm_mon;
    int anio = tm_t2->tm_year;
    DtFecha fechaIngreso = new DtFecha(dia, mes, anio);

    Socio *nuevoSocio = new Socio(ci, nombre, fechaIngreso);

    //Usar fecha del sistema (ni idea como gg ekide)

    //try
    //agrega la mascota al vector de mascotas
    nuevoSocio.agregarMascota(dtMascota);

    // Esta funcion deberia determinar si es Perro o Gato

    //cuando termina de cargar el objeto Socio, lo deberia agregar a la coleccion
    //deberia tener una operacion para agregar a la coleccion de socios
    agregar_a_coleccion(nuevoSocio);


};
void ingresarConsulta(string motivo, string ci) {
    int tamanio = coleccionSocios.size();

    //busca el indice donde esta el socio
    int i = BuscarSocio(ci, coleccionSocios);
    //aca va un try
    if (i <= tamanio) { //Si se encuentra el socio, se agrega su mascota
        DtConsulta consulta = new DtConsulta(fecha, motivo);
        coleccionSocios[i].agregarConsulta(consulta);
    };

}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ciSocio, int& cantConsultas) {
    int i = buscarSocio(ciSocio, coleccionSocios);
    int j = 0;
    DtConsulta** arregloCons = new DtConsulta[cantConsultas]; //arreglo que voy a devolver
    DtConsulta** consultasHechas = coleccionSocios[i].getConsultas();
    while ( consultasHechas[j].getFecha() < fecha ) {
        //Hago una copia del arreglo hasta la fecha
        arregloCons[j] = new Consulta(consultasHechas.getFecha(), consultasHechas.getMotivo())
        j++;

    } // Hay que sobrecargar el operador < para comparar fechas



    return arregloCons;

}
void eliminarSocio(string ci) {
    int i = BuscarSocio(ci, coleccionSocios);
    //Usar destructor de Socio
    // Segun Santi esto llama a todo implicitamente
    delete coleccionSocios[i];
}

DtMascota** obtenerMascotas(string ci, int &cantMascotas) {
    int i = BuscarSocio(ci, coleccionSocios);
    int j = 0;
    DtMascota** arregloMascotas = new DtMascotas[cantMascotas];
    DtMascota** mascotasExistentes = coleccionSocios[i].getMascotas();
    while (j < cantMascotas) {
        arregloMascotas[j] = mascotasExistentes[j];
        j++;
    }
    return arregloMascotas;
}

void insertarSocio(){
    cout << "Ingrese datos personales" << endl;
    cout << "Ingrese el nombre del socio: ";
    string nombreSocio;
    cin >> nombreSocio;
    cout << "Ingrese la cedula de identidad:";
    string ci;
    cin >> ci;
    cout << "Ingrese datos de la mascota";
    cout << "Nombre:";
    string nombreMascota;
    cin >> nombreMascota;
    cout << "Peso:";
    float peso;
    cin >> peso;
    cout << "Genero:";
    int userInput;
    cin >> userInput;
    Genero genero = static_cast<Genero>(userInput); //Nose si es asi para enum
    cout << "Identifique a la mascota:\n";
    cout << " 1. Perro\n";
    cout << " 2. Gato \n";
    int opcionMascota;
    cin >> opcionMascota;
    switch (opcionMascota) {
    case 1:
        //cargar datatype Perro
        cout << "Ingrese la raza del perro:";
        cin >> userInput;
        RazaPerro raza = static_cast<RazaPerro>(userInput); //Nose si es asi para enum
        cout << "Esta vacunado? (0-falso / 1-verdadero)";
        bool vacuna;
        cin >> vacuna;

        //carga un DTPerro
        DtPerro *dataPerro = new DtPerro(nombreMascota, peso, genero, raza, vacuna);
        registrarSocio(ci, nombreSocio, dataPerro);
        break;

    case 2:

        cout << "Ingrese el tipo de pelo del gato:";
        cin >> userInput;
        TipoPelo tipoPelo = static_cast<TipoPelo>(userInput); //Nose si es asi para enum

        //cargar datatype gato
        DtGato *dataGato = new DtGato(nombreMascota, peso, genero, tipoPelo);
        registrarSocio(ci, nombreSocio, dataGato);
        break;
    }
}

void insertarMascota(){
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese datos de la mascota";
    cout << "Nombre:";
    string nombreMascota;
    cin >> nombreMascota;
    cout << "Peso:";
    float peso;
    cin >> peso;
    cout << "Genero:";
    int userInput;
    cin >> userInput;
    Genero genero = static_cast<Genero>(userInput); //Nose si es asi para enum
    cout << "Identifique a la mascota:\n";
    cout << " 1. Perro\n";
    cout << " 2. Gato \n";
    int opcionMascota;
    cin >> opcionMascota;
    switch (opcionMascota) {
    case 1:
        //cargar datatype Perro
        cout << "Ingrese la raza del perro:";
        cin >> userInput;
        RazaPerro raza = static_cast<RazaPerro>(userInput); //Nose si es asi para enum
        cout << "Esta vacunado? (0-falso / 1-verdadero)";
        bool vacuna;
        cin >> vacuna;

        //carga un DTPerro
        DtPerro *dataPerro = new DtPerro(nombreMascota, peso, genero, raza, vacuna);
        agregarMascota(ci, dataPerro);
        break;

    case 2:

        cout << "Ingrese el tipo de pelo del gato:";
        cin >> userInput;
        TipoPelo tipoPelo = static_cast<TipoPelo>(userInput); //Nose si es asi para enum

        //cargar datatype gato
        DtGato *dataGato = new DtGato(nombreMascota, peso, genero, tipoPelo);
        agregarMascota(ci, dataGato);
        break;
    }

}

void insertarConsulta(){
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la consulta:";
    string consulta;
    cin >> consulta;
    ingresarConsulta(consulta, ci);
}

void imprimirConsultas(DtConsulta** lista){

}

void verConsultas(){
    cout << "Ingrese la fecha que quiera ver las consultas realizas hasta entonces";
    cout << "Dia:";
    int dia;
    cin >> dia;
    cout << "Mes:";
    int mes;
    cin >> mes;
    cout << "Anio:";
    int anio;
    cin >> anio;
    DtFecha fecha = new DtFecha(dia, mes, anio);
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la cantidad de consultas que desea ver:";
    int cant;
    cin >> cant;
    imprimirConsultas(verConsultasAntesDeFecha(fecha, ci, cant)); //Falta implementar imprimirConsultas

}

void imprimirMascotas(DtMascota** lista){

}

void verMascotas(){
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la cantidad de mascotaque desea ver:";
    int cant;
    cin >> cant;
    imprimirMascotas(obtenerMascotas(ci, cant)); //Falta implementar imprimirMascotas
}


int main() {

    bool termino = false;
    int opcion;
    while (!termino) {
        cout << " Bienvenido. Elija una opcion:\n";
        cout << " 1. Registrar socio\n";
        cout << " 2. Agregar mascota\n";
        cout << " 3. Insertar consulta\n";
        cout << " 4. Ver consultas antes de fecha\n";
        cout << " 5. Ver mascotas de socio\n";
        cout << " 6. Eliminar socio\n";
        cout << " 0. Salir\n";
        cout << "\n Opcion:";
        cin >> opcion;
        cout << "\033[2J\033[1;1H"; //Clear Screen
        switch (opcion) {
        case 0:
            termino = true;
            break;
        case 1:
            insertarSocio();
            break;
        case 2:
            insertarMascota();
            break;
        case 3:
            insertarConsulta();
            break;
        case 4:
            verConsultas();
            break;
        case 5:
            verMascotas();
            break;
        case 6:
            break;
        default: cout << " Ingrese una opcion correcta\n";
        }

    }

    return 0;
};
