#pragma once
#include<string.h>
#include<fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>


class estructura_circular
{
	class Nodo {
	public:
		Nodo(std::string x, std::string act,std::string usu,std::string dep,std::string fec,std::string tie,string emp)
		{
			next = 0;
			before = 0;
			dato = x;
			activo = act;
			usuario = usu;
			departamento = dep;
			fecha = fec;
			tiempo = tie;
			empresa = emp;

		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }

		std::string getDato() { return dato; }
		std::string getActivo() { return activo; }
		std::string getUsuario() { return usuario; }
		std::string getDepartamento() { return departamento; }
		std::string getFecha() { return fecha; }
		std::string getTiempo() { return tiempo; }
		std::string getEmpresa() { return empresa; }



	private:
		Nodo *next;
		Nodo *before;
		std::string dato;
		std::string activo;
		std::string usuario;
		std::string departamento;
		std::string fecha;
		std::string tiempo;
		std::string empresa;




	};
	/////////////////////sigue la lista
public:
	estructura_circular()
	{
		first = 0;
		last = 0;
		size = 0;

		firstO = 0;
		lastO = 0;
		sizeO = 0;
	}

	int getSize() { return size; }
	void add_ordenado(std::string datos, string act, string usu, string dep, string fec, string tie, std::string emp);
	void add_first(std::string datos, string act, string usu, string dep, string fec, string tie, std::string emp);
	void add_first_(std::string datos, string act, string usu, string dep, string fec, string tie, std::string emp);
	void add_last(std::string datos, string act, string usu, string dep, string fec, string tie, std::string emp);
	void add_last_(std::string datos, string act, string usu, string dep, string fec, string tie, std::string emp);
	void add_at(std::string datos, string act, string usu, string dep, string fec, string tie, std::string emp, int index);
	void remove_at(int index);
	std::string remove_cadena(string cadena);
	void limpiar();
	bool exist(std::string cadena);
	std::string grafic();
	void generar_txt();
	std::string get_element_at(int index);
	void lista_imprimir();

	//para el reporte 
	std::string grafic_reporte(string nom, string dep, string emp);
	void generar_txt_reporte(string nom, string dep,string emp);
	//para el ordenamiento
	void orden();
	std::string grafic_();
	void generar_txt_();

	bool usuarioTransaccion(string nombre,string departamento,string empresa);



	string aMinuscula(string cadena) {
		for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
		return cadena;
	}



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




private:
	bool isEmpty() { return size == 0; }
	int size;
	Nodo *first;
	Nodo *last;

	bool isEmptyO() { return sizeO == 0; }
	int sizeO;
	Nodo *firstO;
	Nodo *lastO;
};

void estructura_circular::limpiar()
{
	this->size = 0;
	this->first = 0;
	this->last = 0;



}










void estructura_circular::add_ordenado(std::string datos,std::string act,std::string usu,std::string dep,std::string fec,std::string tie, std::string emp)
{
	string dato = aMinuscula(datos); string activo = aMinuscula(act);
	string usuario = aMinuscula(usu); string departamento = aMinuscula(dep); string fecha = aMinuscula(fec); string tiempo = aMinuscula(tie);
	string empresa = aMinuscula(emp);
	Nodo *n = new Nodo(dato,activo,usuario,departamento,fecha,tiempo,empresa);
	Nodo *aux = this->first;
	bool bandera = false;

	if (this->isEmpty())
	{
		this->first = n;
		this->last = n;
		this->size++;
	}
	else
	{

		while (true) {
			if (this->comparar(aux->getDato(), n->getDato())>0) {   ///// verifica que dato va despues , ordena los strings y si levanta una bandera
																	//std::cout<<"comparo  ----------------------------------- "<<this->comparar(aux->getDato(),n->getDato())<<"---"<<aux->getDato()<<"--"<<n->getDato()<<this->getSize()<<std::endl;
																	// std::cout<<"comparo  ----------------------------------- "<<aux->getDato()<<std::endl;

				bandera = true;
				break;
			}
			if (aux->getNext() == this->first || aux->getNext() == 0) { break; } ///si llega aca ya llego al ultimo nodo
			aux = aux->getNext();


		}

		if (aux == this->first&&bandera == true && this->getSize() == 1) {
			n->setNext(this->first);
			this->first->setBefore(n);
			this->first = n;
			this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es estructura_circular
			this->size++;


		}
		else if (aux == this->last&&bandera == false && this->getSize() == 1) {
			this->last->setNext(n);
			n->setBefore(this->last);
			this->last = n;
			this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es estructura_circular
			this->first->setBefore(this->last);
			this->size++;

		}
		else if (aux == this->last&&bandera == true && this->getSize()>1) {
			n->setNext(aux);
			n->setBefore(aux->getBefore());
			aux->getBefore()->setNext(n);
			aux->setBefore(n);
			this->size++;


		}
		else if (aux == this->last&&bandera == false && this->getSize()>1) {
			this->last->setNext(n);
			n->setBefore(this->last);
			this->last = n;
			this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es estructura_circular
			this->first->setBefore(this->last);
			this->size++;

		}
		else if (aux == this->first&&bandera == true && this->getSize()>1) {

			n->setNext(this->first);
			this->first->setBefore(n);
			this->first = n;
			this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es estructura_circular
			this->last->setNext(this->first);

			this->size++;
		}
		else if (bandera == true && this->getSize()>1) {
			n->setNext(aux);
			n->setBefore(aux->getBefore());
			aux->getBefore()->setNext(n);
			aux->setBefore(n);
			this->size++;

		}
		else {
		}


	}
}

