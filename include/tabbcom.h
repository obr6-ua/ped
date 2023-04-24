#ifndef _tabbcom_ 
#define _tabbcom_

#include "tvectorcom.h"
#include <queue>

class TABBCom;

class TNodoABB{
    private:
        // El elemento del nodo
        TComplejo item;
        // Subárbol izquierdo y derecho
        TABBCom iz, de;

    public:
        friend class TABBCom;
        // Constructor por defecto
        TNodoABB ();
        // Constructor de copia
        TNodoABB (const TNodoABB &);
        // Destructor
        ~TNodoABB ();
        // Sobrecarga del operador asignación
        TNodoABB & operator=(const TNodoABB &);
};

class TABBCom{

    private:
        // Puntero al nodo
        TNodoABB *nodo;
        // AUXILIAR : Devuelve el recorrido en inorden
        void InordenAux(TVectorCom &, int &) const;
        // AUXILIAR : Devuelve el recorrido en preorden
        void PreordenAux(TVectorCom &, int &);
        // AUXILIAR : Devuelve el recorrido en postorden
        void PostordenAux(TVectorCom &, int &);
        //Devuelve TRUE si es mayor que el item de dicho nodo
        bool EsMayor(const TComplejo &);

    public:
        friend class TNodoABB;
        // Constructor por defecto
        TABBCom ();
        // Constructor de copia
        TABBCom (const TABBCom &);
        // Destructor
        ~TABBCom ();
        // Sobrecarga del operador asignación
        TABBCom & operator=(const TABBCom &);

        // Sobrecarga del operador igualdad
        bool operator==(const TABBCom &);
        // Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
        bool EsVacio() const;
        // Inserta el elemento en el árbol
        bool Insertar(const TComplejo &);
        // Borra el elemento en el árbol
        bool Borrar(const TComplejo &);
        // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
        bool Buscar(const TComplejo &);
        // Devuelve el elemento en la raíz del árbol
        TComplejo Raiz() const;
        // Devuelve la altura del árbol (la altura de un árbol vacío es 0)
        int Altura();
        // Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
        int Nodos() const;
        // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
        int NodosHoja();
        // Devuelve el recorrido en inorden
        TVectorCom Inorden() const;
        // Devuelve el recorrido en preorden
        TVectorCom Preorden();
        // Devuelve el recorrido en postorden
        TVectorCom Postorden();
        // Devuelve el recorrido en niveles
        TVectorCom Niveles();
        // Sobrecarga del operador salida
        friend ostream & operator<<(ostream &, TABBCom &);
};

#endif