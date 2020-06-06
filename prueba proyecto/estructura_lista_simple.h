#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class estructura_lista_simple
{
	class Node_lista {
	public:
		Node_lista(std::string x)
		{
			siguiente_node = 0;
			info = x;
		}

		Node_lista *getNext() { return siguiente_node; }
		void setNext(Node_lista *n) { siguiente_node = n; }
		std::string getDato() { return info; }

		void mostrar_lista()
		{
			std::cout << info << " -> ";
		}

		Node_lista *siguiente_node;

	private:

		std::string info;

	};

public:
	estructura_lista_simple()
	{
		first = 0;
		size = 0;
	}

	int getTamano() { return size; }
	void add_en_orden(std::string info);
	void add_al_inicio(std::string info);
	void add_al_final(std::string info);

	
	// Este metodo me compara dos strings pero los compara haciendolos cadena de char primero porque se utiliza el metodo strcpy_s 
	// El cual me devuelve un int el cual me dice que orden alfabeticamente van los dos strings
	// Este codigo es totalmente mio, 
	int comparar(std::string a, std::string b) {
		int n1 = a.length();
		int n2 = b.length();

		//Valor estatico porque visual estudio no me dejo meter una variable nose porque razon
		char char_a[100];
		char char_b[100];

		strcpy_s(char_a, a.c_str());
		strcpy_s(char_b, b.c_str());
		return strcmp(char_a, char_b);
	}





	void mostrar_lista()
	{
		Node_lista *temp = this->first;
		if (this->isEmpty()) {
			cout << "La estructura_lista_simple está vacía " << endl;
		}
		else {
			while (temp) {
				temp->mostrar_lista();
				if (temp->getNext() == 0) cout << "null";
				temp = temp->siguiente_node;
			}
		}
		cout << endl << endl;
	}




	std::string cadena_grafic()
	{
		std::string cad1 = "digraph G {\nnodesep=.02;\nrankdir=LR;\n";
		std::string cad2 = "node[fillcolor =cyan , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\nlabel = \"Lista Simple\" ;\n";
		std::string cad3 = "";
		Node_lista *node = this->first;
		int index = 1;
		std::string nodos = "";
		std::string direccion = "";
		while (node != 0) {
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
			nodos = nodos + "node" + std::to_string(index) + "[label = \"{<n>" + node->getDato() + "| <p> }\"];\n";
			index = index + 1;	node = node->getNext();
		}
		nodos = nodos + "node" + to_string(index) + "[label = \"null\",width=0.5];\n";
		string grafo = cad1 + cad2 + cad3 + nodos + direccion + "}";
		return grafo;


	}



	void generar_abrir() {
		std::string texto = cadena_grafic();
		std::ofstream archivo;
		archivo.open("list_Simple.txt", std::ios::out);
		archivo << texto;
		archivo.close();
		std::string sentencia = "dot -Tpng list_Simple.txt -o list_Simple.png";
		std::string sentencia2 = "start list_Simple.png";
		system(sentencia.c_str());
		system(sentencia2.c_str());
	}




private:
	bool isEmpty() { return size == 0; }
	int size;
	Node_lista *first;
};



void estructura_lista_simple::add_al_inicio(std::string info)
{
	Node_lista *n = new Node_lista(info);
	if (this->isEmpty())
	{
		this->first = n;
		this->size++;
	}
	else
	{
		n->setNext(this->first);

		this->first = n;
		this->size++;
	}
}





void estructura_lista_simple::add_al_final(std::string info)
{
	Node_lista *n = new Node_lista(info);
	Node_lista *aux = this->first;
	Node_lista *aux_ant = 0;
	bool bandera = false;
	if (this->isEmpty())
	{
		this->first = n;
		this->size++;
	}
	else
	{
		while (true) {
			if (aux->getNext() == 0) { break; }
			aux = aux->getNext();
		}
		aux->setNext(n);
		this->size++;
	}
}








void estructura_lista_simple::add_en_orden(std::string info)
{
	Node_lista *n = new Node_lista(info);
	Node_lista *aux = this->first;
	Node_lista *aux_ant = 0;
	bool bandera = false;
	if (this->isEmpty())
	{
		this->first = n;
		this->size++;
	}
	else
	{

		while (true) {

			if (this->comparar(aux->getDato(), n->getDato())>0) {
				bandera = true;
				break;
			}
			if (aux->getNext() == 0) { break; }

			aux_ant = aux;
			aux = aux->getNext();
		}

		if (aux == this->first&&bandera == true) {
			n->setNext(this->first);
			this->first = n;
			this->size++;

		}
		else if (bandera == true && this->getTamano()>1) {

			aux_ant->setNext(n);
			n->setNext(aux);
			this->size++;


		}
		else {
			aux->setNext(n);
			this->size++;
		}


	}
}









