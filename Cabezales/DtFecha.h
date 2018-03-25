#ifndef DTFECHA_H
#define DTFECHA_H
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
        
        friend bool operator< (DtFecha &fecha1, DtFecha &fecha2);
};

#endif
