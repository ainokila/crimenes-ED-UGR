/*
     This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>. 
    
    Copyright 2016 Cristian Velez Ruiz universidadcvr@gmail.com
    Copyright 2016 Jorge Gutierrez Segovia

*/

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
