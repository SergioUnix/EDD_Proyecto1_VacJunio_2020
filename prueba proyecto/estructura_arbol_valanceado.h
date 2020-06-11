#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


class estructura_arbol_valanceado {


	class Nodo {
	public:
		int Info;
		int FactorEquilibrio;


		Nodo *Node_Izquierdo;
		Nodo *Node_Derecho;
		Nodo *Node_papa;

		Nodo(const int datos, Nodo *father = 0, Nodo *iquierdo = 0, Nodo *derecho = 0) {
			Node_Izquierdo = iquierdo;
			Node_Derecho = derecho;

			FactorEquilibrio = 0;
			Info = datos;
			Node_papa = father;

		}



	};

private:	
	Nodo *root;
	Nodo *node_presente;
    enum { Tipo_Izquierdo, Tipo_Derecho };
public:
	estructura_arbol_valanceado() : root(0), node_presente(0) {}
	~estructura_arbol_valanceado() { limpiarArbol(root); }
	std::string grafico = "";
	std::string direcciones = "";
	std::string  texto = "";
	void Insertar(const int datos);
	bool buscarDato(const int datos);
	void eliminar_dato(const int datos);
	bool verifico_vacio(Nodo *r) {
		return r == 0;
	}
	bool EsHoja(Nodo *r) {
		return !r->Node_Derecho && !r->Node_Izquierdo;
	}
	std::string  texto_grafic();
	void generar_grafico();
	void Raiz() { node_presente = root; }
	void recorrido_grap(Nodo *node, std::string lado, std::string Node_papa);
	void recorrido_inOrder(Nodo * node);
	void inOrder();



private:

	void equilibrio(Nodo *nodo, int, bool);
	void rotacion_derecha_izquierda(Nodo* nodo);
	void rotacion_derecha_derecha(Nodo* nodo);
	void rot_simple_izquierda(Nodo* nodo);
	void rot_simple_derecha(Nodo* nodo);
	void limpiarArbol(Nodo* &);
	

};


void estructura_arbol_valanceado::limpiarArbol(Nodo* &nodo)
{
	if (nodo != nullptr) {
		limpiarArbol(nodo->Node_Izquierdo);
		limpiarArbol(nodo->Node_Derecho);
		delete nodo;
		nodo = 0;
	}
}



void estructura_arbol_valanceado::Insertar(const int datos)
{
	Nodo *Node_papa = 0;

	cout << "Insertando : " << datos << endl;
	node_presente = root;

	while (!verifico_vacio(node_presente) && datos != node_presente->Info) {
		Node_papa = node_presente;
		if (datos > node_presente->Info) node_presente = node_presente->Node_Derecho;
		else if (datos < node_presente->Info) node_presente = node_presente->Node_Izquierdo;
	}


	if (!verifico_vacio(node_presente)) return;


	if (verifico_vacio(Node_papa)) root = new Nodo(datos);


	else if (datos < Node_papa->Info) {
		Node_papa->Node_Izquierdo = new Nodo(datos, Node_papa);
		equilibrio(Node_papa, Tipo_Izquierdo, true);
	}


	else if (datos > Node_papa->Info) {
		Node_papa->Node_Derecho = new Nodo(datos, Node_papa);
		equilibrio(Node_papa, Tipo_Derecho, true);
	}
}


void estructura_arbol_valanceado::equilibrio(Nodo *nodo, int rama, bool nuevo)
{
	bool salir = false;


	while (nodo && !salir) {
		if (nuevo)
			if (rama == Tipo_Izquierdo) nodo->FactorEquilibrio--;
			else                  nodo->FactorEquilibrio++;
		else
			if (rama == Tipo_Izquierdo) nodo->FactorEquilibrio++;
			else                  nodo->FactorEquilibrio--;
			if (nodo->FactorEquilibrio == 0) salir = true;


			else if (nodo->FactorEquilibrio == -2) {
				if (nodo->Node_Izquierdo->FactorEquilibrio == 1) rotacion_derecha_derecha(nodo);
				else rot_simple_derecha(nodo);
				salir = true;
			}
			else if (nodo->FactorEquilibrio == 2) {
				if (nodo->Node_Derecho->FactorEquilibrio == -1) rotacion_derecha_izquierda(nodo);
				else rot_simple_izquierda(nodo);
				salir = true;
			}
			if (nodo->Node_papa)
				if (nodo->Node_papa->Node_Derecho == nodo) rama = Tipo_Derecho; else rama = Tipo_Izquierdo;
			nodo = nodo->Node_papa;
	}
}

