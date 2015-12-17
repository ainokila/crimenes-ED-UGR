/* 
 * conjunto.h
 * 
 * Copyright  (C) Juan F. Huete
*/

#ifndef __CONJUNTO_H
#define __CONJUNTO_H
#include <string>
#include <vector>
#include <iostream> 

#include "crimen.h"

using namespace std;


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
	class arrest_iterator;
	
	
	class fechaCreciente {
	public:
	  bool operator()(const entrada & a, const entrada &  b){
	    return a.getDate() > b.getDate();
	   }
	    
	};
	
	class fechaDecreciente {
	public:
	  bool operator()(const entrada & a, const entrada &  b){
	    return (a.getDate() < b.getDate());
	   }
	    
	};

	/** @brief constructor primitivo. 
	@post define la entrada nula como el par ("",-1)
	*/
	conjunto( );
	

	/** @brief constructor de copia
	@param[in] d conjunto a copiar
	*/
	conjunto (const conjunto & d);
		
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


	int busquedaBinaria(const long int & e) const;


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






//*********************************INICIO_ARRESTO_ITERATOR*************************

/** @brief class arrest_iterator
	 * forward iterador de arrestos sobre el diccionario, Lectura 
	 *  arrest_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
	 * */
	class arrest_iterator {
		public:

	 /** @brief Constructor por defecto de arrest_iterator
		   */

		  arrest_iterator();

	 /** @brief Constructor de Copia
		      @param it , tipo arrest_iterator
		  */

		  arrest_iterator(const arrest_iterator & it);

	/** @brief Constructor con parametro iterator tipo vector<entrada>::iterator
	              @param n ,iterator tipo vector<entrada>
		  */

		  arrest_iterator(const vector<conjunto::entrada>::iterator n);
		
      /** @brief Devuelve el valor del iterador actual
                      @return conjunto::entrada , valor actual del iterator
                  */	

		  const conjunto::entrada & operator*() const;

	  /** @brief Pre incremento ++ , ++it
         	      @return Devuelve el arrest_iterator
	              @post Incrementa el iterador despues de devolverlo
        	  */
	
		  arrest_iterator operator++( int );

	  /** @brief Post incremento ++ , it++
                      @return Devuelve el arrest_iterator
		      @post Incrementa el iterador para devolverlo
        	  */

		  arrest_iterator & operator++();
	
	/** @brief Pre decremento -- , --it
         	      @return Devuelve el arrest_iterator
	              @post Decrementa el iterador despues de devolverlo
        	  */

         	  arrest_iterator operator--(int);

	/** @brief Post decremento -- , it--
                      @return Devuelve el arrest_iterator
		      @post Decrementa el iterador para devolverlo
        	  */

		  arrest_iterator & operator--();

	  /** @brief Sobrecarga operator == de clase conjunto::arrest_iterator
        	   @return true , si son iguales , false , si son distintos
                   */

		  bool operator==(const arrest_iterator & it);

	/** @brief Sobrecarga operator == de clase conjunto::arrest_iterator
        	   @return false, si son iguales , true , si son distintos
                  */

		  bool operator!=(const arrest_iterator & it);
		
		private:
		 
		  vector<entrada>::iterator a_itv;
		  friend class conjunto;

	/**
		@brief ptr puntero al propio conjunto para permitirme realizar
		operaciones auxiliares necesarias en este iterador
		*/

		  const conjunto * ptr; 
	  
	};
	/** @brief  
		 @return Devuelve el arrest_iterator a la primera posición del conjunto.
		@post no modifica el diccionario
		*/
    
		  arrest_iterator abegin() ;

	/** @brief iterador al final
         @return Devuelve el iterador arresto a la  posición final del conjunto.
	@post no modifica el diccionario
        */

		  arrest_iterator aend();

//*********************************FIN_ARRESTO_ITERATOR*************************







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
  friend ostream &  operator << ( ostream & sal, const conjunto & D);
 

};


/** @brief imprime todas las entradas del conjunto 
@post  No se modifica el conjunto.
@todo implementar esta funcion
	*/
template <typename CMP>
ostream &  operator << (ostream & sal, const typename conjunto<CMP> & D);

	
#include "../src/conjunto.hxx"
#endif
