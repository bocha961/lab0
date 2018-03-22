#include <iostream>
#include <array>
#include <ctime>
#include <string>
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

using namespace std;

const int MAX_SOCIOS = 100;

struct coleccionSocios {
    Socio *arraySocios[MAX_SOCIOS];
    int tope;
};

typedef coleccionSocios *coleSocios;

coleSocios crearColeSocios() {
    coleSocios res = new coleccionSocios();
    res->tope = 0;
    return res;
}

//Arreglo auxiliar
coleSocios socios;

void agregar_a_coleccion(Socio *agregar) {
    if (socios->tope < MAX_SOCIOS) {
        socios->arraySocios[socios->tope] = agregar;
        socios->tope++;
    }
}

int buscarSocio(string ci) {
    int i = 0;
    while (i < socios->tope  &&  socios->arraySocios[i]->getCI() != ci )
        i++;
    return i;
}

void agregarMascota(string ci, const DtMascota &dtMascota) {
    //busco el socio en la coleccion
    int tamanio = MAX_SOCIOS;
    DtMascota *mascotaAux = (DtMascota *)&dtMascota;
    //int i = 0;
    //busca el indice donde esta el socio
    int i = buscarSocio(ci);
    //aca va un try
    if (i < tamanio) //Si se encuentra el socio, se agrega su mascota
        socios->arraySocios[i]->agregarMascota(mascotaAux);
}


void registrarSocio(string ci, string nombre, const DtMascota &dtMascota) { //aca?
    //Obtener fecha del sistema
    time_t t1;
    struct tm *tm_t2;

    time(&t1);
    tm_t2 = localtime(&t1);
    int dia = tm_t2->tm_mday;
    int mes = tm_t2->tm_mon;
    int anio = tm_t2->tm_year;
    DtFecha *fechaIngreso = new DtFecha(dia, mes + 1, anio + 1900);

    Socio *nuevoSocio = new Socio(ci, nombre, fechaIngreso);

    DtMascota *mascotaAux = (DtMascota *)&dtMascota;

    //try
    //agrega la mascota al vector de mascotas
    nuevoSocio->agregarMascota(mascotaAux);

    // Esta funcion deberia determinar si es Perro o Gato

    //cuando termina de cargar el objeto Socio, lo deberia agregar a la coleccion
    //deberia tener una operacion para agregar a la coleccion de socios
    agregar_a_coleccion(nuevoSocio);
}


void ingresarConsulta(string motivo, string ci) {
    int tamanio = socios->tope;
    //busca el indice donde esta el socio
    /*
     CREAR FUNCION OBTENER FECHA
     */

    int i = buscarSocio(ci);

    time_t t1;
    struct tm *tm_t2;

    time(&t1);
    tm_t2 = localtime(&t1);
    int dia = tm_t2->tm_mday;
    int mes = tm_t2->tm_mon;
    int anio = tm_t2->tm_year;
    DtFecha *fecha = new DtFecha(dia, mes + 1, anio + 1900);
    //aca va un try
    if (i < tamanio) { //Si se encuentra el socio, se agrega su mascota
        DtConsulta *consulta = new DtConsulta(fecha, motivo);
        socios->arraySocios[i]->agregarConsulta(consulta);
    }

}

bool esMenorFecha(DtFecha *fecha1, DtFecha *fecha2) {
    DtFecha *aux1 = fecha1;
    DtFecha *aux2 = fecha2;
    if ((aux1->getAnio() <= aux2->getAnio()) && (aux1->getMes() <= aux2->getMes()) && (aux1->getDia() <= aux2->getDia())) {
        return true;
    }
    else return false;
}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ciSocio, int& cantConsultas) {
    int i = buscarSocio(ciSocio);
    int j = 0;
    DtConsulta *arregloRes[cantConsultas]; //arreglo que voy a devolver
    Consulta **consultasHechas = socios->arraySocios[i]->getConsultas();//arreglo de todas las consultas hechas
    DtFecha *fechaAux = (DtFecha *)&fecha;

    while ( esMenorFecha(consultasHechas[j]->getFecha(), fechaAux)) {
        //Hago una copia del arreglo hasta la fecha
        //Esto esta Mal ya que no son tipos compatibles
        arregloRes[j] = new DtConsulta(consultasHechas[j]->getFecha(), consultasHechas[j]->getMotivo());
        j++;

    }
    DtConsulta **res = arregloRes;

    return res;
}
void eliminarSocio(string ci) {
    int i = buscarSocio(ci);
    //Usar destructor de Socio
    // Segun Santi esto llama a todo implicitamente
    Socio *socioAux = socios->arraySocios[i];
    socios->arraySocios[i] = socios->arraySocios[socios->tope - 1];
    delete socioAux;
    socios->tope--;
}

