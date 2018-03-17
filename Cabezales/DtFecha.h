#ifndef FECHA_H
#define FECHA_H
// Write your header file here.

class DtFecha {
    private:
        int dia;
        int mes;
        int anio;

    public:
        DtFecha(int dia, int mes, int anio);
        ~DtFecha();
        int getDia();
        int getMes();
        int getAnio();
};

#endif