void estructura_circular::add_first(std::string datos, std::string act, std::string usu, std::string dep, std::string fec, std::string tie, std::string emp)
{
	string dato = aMinuscula(datos); string activo = aMinuscula(act);
	string usuario = aMinuscula(usu); string departamento = aMinuscula(dep); string fecha = aMinuscula(fec); string tiempo = aMinuscula(tie);
	string empresa = aMinuscula(emp);

	Nodo *n = new Nodo(dato, activo, usuario, departamento, fecha, tiempo,empresa);
	if (this->isEmpty())
	{
		this->first = n;
		this->last = n;
		this->size++;
	}
	else
	{
		n->setNext(this->first);
		this->first->setBefore(n);
		this->first = n;
		this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es estructura_circular
		this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primeroo porque es estructura_circular
		this->size++;
	}
}

void estructura_circular::add_last(std::string datos, std::string act, std::string usu, std::string dep, std::string fec, std::string tie, std::string emp)
{
	string dato = aMinuscula(datos); string activo = aMinuscula(act);
	string usuario = aMinuscula(usu); string departamento = aMinuscula(dep); string fecha = aMinuscula(fec); string tiempo = aMinuscula(tie);
	string empresa = aMinuscula(emp);
	if (this->isEmpty())
	{
		this->add_first(dato, activo, usuario, departamento, fecha, tiempo,empresa);
	}
	else
	{
		Nodo *n = new Nodo(dato, activo, usuario, departamento, fecha, tiempo,empresa);
		this->last->setNext(n);
		n->setBefore(this->last);
		this->last = n;
		this->last->setNext(this->first); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es estructura_circular
		this->first->setBefore(this->last); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es estructura_circular
		this->size++;
	}
}

void estructura_circular::add_at(std::string datos, std::string act, std::string usu, std::string dep, std::string fec, std::string tie, std::string emp, int index)
{

	string dato = aMinuscula(datos); string activo = aMinuscula(act);
	string usuario = aMinuscula(usu); string departamento = aMinuscula(dep); string fecha = aMinuscula(fec); string tiempo = aMinuscula(tie);
	string empresa = aMinuscula(emp);
	if (index >= 0 && index <= this->size)
	{
		if (index == 0) { this->add_first(dato, activo, usuario, departamento, fecha, tiempo,empresa); return; }
		if (index == this->size) { this->add_last(dato, activo, usuario, departamento, fecha, tiempo,empresa); return; }
		Nodo *aux = this->first;
		int x = 0;
		while (aux != 0)
		{
			if (x == index) { break; }
			aux = aux->getNext();
			x++;
		}
		Nodo *n = new Nodo(dato, activo, usuario, departamento, fecha, tiempo,empresa);
		aux->getBefore()->setNext(n);
		n->setBefore(aux->getBefore());
		n->setNext(aux);
		aux->setBefore(n);
		this->size++;
	}
}

std::string estructura_circular::get_element_at(int index)
{

	int help = index;
	while (help >= this->size) {
		help = help - this->size;
	}
	while (help<0) {
		help = help + this->size;
	}

	if (help >= 0 && help < size)
	{
		Nodo *iterador = this->first;
		int x = 0;
		for (int k = 0; k < this->size; k++) {
			if (help == x) { return iterador->getDato(); break; }
			iterador = iterador->getNext();
			x++;
		}
	}
	return "";
}