DtMascota** obtenerMascotas(string ci, int &cantMascotas) {
    int i = buscarSocio(ci);
    int j = 0;
    /*DtMascota** arregloMascota = new DtMascota[cantMascotas];
    DtMascota** mascotasExistentes = coleccionSocios[i].getMascotas();*/

    DtMascota *arregloMascota[cantMascotas];
    Mascota **mascotasExistentes = socios->arraySocios[i]->getMascotas();
    while (j < cantMascotas) {
        DtPerro *datosMascotaPerro = dynamic_cast<DtPerro*>(mascotasExistentes[j]); // The operand of a pointer dynamic_cast must be a pointer to a complete class
        DtGato *datosMascotaGato = dynamic_cast<DtGato*>(mascotasExistentes[j]);
        if (datosMascotaPerro != NULL)
            arregloMascota[j] = new DtPerro(datosMascotaPerro->getNombre(), datosMascotaPerro->getGenero(), datosMascotaPerro->getPeso(), datosMascotaPerro->getRazaPerro(),
                                            datosMascotaPerro->getVacunaCachorro());
        else
            arregloMascota[j] = new DtGato(datosMascotaGato->getNombre(), datosMascotaGato->getGenero(), datosMascotaGato->getPeso(), datosMascotaGato->getTipoPelo());
        j++;
    }
    DtMascota **res = arregloMascota;
    return res;
}

void insertarSocio() {
    cout << "Ingrese datos personales" << endl;
    cout << "Ingrese el nombre del socio: ";
    string nombreSocio;
    cin >> nombreSocio;
    cout << "Ingrese la cedula de identidad:";
    string ci;
    cin >> ci;
    cout << "Ingrese datos de la mascota\n";
    cout << "Nombre:";
    string nombreMascota;
    cin >> nombreMascota;
    cout << "Peso:";
    float peso;
    cin >> peso;
    cout << "Genero:\n";
    cout << " 1. Macho\n";
    cout << " 2. Hembra\n";
    int opcionGenero;
    cin >> opcionGenero;
    Genero genero;
    switch (opcionGenero) {
    case 1:
        genero = macho;
        break;
    case 2:
        genero = hembra;
        break;
    }
    cout << "Identifique a la mascota:\n";
    cout << " 1. Perro\n";
    cout << " 2. Gato \n";
    int opcionMascota;
    cin >> opcionMascota;
    switch (opcionMascota) {
    case 1: {
        //cargar datatype Perro
        cout << "Ingrese la raza del perro:\n";
        cout << " 0. Labrador\n";
        cout << " 1. Ovejero\n";
        cout << " 2. Bulldog\n";
        cout << " 3. Pitbull\n";
        cout << " 4. Collie\n";
        cout << " 5. Pekines\n";
        cout << " 6. Otro\n";
        int opcionRaza;
        cin >> opcionRaza;
        RazaPerro raza;
        switch (opcionRaza) {
        case 0:
            raza = labrador;
            break;
        case 1:
            raza = ovejero;
            break;
        case 2:
            raza = bulldog;
            break;
        case 3:
            raza = pitbull;
            break;
        case 4:
            raza = collie;
            break;
        case 5:
            raza = pekines;
            break;
        case 6:
            raza = otro;
            break;

        }
        cout << "Esta vacunado? (0-falso / 1-verdadero)";
        bool vacuna;
        cin >> vacuna;

        //carga un DTPerro
        DtPerro *dataPerro = new DtPerro(nombreMascota, genero, peso, raza, vacuna);
        const DtPerro auxPerro = *dataPerro;
        registrarSocio(ci, nombreSocio, auxPerro);
        break;
    }

    case 2:

        cout << "Ingrese el tipo de pelo del gato:\n";
        cout << " 1. Corto\n";
        cout << " 2. Mediano\n";
        cout << " 3. Largo\n";
        int opcionPelo;
        cin >> opcionPelo;
        TipoPelo tipoPelo;
        switch (opcionPelo) {
        case 1:
            tipoPelo = corto;
            break;
        case 2:
            tipoPelo = mediano;
            break;
        case 3:
            tipoPelo = largo;
            break;
        }

        //cargar datatype gato
        DtGato *dataGato = new DtGato(nombreMascota, genero, peso, tipoPelo);
        const DtGato auxGato = *dataGato;
        registrarSocio(ci, nombreSocio, auxGato);
        break;
    }
}