void estructura_arbol_valanceado::rotacion_derecha_derecha(Nodo* nodo)
{
	cout << "rotacion_derecha_derecha" << endl;
	Nodo *Node_papa = nodo->Node_papa;
	Nodo *P = nodo;
	Nodo *Q = P->Node_Izquierdo;
	Nodo *R = Q->Node_Derecho;
	Nodo *B = R->Node_Izquierdo;
	Nodo *C = R->Node_Derecho;

	if (Node_papa)
		if (Node_papa->Node_Derecho == nodo) Node_papa->Node_Derecho = R;
		else Node_papa->Node_Izquierdo = R;
	else root = R;

	Q->Node_Derecho = B;
	P->Node_Izquierdo = C;
	R->Node_Izquierdo = Q;
	R->Node_Derecho = P;

	R->Node_papa = Node_papa;
	P->Node_papa = Q->Node_papa = R;
	if (B) B->Node_papa = Q;
	if (C) C->Node_papa = P;

	switch (R->FactorEquilibrio) {
	case -1: Q->FactorEquilibrio = 0; P->FactorEquilibrio = 1; break;
	case 0:  Q->FactorEquilibrio = 0; P->FactorEquilibrio = 0; break;
	case 1:  Q->FactorEquilibrio = -1; P->FactorEquilibrio = 0; break;
	}
	R->FactorEquilibrio = 0;
}


void estructura_arbol_valanceado::rotacion_derecha_izquierda(Nodo* nodo)
{
	cout << "rotacion_derecha_izquierda" << endl;
	Nodo *Node_papa = nodo->Node_papa;
	Nodo *P = nodo;
	Nodo *Q = P->Node_Derecho;
	Nodo *R = Q->Node_Izquierdo;
	Nodo *B = R->Node_Izquierdo;
	Nodo *C = R->Node_Derecho;

	if (Node_papa)
		if (Node_papa->Node_Derecho == nodo) Node_papa->Node_Derecho = R;
		else Node_papa->Node_Izquierdo = R;
	else root = R;

	P->Node_Derecho = B;
	Q->Node_Izquierdo = C;
	R->Node_Izquierdo = P;
	R->Node_Derecho = Q;

	R->Node_papa = Node_papa;
	P->Node_papa = Q->Node_papa = R;
	if (B) B->Node_papa = P;
	if (C) C->Node_papa = Q;

	switch (R->FactorEquilibrio) {
	case -1: P->FactorEquilibrio = 0; Q->FactorEquilibrio = 1; break;
	case 0:  P->FactorEquilibrio = 0; Q->FactorEquilibrio = 0; break;
	case 1:  P->FactorEquilibrio = -1; Q->FactorEquilibrio = 0; break;
	}
	R->FactorEquilibrio = 0;
}


void estructura_arbol_valanceado::rot_simple_derecha(Nodo* nodo)
{
	cout << "rot_simple_derecha" << endl;
	Nodo *Node_papa = nodo->Node_papa;
	Nodo *P = nodo;
	Nodo *Q = P->Node_Izquierdo;
	Nodo *B = Q->Node_Derecho;
	if (Node_papa)
		if (Node_papa->Node_Derecho == P) Node_papa->Node_Derecho = Q;
		else Node_papa->Node_Izquierdo = Q;
	else root = Q;

	P->Node_Izquierdo = B;
	Q->Node_Derecho = P;
	P->Node_papa = Q;
	if (B) B->Node_papa = P;
	Q->Node_papa = Node_papa;

	P->FactorEquilibrio = 0;
	Q->FactorEquilibrio = 0;
}


void estructura_arbol_valanceado::rot_simple_izquierda(Nodo* nodo)
{
	cout << "rot_simple_izquierda" << endl;
	Nodo *Node_papa = nodo->Node_papa;
	Nodo *P = nodo;
	Nodo *Q = P->Node_Derecho;
	Nodo *B = Q->Node_Izquierdo;

	if (Node_papa)
		if (Node_papa->Node_Derecho == P) Node_papa->Node_Derecho = Q;
		else Node_papa->Node_Izquierdo = Q;
	else root = Q;


	P->Node_Derecho = B;
	Q->Node_Izquierdo = P;


	P->Node_papa = Q;
	if (B) B->Node_papa = P;
	Q->Node_papa = Node_papa;


	P->FactorEquilibrio = 0;
	Q->FactorEquilibrio = 0;
}

//Este recorrido InOrder se uso para la Tarea en Clase que dejo el ingeniro Espino
void estructura_arbol_valanceado::recorrido_inOrder(Nodo * node) {
	if (!node) {
		return;
	}
	recorrido_inOrder(node->Node_Izquierdo); //se va por la Izquierda
	std::cout << std::to_string(node->Info) << " - "; // concateno los nodos
	recorrido_inOrder(node->Node_Derecho);//Se va por la derecha
}

