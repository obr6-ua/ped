#include "../include/tabbcom.h"

using namespace std;

    // Constructor por defecto
    TNodoABB::TNodoABB (){
    }
    // Constructor de copia
    TNodoABB::TNodoABB (const TNodoABB &tnodoabb){
        this->item = tnodoabb.item;
        this->iz = tnodoabb.iz;
        this->de = tnodoabb.iz;
    }
    // Destructor
    TNodoABB::~TNodoABB (){
    }
    // Sobrecarga del operador asignación
    TNodoABB & TNodoABB::operator=(const TNodoABB &tnodoabb){
        if(this != &tnodoabb){
            (*this).~TNodoABB();
        }
        this->de = tnodoabb.de;
        this->item = tnodoabb.item; 
        this->iz = tnodoabb.iz;
        
        return *this;
    }
    // Constructor por defecto
    TABBCom::TABBCom (){
        this->nodo = NULL;
    }
    // Constructor de copia
    TABBCom::TABBCom (const TABBCom &tabbcom){
        Copiar(tabbcom);   
    }

    void TABBCom::Copiar(const TABBCom &origen) {
	if (!origen.EsVacio()) {
		this->nodo = new TNodoABB();
		this->nodo->item = origen.nodo->item;

		this->nodo->iz.Copiar(origen.nodo->iz);
		this->nodo->de.Copiar(origen.nodo->de);
	} else
		this->nodo = NULL;
    }

    // Destructor
    TABBCom::~TABBCom (){
        while (!this->EsVacio()) {
            this->nodo->iz.~TABBCom();
            this->nodo->de.~TABBCom();

            delete this->nodo;
            this->nodo = NULL;
        }
    }

    // Sobrecarga del operador asignación
    TABBCom & TABBCom::operator=(const TABBCom &tabbcom){
        if (this != &tabbcom) {
            this->~TABBCom();
            this->Copiar(tabbcom);
        }

        return *this;
    }

    // Sobrecarga del operador igualdad
    bool TABBCom::operator==(const TABBCom &tabbcom){
        return (this->Inorden() == tabbcom.Inorden() ? true : false);
    }
    //Devuelve TRUE si es mayor que el item de dicho nodo
    bool TABBCom::EsMayor(const TComplejo &com){
        TNodoABB *tnodo = new TNodoABB();
        tnodo->item = com;

        return (tnodo->item == nodo->item
        || com.Mod() < nodo->item.Mod() 
        || com.Re() < nodo->item.Re() 
        || com.Im() < nodo->item.Im()) ? false : true;
    }

    // Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
    bool TABBCom::EsVacio() const{
        if (this->nodo)
		return false;
	else
		return true;
    }

    // Inserta el elemento en el árbol
    bool TABBCom::Insertar(const TComplejo &com){
        if(this->Buscar(com)) return false;

        if(EsVacio()){
            this->nodo = new TNodoABB();
            this->nodo->item = com;
            return true;
        }

        if(this->EsMayor(com)){
            return this->nodo->de.Insertar(com);
        }
        else{
            return this->nodo->iz.Insertar(com);
        }
    }
    // Borra el elemento en el árbol
    bool TABBCom::Borrar(const TComplejo &com){
        bool borrado = false;
        TNodoABB *aux;
        if (this->Buscar(com)) {
            if (this->nodo->item == com) {
                if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {
                    delete nodo;
                    nodo = NULL;
                    borrado = true;
                } else {
                    if (this->nodo->iz.EsVacio() || this->nodo->de.EsVacio()) {
                        if (this->nodo->iz.EsVacio()) { //Sin subarbol izq
                            aux = nodo;
                            nodo = nodo->de.nodo;
                            aux->de.nodo = NULL;
                            delete aux;
                            aux = NULL;

                            borrado = true;
                        } else { //Sin subarbol der
                            aux = nodo;
                            nodo = nodo->iz.nodo;
                            aux->iz.nodo = NULL;
                            delete aux;
                            aux = NULL;

                            borrado = true;
                        }
                    } else { //Cuando tiene dos subarboles hijo.
                        Sustituir();

                        borrado = true;
                    }
                }

                borrado = true;
            } else {
                if (EsMayor(com))
                    borrado = this->nodo->de.Borrar(com);
                else
                    borrado = this->nodo->iz.Borrar(com);
            }
        }

        return borrado;
    }

    void TABBCom::Sustituir() {
        TNodoABB *anterior = nodo, *posterior = nodo->iz.nodo;
        while (!posterior->de.EsVacio()) {
            anterior = posterior;
            posterior = posterior->de.nodo;
        }
        if (posterior->iz.EsVacio()) {
            nodo->item = posterior->item;
            if (anterior == nodo) {
                nodo->iz = posterior->iz;
            } else {
                anterior->de = posterior->iz;
            }
        } else {
            nodo->item = posterior->item;
            anterior->de = posterior->iz;
        }
        delete posterior;
    }

    // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
    bool TABBCom::Buscar(const TComplejo &com){
        if (EsVacio()) {
            return false;
        }
        if (this->nodo->item == com) {
            return true;
        }
        return this->nodo->iz.Buscar(com) || this->nodo->de.Buscar(com);
    }

    // Devuelve el elemento en la raíz del árbol
    TComplejo TABBCom::Raiz() const{
        return (EsVacio() ? TComplejo() : this->nodo->item);
    }

    // Devuelve la altura del árbol (la altura de un árbol vacío es 0)
    int TABBCom::Altura(){
        return (EsVacio() ? 0 : (1 + max(this->nodo->iz.Altura(), this->nodo->de.Altura())));
    }

    // Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
    int TABBCom::Nodos() const{
		return EsVacio() == true ? 0 : (1 + nodo->de.Nodos() + nodo->iz.Nodos());
	}
	

    // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
    int TABBCom::NodosHoja(){
        if(EsVacio()) return 0;

        if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){
            return 1;
        } 
        else {
            return this->nodo->de.NodosHoja() + this->nodo->iz.NodosHoja();
        }
    }

    // AUXILIAR : Devuelve el recorrido en inorden
    void TABBCom::InordenAux(TVectorCom &v, int &i) const{
        if (!this->EsVacio()) {
            if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){
                //Lo añado al vector y acabo recur
                v[i] = this->nodo->item;
                i++;
            } else {
                this->nodo->iz.InordenAux(v, i);
                v[i] = this->nodo->item;
                i++;
                this->nodo->de.InordenAux(v, i);
            }
        }
    }

    // Devuelve el recorrido en inorden
    TVectorCom TABBCom::Inorden() const
    {
        // Posición en el vector que almacena el recorrido 
        int posicion = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos 
        TVectorCom v(Nodos());
        InordenAux(v, posicion);
        return v;
    }

    // AUXILIAR : Devuelve el recorrido en preorden
    void TABBCom::PreordenAux(TVectorCom &v, int &i){
        if(!EsVacio()){
            i++;
            v[i] = Raiz();
            this->nodo->iz.PreordenAux(v, i);        
            this->nodo->de.PreordenAux(v, i);
        }    
    }

    // Devuelve el recorrido en preorden
    TVectorCom TABBCom::Preorden(){
        int i = 1;
        TVectorCom v (this->Nodos());
        this->PreordenAux(v, i);
        return v;
    }

    // AUXILIAR : Devuelve el recorrido en postorden
    void TABBCom::PostordenAux(TVectorCom &v, int &i){
        if(!EsVacio()){ 
            this->nodo->iz.PostordenAux(v, i);        
            this->nodo->de.PostordenAux(v, i);
            i++;
            v[i] = Raiz();
        }
    }

    // Devuelve el recorrido en postorden
    TVectorCom TABBCom::Postorden(){
        int i = 1;
        TVectorCom v(this->Nodos());
        this->PostordenAux(v, i);
        return v;
    }

    

    // Devuelve el recorrido en niveles
    TVectorCom TABBCom::Niveles(){
        int i = 1;
        queue<TNodoABB*> cola;
        TVectorCom v(this->Nodos());
        TNodoABB *tnodo = this->nodo;
        TABBCom abb = *this;
        cola.push(tnodo);
        
        while(!cola.empty()){
			TNodoABB *temp = cola.front();
			v[i] = (*temp).item;
			i++;

			cola.pop();

			if(!(*temp).iz.EsVacio()){
				cola.push((*temp).iz.nodo);
			}
			if(!(*temp).de.EsVacio()){
				cola.push((*temp).de.nodo);
			}
		}
        return v;
    }
    
    // Sobrecarga del operador salida
    ostream & operator<<(ostream &s,const TABBCom &obj){
        TABBCom abb(obj);
        s << abb.Niveles();
        return s;
    }
