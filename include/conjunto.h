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
    Copyright 2016 Mario Antonio Lopez Ruiz
*/

#ifndef __CONJUNTO_H
#define __CONJUNTO_H
#include <string>
#include <vector>
#include <iostream> 

#include "crimen.h"

using namespace std;


	/** @brief Class CrecienteIUCR
	 *  operator()
	 * */
	class CrecienteIUCR {
 		public:
		/** @brief Comparador del funtor , para ordenar de forma creciente por IUCR 
			@param a , tipo crimen
			@param b , tipo crimen
		*/
   		bool operator()(const crimen &a, const crimen &b);
	};

	/** @brief Class CrecienteID
	 *  operator()
	 * */
	class CrecienteID {
 		public:
		/** @brief Comparador del funtor, para ordenar de forma creciente por ID 
			@param a , tipo crimen
			@param b , tipo crimen
		*/
   		bool operator()(const crimen &a, const crimen &b);
	};

		/** @brief Class DecrecienteID
	 *  operator()
	 * */
	class DecrecienteID {
 		public:
		/** @brief Comparador del funtor, para ordenar de forma decreciente por ID
			@param a , tipo crimen
			@param b , tipo crimen
		*/
   		bool operator()(const crimen &a, const crimen &b);
	};

		/** @brief Class CrecienteFecha
	 *  operator()
	 * */
	class CrecienteFecha {
 		public:
		/** @brief Comparador del funtor, para ordenar de forma creciente por fecha 
			@param a , tipo crimen
			@param b , tipo crimen
		*/
   		bool operator()(const crimen &a, const crimen &b);
	};

	/** @brief Class recienteFecha
	 *  operator()
	 * */
	class DecrecienteFecha {
 		public:
		/** @brief Comparador del funtor,, para ordenar de forma decreciente por fecha 
			@param a , tipo crimen
			@param b , tipo crimen
		*/
   		bool operator()(const crimen &a, const crimen &b);
	};



//! Clase conjunto
 /*! conjunto:: conjunto, find, size,  
 * Tipos conjunto::entrada, conjunto::size_type
 * Descripción

* Un conjunto es un contenedor que permite almacenar en orden creciente un conjunto de elementos no repetidos.  En nuestro caso el conjunto va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento, etc). Este conjunto "simulará" un conjunto de la stl, con algunas claras diferencias pues, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

* Asociado al conjunto, tendremos el tipo  \code conjunto::entrada \endcode que permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto, en nuestro caso delitos (crimenes). Para esta entrada el requisito es que tenga definidos el operador< y operator=

* El número de elementos en el conjunto puede variar dinámicamente; la gestión de la memoria es automática. 
 
 @todo Implementa esta clase, junto con su documentación asociada
 */
template <typename CMP> 
class conjunto{
  
public:
	typedef crimen entrada;
	typedef unsigned int size_type;

	class iterator; //declaraciones previa
	class const_iterator;
	

	/** @brief constructor primitivo. 
	@post define la entrada nula como el par ("",-1)
	*/
	conjunto( );

	/** @brief Constructor que se le pasan dos iteradores ,
	@param inicio , conjunto<CMP>::iterator
	@param fina , conjunto<CMP>::iterator
	*/
	conjunto(typename conjunto<CMP>::iterator & inicio, typename conjunto<CMP>::iterator &fina);
	

	/** @brief constructor de copia
	@param[in] d conjunto a copiar
	*/
	conjunto (const conjunto & d);


	/** @brief Metodo para buscar un crimen , que te devuelve un iterador a su posicion
	@param c , tipo crimen
	@return conjunto<CMP>::iterator, iterador a su posicion
	*/
	conjunto<CMP>::iterator find(const crimen &c);

	/** @brief Metodo para buscar un crimen , que te devuelve un const_iterador a su posicion
	@param c , tipo crimen
	@return conjunto<CMP>::const_iterator, iterador a su posicion
	*/
	conjunto<CMP>::const_iterator find(const crimen &c)const;

	/** @brief Metodo para buscar un crimen respecto a su ID , que te devuelve un iterador a su posicion
	@param c , tipo crimen
	@return conjunto<CMP>::iterator, iterador a su posicion
	*/
	conjunto<CMP>::iterator find(const long int &id);

	/** @brief Metodo para buscar un crimen respecto a su ID , que te devuelve un const_iterador a su posicion
	@param c , tipo crimen
	@return conjunto<CMP>::const_iterator, iterador a su posicion
	*/
	conjunto<CMP>::const_iterator find(const long int &id)const;

	/** @brief Devuelve un iterador al elemento que no precede a x , en resumen , devuelve el primer elemento comp(e,x) es falso
	@param entrada , tipo conjunto::entrada
	@return conjunto<CMP>::iterator, iterador a su posicion
	*/
	conjunto<CMP>::iterator lower_bound (const conjunto<CMP>::entrada & x);

