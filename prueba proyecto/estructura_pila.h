#pragma once
#include <string>


template <class T>
class estructura_pila
{
	template <class T> //Creo esta clase Nodo dentro de la clase pila 
	class Node
	{
	public:
		T dato_generico;
		Node* siguiente_node; //Siempre habra un siguiente
		void setDato(T n) { dato_generico = n; }
		T getDato() { return dato_generico; }
		Node(T Dato) // contructor de la clase Node
		{
			dato_generico = Dato;
			siguiente_node = 0;
		}
	};



public:

    Node<T>* head_pila;

	estructura_pila() { head_pila = 0; };  // el constructor de la clase pila
	//virtual ~estructura_pila(); // Este es el destructor


	

	//metodos que puedo implementar
	void imprimir_pila();
	void push(T dato_generico);
	void pop();
	std::string  cadena_grafic();
	void generar_abrir();


};

//Solo imprime la pila
template<class T>
void estructura_pila<T>::imprimir_pila()
{
	Node<T>* tmp = head_pila;
	while (tmp != 0)
	{
		std::cout << tmp->dato_generico << " ";
		tmp = tmp->siguiente_node;
	}
	std::cout << "\n";

}

//metodo que ingreso el dato
template<class T>
void estructura_pila<T>::push(T dato_generico) {
	if (head_pila == 0) head_pila = new Node<T>(dato_generico);
	else
	{
		Node<T>* tmp = head_pila;
		head_pila = new Node<T>(dato_generico);
		head_pila->siguiente_node = tmp;
	}
}

//Metodo que quita un dato
template<class T>
void estructura_pila<T>::pop() {
	if (head_pila != 0)
	{
		Node<T>* tmp = head_pila;
		head_pila = head_pila->siguiente_node;
		delete tmp;
	}
}

// Creo la cadena del .dot para crear la grafica de Ghapviz
template<class T>
std::string  estructura_pila<T>::cadena_grafic() {
	//Empiezo a Graficar en Graphiz
	std::string cad1 = "digraph G {\n nodesep=.05;\nrankdir = L;\nnode[fillcolor =aquamarine2 , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\nnode2[label=\"{ Cabeza de la pila }\"];\nnode2->node1;\n ";
	int index = 0;
	std::string nodos = "";
	Node<T> *tmp = head_pila;
		
	while (tmp != 0) {  // mientras no sea null avanzo
		if (tmp->siguiente_node == 0) { nodos = nodos + tmp->getDato(); }
		else {nodos = nodos + tmp->getDato() + "|";}
		
		index = index + 1;
		tmp = tmp->siguiente_node;
		
	}
	std::string grafo = cad1 + "node1[label=\"{" + nodos + "}\"];\n}";
	return grafo;

};

// Aca genero el txt y luego abro el png
template<class T>
void estructura_pila<T>::generar_abrir() {
	std::string texto = cadena_grafic();
	std::ofstream archivo;
	archivo.open("realizados.txt", std::ios::out);
	archivo << texto;
	archivo.close();
	std::string sentencia = "dot -Tpng realizados.txt -o realizados.png";
	std::string sentencia2 = "start realizados.png";
	std::string salir = "EXIT";
	system(sentencia.c_str());
	system(sentencia2.c_str());
	system(salir.c_str());


};