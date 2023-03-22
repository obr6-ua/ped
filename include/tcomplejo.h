#ifndef _tcomplejo_ 
#define _tcomplejo_

#include <iostream>
#include <cmath>

using namespace std;

class TComplejo {
    private:
        double re ; // PARTE REAL
        double im ; // PARTE IMAGINARIA
    public:
        //Constructor por defecto : PARTE REAL e IMAGINARIA inicializadas a 0
        TComplejo ();
        //Constructor a partir de la PARTE REAL
        TComplejo (double );
        //Constructor a partir de la PARTE REAL e IMAGINARIA
        TComplejo (double , double);
        //Constructor copia
        TComplejo (const TComplejo&);
        //Destructor
        ~TComplejo();
        // Sobrecarga del operador asignación
        TComplejo& operator= (const TComplejo&);

        TComplejo operator+ (const TComplejo&);
        TComplejo operator- (const TComplejo&);
        TComplejo operator* (const TComplejo&);
        TComplejo operator+ (double);
        TComplejo operator- (double);
        TComplejo operator* (double);
        // OTROS OPERADORES
        bool operator== (const TComplejo&); // IGUALDAD de números complejos
        bool operator!= (const TComplejo&); // DESIGUALDAD de números complejos
        double Re() const ; // Devuelve PARTE REAL
        double Im() const; // Devuelve PARTE IMAGINARIA
        void Re(double)  ; // Modifica PARTE REAL
        void Im(double)  ; // Modifica PARTE IMAGINARIA
        double Arg(void); // Calcula el Argumento (en Radianes)
        double Mod(void); // Calcula el Módulo

        // Sobrecarga del operador SALIDA
        friend ostream & operator<<(ostream &, const TComplejo &);
        friend TComplejo operator+ (double , const TComplejo&);
        friend TComplejo operator- (double , const TComplejo&);
        friend TComplejo operator* (double , const TComplejo&);
};
#endif