	/** @brief Devuelve un const_iterador al elemento que no precede a x , en resumen , devuelve el primer elemento comp(e,x) es falso
	@param entrada , tipo conjunto::entrada
	@return conjunto<CMP>::const_iterator, iterador a su posicion
	*/
	conjunto<CMP>::const_iterator lower_bound (const conjunto<CMP>::entrada & x)const;

	/** @brief Devuelve un iterador al elemento que precede a x , en resumen , devuelve el primer elemento comp(e,x) es verdadero
	@param entrada , tipo conjunto::entrada
	@return conjunto<CMP>::iterator, iterador a su posicion
	*/
	conjunto<CMP>::iterator upper_bound (const conjunto<CMP>::entrada & x);

		/** @brief Devuelve un const_iterador al elemento que precede a x , en resumen , devuelve el primer elemento comp(e,x) es verdadero
	@param entrada , tipo conjunto::entrada
	@return conjunto<CMP>::const_iterator, iterador a su posicion
	*/
	conjunto<CMP>::const_iterator upper_bound (const conjunto<CMP>::entrada & x)const;














		
	/** @brief busca un crimen en el conjunto
	@param id identificador del crimen  buscar
	@return Si existe una entrada en el conjunto devuelve un par con una copia de la entrada en el conjunto y con el segundo valor a true. Si  no se encuentra devuelve la entrada con la definicion 	por defecto y false 
	@post no modifica el conjunto.
	\verbatim Uso
       

	if (C.findID(12345).second ==true) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/
	pair<conjunto::entrada,bool>  findID( const long int & id) const;

	/** @brief busca los crimenes con el mismo codigo IUCR
	@param icur identificador del crimen  buscar
	@return Devuelve un  conjunto con todos los crimenes con el codigo IUCR. Si no existe ninguno devuelve el conjunto vacio.
	@post no modifica el conjunto.
	\verbatim Uso
        vector<crimen> C, A;
        ....
        A = C.findIUCR("0460");
	\endverbatim
	*/
	conjunto findIUCR( const string & iucr) const;


	int busquedaBinaria(const crimen & e) const;


/** @brief busca los crimenes que contienen una determinada descripcion 
	@param descr string que representa la descripcion del delito buscar
	@return Devuelve un  conjunto con todos los crimenes  que contengan descr en su descripcionR. Si no existe ninguno devuelve el conjunto vacio.
	@post no modifica el conjunto.
	\verbatim Uso
        vector<crimen> C, A;
        ....
        A = C.findDESCR("BATTERY");
	\endverbatim
	*/
	conjunto  findDESCR( const string & descr) const;

/** @brief Inserta una entrada en el conjunto
@param e entrada a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un delito con igual ID en el conjunto. False en caso contrario
@post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
*/
	bool insert( const conjunto::entrada & e);

	
	
/** @brief Borra una entrada en el conjunto .

Busca la entrada con id en el conjunto (o e.getID() en el segundo caso) y si la encuentra la borra

@param[in] entrada con e.getID() que queremos borrar, el resto de los valores no son tenidos en cuenta
@param[in] id a borrar

@post Si esta en el conjunto su tamaño se decrementa en 1.
*/
	 bool erase(const long int & id);
         bool erase(const  conjunto::entrada & e);
         

/** @brief operador de asignación
@param[in] org conjunto  a copiar.
 Crea un conjunto duplicado exacto de org.
*/
  conjunto & operator=( const conjunto & org);

	/** @brief numero de entradas en el conjunto
@post  No se modifica el conjunto.
*/
	size_type size() const ;


/** @brief vacia
   Chequea si el conjunto esta vacio (size()==0)
*/
  bool empty() const;

/** @brief Consultor Vector
   Devuelve el valor del vector vc
*/


inline vector<crimen> getVector(){
	
	return vc;
}


inline conjunto::entrada getPos(unsigned int indice) const{
	
	if(indice < vc.size()){
		return vc[indice];
	}else{
		cout << "El indice es mayor que el numero total de datos del vector."<< endl;
		conjunto::entrada solucion;
		return solucion;
	}


}	   

//LOS SIGUIENTES MÉTODOS SON DE LA CLASE ITERATOR

	// ================================= ITERADORES ========================================/

   /** @brief class iterator
	 * forward iterador sobre el conjunto, LECTURA
	 *  iterator() ,operator*(), operator++, operator++(int) operator=, operator==, operator!=
	 * */
    class iterator {

	 public:

	/** @brief Constructor por defecto de iterator

	*/
       iterator();

	/** @brief Constructor de Copia
	@param it , tipo iterator
	*/
       iterator(const iterator & it);

	/** @brief Constructor con parametro iterator tipo vecto<entrada>::iterator
	@param n ,iterator tipo vecto<entrada>

	*/
       iterator(const vector<conjunto::entrada>::iterator n);
       
	/** @brief Devuelve el valor del iterador actural
         @return conjunto::entrada , valor actual del iterator
        */
       const conjunto::entrada & operator*() const;
       