void estructura_circular::lista_imprimir()
{
	std::string result;
	for (int j = 0; j<this->size - 1; j++) {
		result = result + get_element_at(j) + "  --  ";
	}
	std::cout << result << std::endl;

}



/////verifica si existe la cadena dentro de la estructura
bool estructura_circular::exist(std::string cadena)
{
	bool result = false;

	Nodo *node = this->first;
	int x = 1;
	while (true)
	{
		if (cadena == node->getDato()) { result = true; return true; }
		x++;
		if (node->getNext() == this->first || node->getNext() == 0) { break; }
		node = node->getNext();
	}

	return result;
}


///transacciones de un Usuario
/////verifica si existe la cadena dentro de la estructura
bool estructura_circular::usuarioTransaccion(string nom, string dep, string emp)
{
	string nombre = aMinuscula(nom);
	string departamento = aMinuscula(dep);
	string empresa = aMinuscula(emp);
	bool result = false;

	Nodo *node = this->first;
	int x = 1;
	while (node!=0)
	{
	//	cout << "datos ingresado : " << nombre << "  " << departamento << "  " << empresa << endl;
		//cout << "datos en nodos " << node->getUsuario() << " " << node->getDepartamento() << " " << node->getEmpresa();
			if (comparar(node->getUsuario(),nombre)==0 && comparar(node->getDepartamento(), departamento) == 0 && comparar(node->getEmpresa(), empresa) == 0) {
			cout << "Id transaccion: " << node->getDato() << " Realizo la Renta: " << node->getUsuario() << " Id renta: " << node->getActivo();
			cout << " Departamento: " << node->getDepartamento() << " Empresa: " << node->getEmpresa() << " Fecha: " << node->getFecha();
			cout << " TiempoRenta: " << node->getTiempo() <<endl<<endl;
			result = true; 
		}
		x++;
		if (node->getNext() == this->first || node->getNext() == 0) { break; }
		node = node->getNext();
	}

	return result;
}

///Elimino dado un String pero devuelvo un alfanumerico del activo para eliminarlo tambien
std::string estructura_circular::remove_cadena(std::string cadena)
{
	std::string result = "";

	Nodo *node = this->first;
	int x = 0;
	while (true)
	{
		if (cadena == node->getDato()) { result = node->getActivo(); remove_at(x); return result; }
		x++;
		if (node->getNext() == this->first || node->getNext() == 0) { break; }
		node = node->getNext();

	}

	return result;
}







void estructura_circular::remove_at(int index)
{
	if (index >= 0 && index < this->size)
	{ 
		if (index == 0 && size == 1) { limpiar(); return; }
		if (index == 0 && size > 0) { Nodo *aux = this->first->getNext();  aux->setBefore(this->last); this->first = aux;   this->last->setNext(this->first);    this->size--;    return; }
		if (index == this->size - 1) { Nodo *aux = this->last->getBefore();  aux->setNext(this->first); this->last = aux;       this->size--;             return; }
		Nodo *aux = this->first;
		int x = 0;
		while (aux != 0)
		{
			if (x == index) { break; }
			aux = aux->getNext();
			x++;
		}
		if (aux != 0) {
			aux->getBefore()->setNext(aux->getNext());
			aux->getNext()->setBefore(aux->getBefore());
			this->size--;
		}
	}

	// return 0;
}

std::string estructura_circular::grafic()
{
	std::string linea1 = " digraph G {\n";
	std::string linea2 = "nodesep=.02;\n";
	std::string linea3 = "rankdir=LR;\n";
	std::string linea4 = "node[fillcolor =cyan , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\nlabel = \"Lista Circular\" ;\n";
	std::string linea5 = "";
	std::string linea6 = "node [width =1.5];\n";

	Nodo *node = this->first;
	//node =self.head
	int index = 1;
	std::string nodos = "";
	std::string direccion = "";

	// if(aux->getNext()==this->first||aux->getNext()==0){break;} ///si llega aca ya llego al ultimo nodo
	//      aux=aux->getNext();

	while (node!=0) {
		nodos = nodos + "node" + std::to_string(index) + "[label = \"{<n> |{" + node->getDato() +"|"+ node->getUsuario() +"|"+node->getDepartamento() + "|" + node->getEmpresa() + "|" + node->getActivo() + "}| <p> }\"];\n";
		

		if (index == 1 && size ==1) {
			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index) + ":n;\n";
		}
		else if (index == 1) {
			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(this->size) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
		}
		else if (index == this->size) {
			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index - 1) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(1) + ":n;\n";
		}
		else {

			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index - 1) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
		}
		index = index + 1;

		if (node->getNext() == this->first || node->getNext() == 0) { break; }
		node = node->getNext();

	}

	std::string lineafinal = "}\n";
	std::string grafo = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + nodos + direccion + lineafinal;
	return grafo;

}


