#ifndef SRC_DICCIONARIO_H_
#define SRC_DICCIONARIO_H_

#include "./ABB.h"
#include <iostream>

template<class K, class T>
class Diccionario {
private:
	//Atributos

	ABB<K, T> *abb;

public:
	//Metodos

	Diccionario();

	T obtener_dato(K clave);

	bool guardar(K clave, T data);

	bool pertenece(K clave);

	T borrar(K clave);

	void imprimir();

	~Diccionario();
};

template<class K, class T>
Diccionario<K, T>::Diccionario() {
	this->abb = new ABB<K, T>();
}

template<class K, class T>
T Diccionario<K, T>::obtener_dato(K clave) {
	if (!this->abb->buscar(clave))
		return NULL;

	return this->abb->get_dato(clave);

}

template<class K, class T>
bool Diccionario<K, T>::pertenece(K clave) {
	return this->abb->buscar(clave);
}

template<class K, class T>
bool Diccionario<K, T>::guardar(K clave, T data) {
	if (this->pertenece(clave))
		return false;

	return this->abb->insertar(clave, data);
}

template<class K, class T>
T Diccionario<K, T>::borrar(K clave) {
	return this->abb->borrar(clave);
}

template<class K, class T>
void Diccionario<K, T>::imprimir() {
	this->abb->imprimir_in_order();
}

template<class K, class T>
Diccionario<K, T>::~Diccionario() {
	delete this->abb;
}

#endif /* SRC_DICCIONARIO_H_ */
