#ifndef FECHA_H
#define FECHA_H
// Write your header file here.

class Fecha {
    private:
        int dia;
        int mes;
        int anio;
        
    public:
        Fecha(int dia, int mes, int anio);
        int getDia();
        int getMes();
        int getAnio();
};

#endif