void estructura_circular::generar_txt() {
	//if (size > 0) {
		std::string texto = grafic();
		std::ofstream archivo;
		archivo.open("circular.txt", std::ios::out);

		archivo << texto;
		archivo.close();

		std::string sentencia = "dot -Tpng circular.txt -o circular.png";
		std::string sentencia2 = "start circular.png";
		std::string salir = "EXIT";
		system(sentencia.c_str());
		system(sentencia2.c_str());
		system(salir.c_str());
	//}


};



/////// Generar Reporte


std::string estructura_circular::grafic_reporte(string nom,string dep, string emp)
{
	this->firstO = 0;
		this->sizeO = 0;
		this->lastO = 0;



	Nodo *node = this->first;
	//int index = 1;

	while (node != 0) {
//	cout << "datos ingresados   " << nom << " " << dep << " " << emp << endl;
		if (node->getUsuario() == nom && node->getDepartamento() == dep && node->getEmpresa() == emp) {
		
			add_first_(node->getDato(), node->getActivo(), node->getUsuario(), node->getDepartamento(), node->getFecha(), node->getTiempo(), node->getEmpresa());
		}
		if (node->getNext() == this->first || node->getNext() == 0) { break; }
		node = node->getNext();

	}
	
	


	std::string linea1 = " digraph G {\n";
	std::string linea2 = "nodesep=.02;\n";
	std::string linea3 = "rankdir=LR;\n";
	std::string linea4 = "node[fillcolor =cyan , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\nlabel = \"Lista Circular\" ;\n";
	std::string linea5 = "";
	std::string linea6 = "node [width =1.5];\n";

	Nodo *nodes = this->firstO;
	//node =self.head
	int index = 1;
	std::string nodos = "";
	std::string direccion = "";

	std::string primer = "";
	std::string ultimo = "";

	// if(aux->getNext()==this->first||aux->getNext()==0){break;} ///si llega aca ya llego al ultimo nodo
	//      aux=aux->getNext();

	while (nodes != 0) {

			nodos = nodos + "node" + std::to_string(index) + "[label = \"{<n> |{" + nodes->getDato() + "|" + nodes->getUsuario() + "|" + nodes->getDepartamento() + "|" + nodes->getEmpresa() + "|" + nodes->getActivo() + "}| <p> }\"];\n";


			if (index == 1 && sizeO == 1) {
				direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index) + ":p;\n";
				direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index) + ":n;\n";
			}
			else if (index == 1) {
				direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(this->sizeO) + ":p;\n";
				direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
			}
			else if (index == this->sizeO) {
				direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index - 1) + ":p;\n";
				direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(1) + ":n;\n";
			}
			else {

				direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index - 1) + ":p;\n";
				direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
			}

	

			index = index + 1;

			if (nodes->getNext() == this->firstO || nodes->getNext() == 0) { break; }
			nodes = nodes->getNext();

		}

		std::string lineafinal = "}\n";
		std::string grafo = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + nodos + direccion + lineafinal;
		return grafo;

}



void estructura_circular::generar_txt_reporte(string nom, string dep,string emp) {
	//if (size > 0) {
	std::string texto = grafic_reporte(nom,dep,emp);
	std::ofstream archivo;
	archivo.open("circular.txt", std::ios::out);

	archivo << texto;
	archivo.close();

	std::string sentencia = "dot -Tpng circular.txt -o circular.png";
	std::string sentencia2 = "start circular.png";
	std::string salir = "EXIT";
	system(sentencia.c_str());
	system(sentencia2.c_str());
	system(salir.c_str());
	//}


};







///ordenamiento

void estructura_circular::orden()
{

	this->firstO = 0;
	this->sizeO = 0;
	this->lastO = 0;


	Nodo *node = this->first;
	int index = 1;
	
	while (node != 0) {

		add_first_(node->getDato(),node->getActivo(), node->getUsuario(), node->getDepartamento(),node->getFecha(),node->getTiempo(),node->getEmpresa());

		if (node->getNext() == this->first || node->getNext() == 0) { break; }	
		node = node->getNext();

	}


}


