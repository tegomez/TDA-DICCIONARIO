#include<iostream>
#include "src/Diccionario.h"

using namespace std;

int main() {
	Diccionario<string, int> *dicc = new Diccionario<string, int>();
	string personajes[] = { "Goro", "Goro", "Aang", "Goro", "Zuko", "Gaara","Kratos" };
	int vida[] = { 100, 70, 66, 99, 80, 90, 120 };

	bool fallo = false;
	for (int i = 0; i < 7; i++) {
		fallo = !dicc->guardar(personajes[i], vida[i]);
		if (fallo)
			cout << "El personaje: " << personajes[i] << " ya existe..." << endl;
	}

	dicc->imprimir();

	delete dicc;

}
