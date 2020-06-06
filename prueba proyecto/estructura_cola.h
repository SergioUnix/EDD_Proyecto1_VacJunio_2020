#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>


using namespace std;

template <class T>
class estructura_cola {

	template <class T>
	class Nodo {
	public:

		T info;
		Nodo<T> *siguiente;
		Nodo(T Dato) // contructor de la clase Node
		{
			info = Dato;
		}
	};

private:
	Nodo<T> *cabeza;
	Nodo<T> *ultimo;
public:
	estructura_cola() { cabeza = 0; ultimo = 0; };  // el constructor de la clase pila
	//virtual ~estructura_cola(); // Este es el destructor
	bool estaVaciaCola();

	void insertar(T Dato);

	T extraer();
	void imprimir();

	std::string  cadena_grafic();
	void generar_abrir();

	int getTamano();


};


template <class T>
void estructura_cola<T>::insertar(T Dato) ////ingreso el puntaje y la letra
{
	Nodo<T> *nuevo = new Nodo<T>(Dato);
	nuevo->siguiente = 0;
	if (estaVaciaCola())
	{
		cabeza = nuevo;
		ultimo = nuevo;
	}
	else {
		ultimo->siguiente = nuevo;
		ultimo = nuevo;
	}
};

template <class T>
T estructura_cola<T>::extraer()
{
	if (!estaVaciaCola())
	{
		T informacion = cabeza->info;
		Nodo<T> *bor = cabeza;
		if (cabeza == ultimo)
		{
			cabeza = 0;
			ultimo = 0;
		}
		else
		{
			cabeza = cabeza->siguiente;
		}
		delete bor;
		return informacion;
	}
	else
		return "";
}

template <class T>
int estructura_cola<T>::getTamano()
{
	int result = 0;
	Nodo<T> *aux = cabeza;

	while (aux != 0)
	{
		result++;
		aux = aux->siguiente;
	}
	return result;
}

template <class T>
void estructura_cola<T>::imprimir()
{
	Nodo<T> *aux = cabeza;
	cout << "Listado de todos los elementos de la cola.\n";
	while (aux != 0)
	{
		cout << aux->info << "-";
		aux = aux->siguiente;
	}
	cout << "\n";
}




template <class T>
bool estructura_cola<T>::estaVaciaCola()
{
	if (cabeza == 0)
		return true;
	else
		return false;
}








template <class T>
std::string  estructura_cola<T>::cadena_grafic() {
	Nodo<T> *aux = cabeza;
	std::string  linea1 = "digraph G {\n nodesep=.05;\nrankdir = LR;\nlabel = \" <= == == = Direccion de la cola\" ;\nnode[fillcolor =darkorange1 , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\n";
	std::string ultimaLinea = "}\"];\n}";
	std::string nodos = "";
	int a = 0;
	while (aux != 0)
	{
		if (aux->siguiente == 0) { nodos = nodos + aux->info ; }
		else { nodos = nodos + aux->info + "|"; }

		


		aux = aux->siguiente;
		a++;
	}
	std::string grafo = linea1 + "node1[label=\"{" + nodos + ultimaLinea;
	return grafo;
};
template <class T>
void estructura_cola<T>::generar_abrir() {
	std::string texto = cadena_grafic();
	std::ofstream archivo;
	archivo.open("cola.txt", std::ios::out);

	archivo << texto;
	archivo.close();

	std::string sentencia = "dot -Tpng cola.txt -o cola.png";
	std::string sentencia2 = "start cola.png";
	std::string salir = "EXIT";
	system(sentencia.c_str());
	system(sentencia2.c_str());
	system(salir.c_str());


};