void estructura_circular::add_first_(std::string datos, std::string act, std::string usu, std::string dep, std::string fec, std::string tie, std::string emp)
{
	string dato = aMinuscula(datos); string activo = aMinuscula(act);
	string usuario = aMinuscula(usu); string departamento = aMinuscula(dep); string fecha = aMinuscula(fec); string tiempo = aMinuscula(tie);
	string empresa = aMinuscula(emp);

	Nodo *n = new Nodo(dato, activo, usuario, departamento, fecha, tiempo, empresa);
	if (this->isEmptyO())
	{
		this->firstO = n;
		this->lastO = n;
		this->sizeO++;
	}
	else
	{
		n->setNext(this->firstO);
		this->firstO->setBefore(n);
		this->firstO = n;
		this->firstO->setBefore(this->lastO); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es estructura_circular
		this->lastO->setNext(this->firstO); // aca seteo el puntero ultimo puntero para que apunte hacia el primeroo porque es estructura_circular
		this->sizeO++;
	}
}





void estructura_circular::add_last_(std::string datos, std::string act, std::string usu, std::string dep, std::string fec, std::string tie, std::string emp)
{
	string dato = aMinuscula(datos); string activo = aMinuscula(act);
	string usuario = aMinuscula(usu); string departamento = aMinuscula(dep); string fecha = aMinuscula(fec); string tiempo = aMinuscula(tie);
	string empresa = aMinuscula(emp);
	if (this->isEmptyO())
	{
		this->add_first_(dato, activo, usuario, departamento, fecha, tiempo, empresa);
	}
	else
	{
		Nodo *n = new Nodo(dato, activo, usuario, departamento, fecha, tiempo, empresa);
		this->lastO->setNext(n);
		n->setBefore(this->lastO);
		this->lastO = n;
		this->lastO->setNext(this->firstO); // aca seteo el puntero ultimo puntero para que apunte hacia el primero porque es estructura_circular
		this->firstO->setBefore(this->lastO); // aca seteo el puntero primer puntero para que apunte hacia el ultimo porque es estructura_circular
		this->sizeO++;
	}
}










std::string estructura_circular::grafic_()
{

	std::string linea1 = " digraph G {\n";
	std::string linea2 = "nodesep=.02;\n";
	std::string linea3 = "rankdir=LR;\n";
	std::string linea4 = "node[fillcolor =cyan , fontcolor = navy , color = darkolivegreen3 ,style = filled, shape = record, width = .1, height = .1];\nlabel = \"Lista Circular\" ;\n";
	std::string linea5 = "";
	std::string linea6 = "node [width =1.5];\n";

	Nodo *node = this->firstO;
	//node =self.head
	int index = 1;
	std::string nodos = "";
	std::string direccion = "";

	// if(aux->getNext()==this->firstO||aux->getNext()==0){break;} ///si llega aca ya llego al ultimo nodo
	//      aux=aux->getNext();

	while (node != 0) {
		nodos = nodos + "node" + std::to_string(index) + "[label = \"{<n> |{" + node->getDato() + "|" + node->getUsuario() + "|" + node->getDepartamento() + "|" + node->getEmpresa() + "|" + node->getActivo() + "}| <p> }\"];\n";


		if (index == 1 && sizeO == 1) {
			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index) + ":n;\n";
		}
		else if (index == 1) {
			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(this->sizeO) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
		}
		else if (index == this->sizeO) {
			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index - 1) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(1) + ":n;\n";
		}
		else {

			direccion = direccion + "node" + std::to_string(index) + ":n -> node" + std::to_string(index - 1) + ":p;\n";
			direccion = direccion + "node" + std::to_string(index) + ":p -> node" + std::to_string(index + 1) + ":n;\n";
		}
		index = index + 1;

		if (node->getNext() == this->firstO || node->getNext() == 0) { break; }
		node = node->getNext();

	}

	std::string lineafinal = "}\n";
	std::string grafo = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + nodos + direccion + lineafinal;
	return grafo;

}


void estructura_circular::generar_txt_() {
	//if (size > 0) {
	std::string texto = grafic_();
	std::ofstream archivo;
	archivo.open("circular_ordenado.txt", std::ios::out);

	archivo << texto;
	archivo.close();

	std::string sentencia = "dot -Tpng circular_ordenado.txt -o circular_ordenado.png";
	std::string sentencia2 = "start circular_ordenado.png";
	std::string salir = "EXIT";
	system(sentencia.c_str());
	system(sentencia2.c_str());
	system(salir.c_str());
	//}


};
