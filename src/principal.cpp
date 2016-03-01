#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
	
	/** @brief lee un fichero de delitos, linea a linea
	@param[in] s nombre del fichero
        @param[in,out] C conjunto sobre el que se lee
	@return true si la lectura ha sido correcta, false en caso contrario
	*/
template <typename CMP>
bool load(conjunto<CMP> &  C, const string & s) {

 ifstream fe;
 string cadena;	


 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   	//cout << "leo:: "<< cadena << endl;
		crimen aux;
		aux.setCrimen(cadena);
		C.insert(aux);
         }
     }
    fe.close();
    return true;
    } // else
  fe.close();
  return false;
 }

int main()
{
    conjunto<CrecienteIUCR> ChicagoDB;
    crimen d;
    fecha f;
    
    

	load(ChicagoDB, "crimenes.csv");
	
	conjunto<CrecienteIUCR>::iterator it;
	for (it = ChicagoDB.begin() ; it != ChicagoDB.end(); ++it) //Itera sobre todos los elementos del conjunto.
		cout << *it << endl;

	cout << "Probamos a buscar un crimen con id 2034\n";
	conjunto<CrecienteIUCR> nuevo = ChicagoDB.findIUCR("2034");
	cout <<nuevo;

   return 0;
}