void estructura_arbol_valanceado::inOrder() {
	recorrido_inOrder(root);
	std::cout << "\n";

}



void estructura_arbol_valanceado::eliminar_dato(const int datos)
{
	Nodo *Node_papa = 0;
	Nodo *nodo;
	int aux;

	node_presente = root;

	while (!verifico_vacio(node_presente)) 
	{
		if (datos == node_presente->Info) 
		{
	    if (EsHoja(node_presente))
		{
		if (Node_papa)
		if (Node_papa->Node_Derecho == node_presente) Node_papa->Node_Derecho = 0;
		else if (Node_papa->Node_Izquierdo == node_presente) Node_papa->Node_Izquierdo = 0;
		delete node_presente;
		node_presente = 0;

		if ((Node_papa->FactorEquilibrio == 1 &&   Node_papa->Node_Derecho == node_presente ) ||
		(Node_papa->FactorEquilibrio == -1 &&Node_papa->Node_Izquierdo == node_presente )) {
		Node_papa->FactorEquilibrio = 0;
		node_presente = Node_papa;
		Node_papa = node_presente->Node_papa;
		}
		if (Node_papa)
		if (Node_papa->Node_Derecho == node_presente) equilibrio(Node_papa, Tipo_Derecho, false);
		else                         equilibrio(Node_papa, Tipo_Izquierdo, false);
		return;
		}
		else {
		Node_papa = node_presente;
		
		if (node_presente->Node_Derecho) {
		nodo = node_presente->Node_Derecho;
		while (nodo->Node_Izquierdo) {
		Node_papa = nodo;
		nodo = nodo->Node_Izquierdo;
		}
		}

		else {
		nodo = node_presente->Node_Izquierdo;
		while (nodo->Node_Derecho) {
		Node_papa = nodo;
		nodo = nodo->Node_Derecho;
		}
		}

		aux = node_presente->Info;
		node_presente->Info = nodo->Info;
		nodo->Info = aux;
		node_presente = nodo;
		}
		}
		else {
		Node_papa = node_presente;
		if (datos > node_presente->Info) node_presente = node_presente->Node_Derecho;
		else if (datos < node_presente->Info) node_presente = node_presente->Node_Izquierdo;
		}
	}
}



bool estructura_arbol_valanceado::buscarDato(const int datos)
{
	node_presente = root;
	while (!verifico_vacio(node_presente)) {
		if (datos == node_presente->Info) return true;
		else if (datos > node_presente->Info) node_presente = node_presente->Node_Derecho;
		else if (datos < node_presente->Info) node_presente = node_presente->Node_Izquierdo;
	}
	return false;
}


/////////////////////////   Crear txt de ghrapviz

void estructura_arbol_valanceado::recorrido_grap(Nodo * node, string lado, string Node_papa) {
	if (!node) {


		return;
	}
	if (lado == "root") {
		direcciones = "";  //el if lo que hace es que si esta llenas estas variables me las borre y haga una nueva asignacion, esto es porque c++ guarda su valor aun
		grafico = "";
	}


	recorrido_grap(node->Node_Izquierdo, "0", std::to_string(node->Info)); //se va por la Izquierda

	if (lado != "root"&& Node_papa != "root") { direcciones = direcciones + Node_papa + ":C" + lado + "->" + std::to_string(node->Info) + "\n"; } ////if que guarda las direcciones de los nodos
	grafico = grafico + std::to_string(node->Info) + "[ label =\"<C0>|" + std::to_string(node->Info) + "|<C1>\"]; \n"; // concateno los nodos

	recorrido_grap(node->Node_Derecho, "1", std::to_string(node->Info));//Se va por la derecha




}






std::string  estructura_arbol_valanceado::texto_grafic() {
	grafico = "";
	direcciones = "";
	recorrido_grap(root, "root", "root");
	string linea1 = "digraph grafica{ \nrankdir=TB; \nnode[fillcolor =cyan , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\nlabel = \"Arbol Balanceado estructura_arbol_valanceado\" ;\n";
	return linea1 + grafico + direcciones + "} \n";
	std::cout << std::endl;

}


void estructura_arbol_valanceado::generar_grafico() {
	texto = texto_grafic();


	std::ofstream archivo;
	archivo.open("Arbol_Balanceado.txt", std::ios::out);

	archivo << texto;
	archivo.close();

	std::string sentencia = "dot -Tpng Arbol_Balanceado.txt -o Arbol_Balanceado.png";
	std::string sentencia2 = "start Arbol_Balanceado.png";
	system(sentencia.c_str());
	system(sentencia2.c_str());



}