	/** @brief Preincremento ++ ++it
         @return Devuelve el iterador
	@post Despues de devolverlo , se incremente
        */
       iterator operator++( int );

	/** @brief Post incremento ++ , it++
         @return Devuelve el iterador
	@post Incrementa el iterador para devolverlo
        */
       iterator & operator++();

	/** @brief Predecremento -- --it
         @return Devuelve el iterador
	@post Despues de devolverlo , se decrementa
        */
       iterator operator--(int);

	/** @brief Post decremento -- , it--
         @return Devuelve el iterador
	@post Decrementa el iterador para devolverlo
        */
       iterator & operator--();

	/** @brief Sobrecarga operato == de clase conjunto::iterator
        @return true , si son iguales , false , si son distintos
        */
       bool operator==(const iterator & it);

	/** @brief Sobrecarga operato != de clase conjunto::iterator
        @return false , si son iguales , true , si son distintos
        */
       bool operator!=(const iterator & it);

       private:
           friend class conjunto;
           vector<conjunto::entrada>::iterator itv;
	};

     /**@brief devuelve iterador al inicio del conjunto
     */
     iterator begin();

     /**@brief devuelve iterador al final (posición siguiente al último del conjunto
     */
     iterator end();
	
//*********************************FIN-ITERATOR************************************






//*********************************INICIO_CONST_ITERATOR*************************
	
 	

	/** @brief class const_iterator
	 * forward iterador constante sobre el diccionario, Lectura 
	 *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
	 * */
	class const_iterator {
		public:

		  /** @brief Constructor por defecto de const_iterator
		   */	
		  const_iterator();

		  /** @brief Constructor de Copia
		      @param it , tipo const_iterator
		  */
		  const_iterator(const const_iterator & it);

		  /** @brief Constructor con parametro iterator tipo vecto<entrada>::const_iterator
	              @param n ,const_iterator tipo vecto<entrada>
		  */
		  const_iterator(const vector<conjunto::entrada>::const_iterator n);

		  /** @brief Convierte iterator en const_iterator
		  */
		  const_iterator(const iterator & it);

		  /** @brief Devuelve el valor del iterador actual
                      @return conjunto::entrada , valor actual del iterator
                  */	
		  const conjunto::entrada & operator*() const;

		  /** @brief Pre incremento ++ , ++it
         	      @return Devuelve el const_iterador
	              @post Incrementa el iterador despues de devolverlo
        	  */
		  const_iterator operator++( int );

		  /** @brief Post incremento ++ , it++
                      @return Devuelve el const_iterador
		      @post Incrementa el iterador para devolverlo
        	  */
		  const_iterator & operator++();

		  /** @brief Pre decremento -- , --it
         	      @return Devuelve el const_iterador
	              @post Decrementa el iterador despues de devolverlo
        	  */
	 	  const_iterator operator--(int);
		
		 /** @brief Post decremento -- , it--
                      @return Devuelve el const_iterador decrementado
		      @post Decrementa iterator
       		*/
		  const_iterator & operator--();

		  /** @brief Sobrecarga operator == de clase conjunto::const_iterator
        	   @return true , si son iguales , false , si son distintos
          */
		  bool operator==(const const_iterator & it);

		  /** @brief Sobrecarga operator == de clase conjunto::const_iterator
        	   @return false, si son iguales , true , si son distintos
          */
		  bool operator!=(const const_iterator & it);
		private:
		 
		  vector<entrada>::const_iterator c_itv;
		  friend class conjunto;
	  
	};

	/** @brief  
         @return Devuelve el const_iterator a la primera posición del conjunto.
	@post no modifica el diccionario
        */
	 const_iterator cbegin() const;

	/** @brief iterador al final
         @return Devuelve el iterador constante a la  posición final del conjunto.
	@post no modifica el diccionario
        */
	const_iterator cend() const;

	
//*********************************FIN_CONST_ITERATOR*************************







private:
 vector<crimen> vc; // vector que almacena los elementos del conjunto
 CMP comp;
 
 friend class iterator;
 friend class arrest_iterator;


 
 
 /** \invariant
 
 IR: rep ==> bool
 
\li Para todo i, 0 <= i < vc.size() se cumple
	vc[i].ID > 0;
\li Para todo i, 0 <= i < D.dic.size()-1 se cumple
	vc[i].ID< vc[i+1].ID

*/

	
  /** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
*/
  bool cheq_rep( ) const;
  
//  declaracion del operator<< como metodo amigo
  template <typename UMP>
  friend ostream &  operator << ( ostream & sal, const conjunto<CMP> & D);
 

};


/** @brief imprime todas las entradas del conjunto 
@post  No se modifica el conjunto.
@todo implementar esta funcion
	*/
template <typename CMP>
ostream &  operator << (ostream & sal, const conjunto<CMP> & D);

	
#include "../src/conjunto.hxx"
#endif