void insertarMascota() {
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese datos de la mascota\n";
    cout << "Nombre:";
    string nombreMascota;
    cin >> nombreMascota;
    cout << "Peso:";
    float peso;
    cin >> peso;
    cout << "Genero:\n";
    cout << " 1. Macho\n";
    cout << " 2. Hembra\n";
    int opcionGenero;
    cin >> opcionGenero;
    Genero genero;
    switch (opcionGenero) {
    case 1:
        genero = macho;
        break;
    case 2:
        genero = hembra;
        break;
    }
    cout << "Identifique a la mascota:\n";
    cout << " 1. Perro\n";
    cout << " 2. Gato \n";
    int opcionMascota;
    cin >> opcionMascota;
    switch (opcionMascota) {
    case 1: {
        //cargar datatype Perro
        cout << "Ingrese la raza del perro:\n";
        cout << " 0. Labrador\n";
        cout << " 1. Ovejero\n";
        cout << " 2. Bulldog\n";
        cout << " 3. Pitbull\n";
        cout << " 4. Collie\n";
        cout << " 5. Pekines\n";
        cout << " 6. Otro\n";
        int opcionRaza;
        cin >> opcionRaza;
        RazaPerro raza;
        switch (opcionRaza) {
        case 0:
            raza = labrador;
            break;
        case 1:
            raza = ovejero;
            break;
        case 2:
            raza = bulldog;
            break;
        case 3:
            raza = pitbull;
            break;
        case 4:
            raza = collie;
            break;
        case 5:
            raza = pekines;
            break;
        case 6:
            raza = otro;
            break;

        }
        cout << "Esta vacunado? (0-falso / 1-verdadero)";
        bool vacuna;
        cin >> vacuna;

        //carga un DTPerro
        DtPerro *dataPerro = new DtPerro(nombreMascota, genero, peso, raza, vacuna);
        const DtPerro auxPerro = *dataPerro;
        agregarMascota(ci, auxPerro);
        break;
    }

    case 2:

        cout << "Ingrese el tipo de pelo del gato:\n";
        cout << " 1. Corto\n";
        cout << " 2. Mediano\n";
        cout << " 3. Largo\n";
        int opcionPelo;
        cin >> opcionPelo;
        TipoPelo tipoPelo;
        switch (opcionPelo) {
        case 1:
            tipoPelo = corto;
            break;
        case 2:
            tipoPelo = mediano;
            break;
        case 3:
            tipoPelo = largo;
            break;
        }

        //cargar datatype gato
        DtGato *dataGato = new DtGato(nombreMascota, genero, peso, tipoPelo);
        const DtGato auxGato = *dataGato;
        agregarMascota(ci, auxGato);
        break;
    }

}

void insertarConsulta() {
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la consulta:";
    string consulta;
    cin >> consulta;
    ingresarConsulta(consulta, ci);
}

void verConsultas() {
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
    DtFecha *fecha = new DtFecha(dia, mes, anio);
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la cantidad de consultas que desea ver:";
    int cant;
    cin >> cant;
    DtConsulta** lista = verConsultasAntesDeFecha(*fecha, ci, cant); //Falta implementar imprimirConsultas
    int i = 0;
    while (i < cant) {
        DtFecha *fecha_i = lista[i]->getFecha();
        int dia_i = fecha_i->getDia();
        int mes_i = lista[i]->getFecha()->getMes();
        int anio_i = lista[i]->getFecha()->getAnio();
        cout << "Consulta #" << i + 1 << " fecha:" << dia_i << "/" << mes_i << "/" << anio_i << endl;
        cout << "Motivo:\n";
        cout << lista[i]->getMotivo();
        i++;
    }

}

void verMascotas() {
    cout << "Ingrese la cedula de identidad del socio:";
    string ci;
    cin >> ci;
    cout << "Ingrese la cantidad de mascotas que desea ver:";
    int cant;
    cin >> cant;
    DtMascota** lista = obtenerMascotas(ci, cant); //Falta implementar imprimirMascotas
    int i = 0;
    while (i < cant) {
        cout << "Mascota #" << i + 1 << endl;
        cout<< "Nombre: " << lista[i]->getNombre()<< endl;
        cout << "Genero: " << lista[i]->getGenero()<< endl;
        cout << "Peso: " << lista[i]->getPeso() << "kg"<< endl;
        cout << "Racion diaria: " << lista[i]->getRacionDiaria() << "gramos"<< endl;
        DtPerro* datosMascotaPerro = dynamic_cast<DtPerro*>(lista[i]);
        DtGato* datosMascotaGato    = dynamic_cast<DtGato*>(lista[i]);
        if (datosMascotaPerro != NULL) {
            cout << "Raza: " << datosMascotaPerro->getRazaPerro()<< endl;
            if (datosMascotaPerro->getVacunaCachorro()) {
                cout << "Tiene vacuna del cachorro: Si" << endl;
            }
            else {
                cout << "Tiene vacuna del cachorro: No" << endl;
            }
        }
        else {
            cout << "Tipo de pelo: " << datosMascotaGato->getTipoPelo() << endl;
        }
        i++;
    }

}

void removerSocio() {
    cout << "Ingrese la cedula de identidad del socio que desea eliminar:";
    string ci;
    cin >> ci;
    eliminarSocio(ci);
}

int main() {
    socios = crearColeSocios();

    bool termino = false;
    int opcion;
    while (!termino) {
        cout << "\033[2J\033[1;1H"; //Clear Screen
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
            removerSocio();
            break;
        default: cout << " Ingrese una opcion correcta\n";
        }
    
    }

    return 0;
};