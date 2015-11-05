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

bool load(conjunto &  C, const string & s) {

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
    conjunto ChicagoDB;
    crimen d;
    fecha f;
    
    

	load(ChicagoDB, "crimenes.csv");
	/*Descomentar esto para comprobaciones
	
	if (ChicagoDB.findID(10073647).second){
		cout << ChicagoDB.findID(10073647).first<<endl;
	}
	else{
		cout << "ID no encontrado."<<endl;
	}	
	cout << ChicagoDB.findDESCR("AGGRAVATED DOMESTIC BATTERY: HANDS/FIST/FEET SERIOUS INJURY")<< endl; */

	//cout <<"Crimen: "<< ChicagoDB<< endl;

   return 0;
}
