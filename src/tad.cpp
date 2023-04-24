/* Prueba:
    - ALTURA, NODOS, NODOSHOJA   
*/

#include <iostream>
<<<<<<< HEAD
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;
=======

using namespace std;

#include "tvectorcom.h"
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14

int
main(void)
{
<<<<<<< HEAD

  
  TABBCom a;
 
  TComplejo c100(100, 1);
  TComplejo c50(50, 1);
  TComplejo c20(20, 1);
  TComplejo c110(110, 1);
 

  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(c100);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(c50);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(c20);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(c110);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Borrar(c20);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;
=======
  TVectorCom a, b(1), c(5);
  TVectorCom a1(a), b1(b), c1(c);

  cout << a.Tamano() << endl;
  cout << b.Tamano() << endl;
  cout << c.Tamano() << endl;
  cout << a1.Tamano() << endl;
  cout << b1.Tamano() << endl;
  cout << c1.Tamano() << endl;
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14

  a.~TVectorCom();
  b.~TVectorCom();
  c.~TVectorCom();
  a1.~TVectorCom();
  b1.~TVectorCom();
  c1.~TVectorCom();

  cout << a.Tamano() << endl;
  cout << b.Tamano() << endl;
  cout << c.Tamano() << endl;
  cout << a1.Tamano() << endl;
  cout << b1.Tamano() << endl;
  cout << c1.Tamano() << endl;

<<<<<<< HEAD
  return 1; 
=======
  return 0;
>>>>>>> 10bbfd0e8cfccf2e2f2a9225b798f36c9f1adb14

}


