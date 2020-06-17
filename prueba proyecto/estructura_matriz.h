#pragma once
#include "estructura_arbol_valanceado.h"

template<class T>
class estructura_matriz
{

	class Nodo {
	public:
		Nodo(string departamentoX, string empresaY, T x, string pas)
		{
			//Aca inicializo los punteros en null que es igual a cero tambien
			this->next = 0;
			this->before = 0;
			this->up = 0;
			this->down = 0;
			this->z_front = 0;
			this->z_back = 0;
			//Aca voy a guardar los datos y el tipo que le ingresare
			this->x = departamentoX;
			this->y = empresaY;
			this->dato = x;
			this->pass = pas;
			//para el arbol balanceado
			this->activos_rentar = new estructura_arbol_valanceado<string>();

		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		Nodo *getUp() { return up; }
		Nodo *getDown() { return down; }
		Nodo *getZ_front() { return z_front; }
		Nodo *getZ_back() { return z_back; }
		string getX() { return x; }
		string getY() { return y; }

		void setNext(Nodo *n) { next = n; };
		void setBefore(Nodo *n) { before = n; };
		void setUp(Nodo *n) { up = n; };
		void setDown(Nodo *n) { down = n; };
		void setZ_front(Nodo *n) { z_front = n; };
		void setZ_back(Nodo *n) { z_back = n; };
		void setDato(T n) { dato = n; };
		void setX(string n) { x = n; };
		void setY(string n) { y = n; };
		T getDato() { return dato; }
		string getPass() { return pass; };

		//para el arbol balaceado
		estructura_arbol_valanceado<string> *getAVL() {return activos_rentar;};
		
	private:
		Nodo *next;    Nodo *before;
		Nodo *up;      Nodo *down;
		Nodo *z_front; Nodo *z_back;
		string x;    string y;
		T dato;  string pass;
		//para el arbol balanceado
		estructura_arbol_valanceado<string> *activos_rentar;

	};



public:
	estructura_matriz()
	{
		root = new Nodo("-1", "-1", "Root","");
		ano = 0;
		mes = 0;


	}



	// Este metodo me compara dos strings pero los compara haciendolos cadena de char primero porque se utiliza el metodo strcpy_s 
	// El cual me devuelve un int el cual me dice que orden alfabeticamente van los dos strings
	// Este codigo es totalmente mio, 
	int comparar(std::string a22, std::string b22) {

		string a = "";
		a = a + a22[0];
		a = a + a22[1];
		a = a + a22[2];
		string b = "";
		b= b + b22[0];
		b = b + b22[1];
		b = b + b22[2];

		//cout << " cadena a " << a << " cadena b " << b << endl;
		int n1 = a.length();
		int n2 = b.length();

		//Valor estatico porque visual estudio no me dejo meter una variable nose porque razon
		char char_a[100];
		char char_b[100];

		strcpy_s(char_a, a.c_str());
		strcpy_s(char_b, b.c_str());
		return strcmp(char_a, char_b);
	}



	
estructura_arbol_valanceado<string> * getArbol(string xx, string yy, T datorev, string pas) {
			string x = aMinuscula(xx);
			string y = aMinuscula(yy);
			string dato = aMinuscula(datorev);
			string pasword = aMinuscula(pas);

			Nodo* NodoCol = this->buscar_columna(x);
			Nodo* NodoFila = this->buscar_fila(y);

			Nodo*temporaldato = 0;
			bool result = false;

			if (NodoCol != 0 && NodoFila != 0) {
				//	std::cout << "Existe la coordenada  " << std::endl;

				while (NodoCol != 0) {

					if (comparar(NodoCol->getX(), x) == 0 && comparar(NodoCol->getY(), y) == 0) {
						temporaldato = NodoCol;

						while (temporaldato != 0) {
							if (temporaldato != 0) {

								//aca verifico si existe el dato
								if (comparar(temporaldato->getDato(), dato) == 0 && comparar(temporaldato->getPass(), pasword) == 0) {
									//	std::cout << "Se encontro el if del true en el while  " << std::endl;
									result = true;

									return temporaldato->getAVL();
									break;
								}

							}
							else {
								break;
							};
							temporaldato = temporaldato->getZ_back();

						};




						break;
					}
					NodoCol = NodoCol->getDown();






				}
			}
			return 0;


		};


////////////////////////  ///////////////////////////Mostrar Catalogo
void catalogo(string nombre,string pass) {
	Nodo* enX = this->root->getNext();

	Nodo* NodoCol = 0;
	Nodo*temporal = 0;
	//cout << "recibo datos " << nombre << " " << pass;
	while (enX != 0) {
		NodoCol = enX;
		while (NodoCol != 0) {
			temporal = NodoCol->getZ_back();
			//cout << " datos nodos " << NodoCol->getDato() << " " << NodoCol->getPass();
	//if (NodoCol->getDato() != nombre && NodoCol->getPass()!= pass) {
			if (NodoCol->getY() != "-1") {
				NodoCol->getAVL()->inOrderDisponible();
			}
			while (temporal != 0) {
			
				if (temporal != 0) {
			//if (temporal->getDato() != nombre && temporal->getPass() != pass) {
					temporal->getAVL()->inOrderDisponible();
			//}
					temporal = temporal->getZ_back();
				}else {	break;	};
			};
			
			NodoCol = NodoCol->getDown();
		}

		enX = enX->getNext();
	}
};




///Realizo No disponible en un activo atravez de cada AVL
void activoNoDisponible(string id_activo) {
	Nodo* enX = this->root->getNext();
	//Nodo* enY = this->root;
	Nodo* NodoCol = 0;
	Nodo*temporal = 0;

	while (enX != 0) {
		NodoCol = enX;
		while (NodoCol != 0) {
			temporal = NodoCol->getZ_back();
			//if (NodoCol->getDato()!=nombre  && NodoCol->getPass()!=pass) {
			if (NodoCol->getY() != "-1") {
				NodoCol->getAVL()->noDisponible(id_activo);
			}
			while (temporal != 0) {

				if (temporal != 0) {
					//if (comparar(NodoCol->getDato(), nombre) != 0 && comparar(NodoCol->getPass(), pass) != 0) {
					temporal->getAVL()->noDisponible(id_activo);
					//}
					temporal = temporal->getZ_back();
				}
				else { break; };
			};

			NodoCol = NodoCol->getDown();
		}

		enX = enX->getNext();
	}
};


////Cambiar a Disponible desde la matriz
void activoDisponible(string id_activo) {
	Nodo* enX = this->root->getNext();
	//Nodo* enY = this->root;
	Nodo* NodoCol = 0;
	Nodo*temporal = 0;

	while (enX != 0) {
		NodoCol = enX;
		while (NodoCol != 0) {
			temporal = NodoCol->getZ_back();
			//if (NodoCol->getDato()!=nombre  && NodoCol->getPass()!=pass) {
			if (NodoCol->getY() != "-1") {
				NodoCol->getAVL()->disponible(id_activo);
			}
			while (temporal != 0) {

				if (temporal != 0) {
					//if (comparar(NodoCol->getDato(), nombre) != 0 && comparar(NodoCol->getPass(), pass) != 0) {
					temporal->getAVL()->disponible(id_activo);
					//}
					temporal = temporal->getZ_back();
				}
				else { break; };
			};

			NodoCol = NodoCol->getDown();
		}

		enX = enX->getNext();
	}
};


//////  Aca imprimo todas las graficas de avl segun un departamento dado
void reporteDepartamento(string departamento) {
	string depa = aMinuscula(departamento);
	Nodo* enX = this->root->getNext();
	//Nodo* enY = this->root;
	Nodo* NodoCol = 0;
	Nodo*temporal = 0;
	int auxiliar = 0;

	string arboles_departamentos = "digraph departamentos{ \n";
	string arboles_final = "label = \"Reporte por Departamento \" ;\n}";


	while (enX != 0) {
		NodoCol = enX;
		while (NodoCol != 0) {
			temporal = NodoCol->getZ_back();
			//if (NodoCol->getDato()!=nombre  && NodoCol->getPass()!=pass) {
//todo la columna
			cout << " dato ingresado " << depa << "  dato del nodo " << NodoCol->getX() << endl;
if(NodoCol->getX()==depa){
			if (NodoCol->getY() != "-1") {
				arboles_departamentos = arboles_departamentos +NodoCol->getAVL()->texto_departamento(NodoCol->getDato(), std::to_string(auxiliar));
				auxiliar++;
			}
			while (temporal != 0) {

				if (temporal != 0) {
					//if (comparar(NodoCol->getDato(), nombre) != 0 && comparar(NodoCol->getPass(), pass) != 0) {
					arboles_departamentos = arboles_departamentos + temporal->getAVL()->texto_departamento(temporal->getDato(), std::to_string(auxiliar));
					auxiliar++;
					//}
					temporal = temporal->getZ_back();
				}
				else { break; };
			};
//todo la columna
}//pertenece a un depa en especifico
			NodoCol = NodoCol->getDown();
		}

		enX = enX->getNext();
	}
	string dot_total = arboles_departamentos + arboles_final;
	generar_txt_departamentos(dot_total);
};




//////  Aca imprimo todas las graficas de avl segun LA EMPRESA INGRESADA
void reporteEmpresa(string empresa) {
	string empre = aMinuscula(empresa);
	Nodo* enX = this->root->getNext();
	//Nodo* enY = this->root;
	Nodo* NodoCol = 0;
	Nodo*temporal = 0;
	int auxiliar = 0;

	string arboles_empresas = "digraph empresas{ \n";
	string arboles_final = "label = \"Reporte por Empresa \" ;\n}";


	while (enX != 0) {
		NodoCol = enX;
		while (NodoCol != 0) {
			temporal = NodoCol->getZ_back();
	
			cout << " dato ingresado " << empre << "  dato del nodo " << NodoCol->getY() << endl;
			if (NodoCol->getY() == empre) {
				if (NodoCol->getY() != "-1") {
					arboles_empresas = arboles_empresas +NodoCol->getAVL()->texto_departamento(NodoCol->getDato(), std::to_string(auxiliar));
					auxiliar++;
				}
				while (temporal != 0) {

					if (temporal != 0) {
						
						arboles_empresas = arboles_empresas +temporal->getAVL()->texto_departamento(temporal->getDato(), std::to_string(auxiliar));
						auxiliar++;
					temporal = temporal->getZ_back();
					}
					else { break; };
				};
				//todo la columna
			}//pertenece a una empresa  en especifico
			NodoCol = NodoCol->getDown();
		}

		enX = enX->getNext();
	}
	string dot_total = arboles_empresas + arboles_final;
	generar_txt_empresas(dot_total);
};






	Nodo* buscar_fila(string y) {
		Nodo *temp = this->root;

		while (temp != 0)
		{
		if (comparar(temp->getY(), y)==0) {
				return temp;
			}

			temp = temp->getDown();

		}
		return 0;
	};

	Nodo* buscar_columna(string x) {
		Nodo* temp = this->root;
		while (temp != 0) {
			if (comparar(temp->getX(), x) == 0) {
				return temp;
			}
			temp = temp->getNext();
		}
		return 0;


	};




	Nodo* insertar_ordenado_columna(Nodo *nuevo, Nodo* cabeza_col) {

		Nodo*temp = cabeza_col;
		bool bandera = false;
		while (true) {
			if (comparar(temp->getX(), nuevo->getX()) ==0) {
				temp->setY(nuevo->getY());
				temp->setDato(nuevo->getDato());
				return temp;

			}
			else if (comparar(temp->getX(),nuevo->getX()) ==1) {
				bandera = true;
				break;

			};
			if (temp->getNext() != 0) {
				temp = temp->getNext();
			}
			else {
				break;
			};
		};
		if (bandera == true) {
			nuevo->setNext(temp);
			temp->getBefore()->setNext(nuevo);
			nuevo->setBefore(temp->getBefore());
			temp->setBefore(nuevo);
		}
		else {
			temp->setNext(nuevo);
			nuevo->setBefore(temp);
		};
		return nuevo;
	};



	Nodo* insertar_ordenado_fila(Nodo *nuevo, Nodo* cabeza_fila) {
		Nodo*temp = cabeza_fila;
		bool bandera = false;
		while (true) {
			if (comparar(temp->getY(), nuevo->getY())==0) {
				temp->setX(nuevo->getX());
				temp->setDato(nuevo->getDato());
				return temp;

			}
			else if (comparar(temp->getY(), nuevo->getY()) ==1) {
				bandera = true;
				break;

			};
			if (temp->getDown() != 0) {
				temp = temp->getDown();
			}
			else {
				break;
			};
		};
		if (bandera == true) {
			nuevo->setDown(temp);
			temp->getUp()->setDown(nuevo);
			nuevo->setUp(temp->getUp());
			temp->setUp(nuevo);
		}
		else {
			temp->setDown(nuevo);
			nuevo->setUp(temp);
		};
		return nuevo;
	};





	Nodo* crear_columna(string x) {
		Nodo* cabeza_columna = this->root;
		Nodo* columna = this->insertar_ordenado_columna(new Nodo(x, "-1", "",""), cabeza_columna);

		return columna;
	}

	Nodo* crear_fila(string y) {
		Nodo* cabeza_fila = this->root;
		Nodo* fila = this->insertar_ordenado_fila(new Nodo("-1", y, "",""), cabeza_fila);

		return fila;
	}

	void insertar_Z(Nodo *nuevo, Nodo *NodoColumna, Nodo *NodoFila) {
		Nodo* enX = this->root;
		Nodo* enY = this->root;
		Nodo* NodoCol = 0;
        Nodo*temporal = 0;

		while (enX != 0) {
			if (comparar(enX->getX(),NodoColumna->getX())==0) {
				NodoCol = enX;
				while (NodoCol != 0) {

					if (comparar(NodoCol->getX(),nuevo->getX())==0 && comparar(NodoCol->getY(),nuevo->getY())==0) {
						//Aca encontro la coordena del nodo, ahora inserto en Z
					//	cout << " SE deberia de insertar en Z" << endl;
						temporal = NodoCol;

						//NodoCol->setZ_back(nuevo);

						
					while (temporal != 0) {
							if (temporal->getZ_back() != 0) {
								temporal = temporal->getZ_back();
							}
							else {
								break;
							};
						};

					temporal->setZ_back(nuevo);
					nuevo->setZ_front(temporal);



					break;
					}
					NodoCol = NodoCol->getDown();
				
				
				}

							
			}
			enX = enX->getNext();
		}		
	};



	//login

	bool login(string xx, string yy, T datorev, string pas) {
		string x = aMinuscula(xx);
		string y = aMinuscula(yy);
		string dato = aMinuscula(datorev);
		string pasword = aMinuscula(pas);

		Nodo* NodoCol = this->buscar_columna(x);
		Nodo* NodoFila = this->buscar_fila(y);

		Nodo*temporaldato = 0;
		bool result = false;

		if (NodoCol != 0 && NodoFila != 0) {
		//	std::cout << "Existe la coordenada  " << std::endl;
		
			while (NodoCol != 0) {

				if (comparar(NodoCol->getX(),x)==0 && comparar(NodoCol->getY(),y)==0) {
					temporaldato = NodoCol;

					while (temporaldato != 0) {
						if (temporaldato != 0) {
							
							//aca verifico si existe el dato
							if (comparar(temporaldato->getDato(),dato) == 0 && comparar(temporaldato->getPass(),pasword) ==0 ) {
							//	std::cout << "Se encontro el if del true en el while  " << std::endl;
								result = true;
								return true;
								break;
							}
							
						}
						else {
							break;
						};
             temporaldato = temporaldato->getZ_back();

					};




					break;
				}
				NodoCol = NodoCol->getDown();






			}
		}
		return result;


	};









	//Verifico si existen datos en esa coordenada , esto es para ingresar en Z
	//si encuentra que hay un nodo en esa coordenada (Departamento, Empresa)  entonces devuelve un true que en consola seria un 1
	//sino lo encuentra devuelve un false que en consola seria un 0

	bool verExistencia(Nodo *nuevo, Nodo *NodoColumna, Nodo *NodoFila) {
		bool result = false;
		//Nodo* temp = this->root;
		Nodo*NodoCol = NodoColumna;
		while (NodoCol != 0) {
			if (comparar(NodoCol->getX(), nuevo->getX()) == 0 && comparar(NodoCol->getY(), nuevo->getY()) == 0 ) {
				result = true;
			}
			NodoCol = NodoCol->getDown();
		}
		return result;
	};
	

	string aMinuscula(string cadena) {
		for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
		return cadena;
	}




	void  insertar_elemento(string xx, string yy, T datorev, string pas) {
		string x = aMinuscula(xx);
		string y = aMinuscula(yy);
		string dato = aMinuscula(datorev);
        string pasword = aMinuscula(pas);

		Nodo * nuevo = new Nodo(x, y, dato, pasword);
		Nodo* NodoColumna = this->buscar_columna(x);
		Nodo* NodoFila = this->buscar_fila(y);

		if (NodoColumna == 0 && NodoFila == 0) {
			 //    std::cout<< "Caso1"<<std::endl; //Solo me sirve para testear en que caso cae
			NodoColumna = this->crear_columna(x);
			//cout << NodoColumna->getX()<<" "<<NodoColumna->getX()<<endl;
			NodoFila = this->crear_fila(y);
			//cout << NodoFila->getX()<<" "<<NodoFila->getX()<<endl;
			nuevo = this->insertar_ordenado_columna(nuevo, NodoFila);
			nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
			return;

		}
		else if (NodoColumna == 0 && NodoFila != 0) {
			//   std::cout<< "Caso2"<<std::endl;   //Testeo nada mas
			NodoColumna = this->crear_columna(x);
			nuevo = this->insertar_ordenado_columna(nuevo, NodoFila);
			nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
			return;

		}
		else if (NodoColumna != 0 && NodoFila == 0) {
		  //  std::cout<< "Caso3"<<std::endl;  //Verifico en que caso cae
			NodoFila = this->crear_fila(y);
			nuevo = this->insertar_ordenado_columna(nuevo, NodoFila);
			nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
			return;

		}
		else if (NodoColumna != 0 && NodoFila != 0) {
		//	std::cout<< "Caso4"<<std::endl;
			//cout << NodoColumna->getX()<<" "<<NodoColumna->getDown()->getY()<<"  "<<NodoColumna->getDown()->getX()<<NodoFila->getDown()->getDato() <<endl;
			//cout << NodoFila->getY()<<" "<<NodoFila->getNext()->getX()<<"  "<<NodoFila->getNext()->getY()<<NodoFila->getNext()->getDato()<<endl;

			if (verExistencia(nuevo, NodoColumna, NodoFila) == 0) {
			nuevo = this->insertar_ordenado_columna(nuevo, NodoFila);
			nuevo = this->insertar_ordenado_fila(nuevo, NodoColumna);
			}
			else {

			
			//	cout << "Se repitio en el mismo Nodo  " << endl;
				insertar_Z(nuevo, NodoColumna, NodoFila);
			}

			//cout << "si imprime 1 es porque ya esta  " << verExistencia(nuevo, NodoColumna, NodoFila) << endl;


			
			return;

		}


	}

	std::string grafic() {
		std::string linea1 = "digraph Sparce_Matrix { \n";
		std::string linea2 = "node [shape=box]  \n";
		std::string linea3 = "Mt[ label = \"Raiz Matrix\", width = 1.5, style = filled, fillcolor = darkolivegreen3, group = 1 ];  \n";
		std::string linea4 = "/*nodos vacíos, necesarios para anular la ubicación de nodo predeterminada de graphiz  */ \n e0[ shape = point, width = 0 ];  \n";
		std::string linea5 = "e1[ shape = point, width = 0 ];   \n";


		/// aca se grafica el eje Y
		Nodo *temp1 = this->root->getDown();
		int j = 0;
		int comodin2 = -1;
		std::string primeroY = "";
		std::string linea6 = "";
		std::string linea7 = ""; ///links de Y
								 /// me ayuda  a recorrer en forma horizontal
		Nodo *recoX = this->root->getDown();
		/// Nodos fila
		std::string filas = "";
		std::string punteros_fila = "";
		std::string same = "";

		int comodin_fila = -1;
		/// recorre en el plano Z
		std::string Z = "";
		std::string punteros_Z = "";
		std::string sameZ = "";
		Nodo *recoXZ;
		int comodin_filaZ = -1;
		int auxiliar = 0;

		while (temp1 != 0)
		{
			recoX = temp1->getNext();
			while (recoX != 0) {
				if (comodin_fila<0) { punteros_fila = punteros_fila + "U" + temp1->getY() + "-> N" + recoX->getX() + recoX->getY() + "[dir=\"both\"]; \n";  same = same + "U" + temp1->getY() + ";";     comodin_fila += 1; }

				if (recoX != 0) {
					filas = filas + "N" + recoX->getX() + recoX->getY() + " [label = \"" + recoX->getDato() + "\" width = 1.5, group =" + recoX->getX() + " ];  \n";
					same = same + "N" + recoX->getX() + recoX->getY() + ";";
					//Si esto encuentra una cabecera hace lo siguiente, para que sea cabecera tiene que haber -1 como string
					if (recoX->getUp()->getY() == "-1") {
						punteros_fila = punteros_fila + "A" + recoX->getUp()->getX() + "-> N" + recoX->getX() + recoX->getY() + "[dir=\"both\"];\n";
					}
					else { //cuando no es cabecera ejecuta esto
						punteros_fila = punteros_fila + "N" + recoX->getX() + recoX->getY() + "-> N" + recoX->getUp()->getX() + recoX->getUp()->getY() + "; \n";
						punteros_fila = punteros_fila + "N" + recoX->getUp()->getX() + recoX->getUp()->getY() + "-> N" + recoX->getX() + recoX->getY() + "; \n";
					}
					// capta los que estan en Z ....

					recoXZ = recoX->getZ_back();
					while (recoXZ != 0) {
						if (comodin_filaZ<0) { punteros_Z = punteros_Z + "N" + recoXZ->getX() + recoXZ->getY() + "-> Z" + recoXZ->getX() + recoXZ->getY() + recoXZ->getDato()  + "[ arrowhead = \"empty\" color=green dir=\"both\" ]; \n";      comodin_filaZ += 1;
						}
						else {}


						Z = Z + "Z" + recoXZ->getX() + recoXZ->getY() + recoXZ->getDato()+ " [label = \"" + recoXZ->getDato() + "\" width = 1.5 ];  \n";
                   							if (recoXZ->getZ_back() != 0) {
								punteros_Z = punteros_Z + "Z" + recoXZ->getX() + recoXZ->getY() + recoXZ->getDato() + "-> Z" + recoXZ->getZ_back()->getX() + recoXZ->getZ_back()->getY() + recoXZ->getZ_back()->getDato() + "; \n";
								punteros_Z= punteros_Z + "Z" + recoXZ->getZ_back()->getX() + recoXZ->getZ_back()->getY() + recoXZ->getZ_back()->getDato() + "-> Z" + recoXZ->getX() + recoXZ->getY() + recoXZ->getDato() + "; \n";
							}
						recoXZ = recoXZ->getZ_back();
						auxiliar = auxiliar + 1;
					}
				  comodin_filaZ = -1;
					/////////////////////////

					if (recoX->getNext() != 0) {
						punteros_fila = punteros_fila + "N" + recoX->getX() + recoX->getY() + "-> N" + recoX->getNext()->getX() + recoX->getNext()->getY() + "; \n" + "N" + recoX->getNext()->getX() + recoX->getNext()->getY() + "-> N" + recoX->getX() + recoX->getY() + "; \n";

					}
				}
				else { break; }


				recoX = recoX->getNext();
			}
			punteros_fila = punteros_fila + "{ rank = same; " + same + "} \n";
			same = "";



			if (comodin2<0) {
				primeroY = "U" + temp1->getY();
				comodin2 += 1;

			}

			linea6 = linea6 + "U" + temp1->getY() + "[label = \"" + temp1->getY() + "\" width = 1.5 style = filled, fillcolor = thistle2, group =" + "1" + "];  \n";
			if (temp1->getDown() != 0) {
				linea7 = linea7 + "U" + temp1->getY() + "-> U" + temp1->getDown()->getY() + "; \n" + "U" + temp1->getDown()->getY() + "-> U" + temp1->getY() + "; \n";

			}


			j += 1;
			temp1 = temp1->getDown();

			comodin_fila = -1;

		}
		std::string same_completo = "{ rank = same; " + same + "} \n";



		Nodo *temp = this->root->getNext();
		int i = 0;
		int comodin = -1;
		std::string primeroX = "";
		std::string linea8 = "";
		std::string linea9 = "";
		std::string para_linea11 = "";
		/// Nodos fila
		std::string columnas = "";
		std::string punteros_columna = "";
		int comodin_columna = -1;
		while (temp != 0)
		{

			if (comodin<0) {
				primeroX = "A" + temp->getX();
				comodin += 1;

			}

			linea8 = linea8 + "A" + temp->getX() + "[label = \"" + temp->getX() + "\" width = 1.5 style = filled, fillcolor = turquoise3, group =" + temp->getX() + "];  \n";
			if (temp->getNext() != 0) {
				linea9 = linea9 + "A" + temp->getX() + "-> A" + temp->getNext()->getX() + "; \n" + "A" + temp->getNext()->getX() + "-> A" + temp->getX() + "; \n";
			}
			para_linea11 = para_linea11 + "A" + temp->getX() + "; ";
			i += 1;
			temp = temp->getNext();
			comodin_columna = -1;

		}


		std::string linea10 = "Mt -> " + primeroY + "[dir=\"both\"]; Mt -> " + primeroX + "[dir=\"both\"]; \n";
		std::string linea11 = "{ rank = same; Mt;" + para_linea11 + "} \n";

		std::string subgrafo = "subgraph cluster_0 {   style = filled; charset = latin1; bgcolor = black; color = white; node[fillcolor =lemonchiffon , fontcolor = black , color = darkolivegreen3 ,style = filled, shape = record];label = \"Ejes en Z\"; ";

		std::string total = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 + linea10 + linea11 + filas + punteros_fila+subgrafo + Z + punteros_Z +"}"+ "}";
		return total;
	}

	void generar_txt() {
		std::string texto = grafic();
		std::ofstream archivo;
		archivo.open("Matriz.txt", std::ios::out);

		archivo << texto;
		archivo.close();

		std::string sentencia = "dot -Tpng Matriz.txt -o Matriz.png";
		std::string sentencia2 = "start Matriz.png";
		system(sentencia.c_str());
		system(sentencia2.c_str());


	}
	void generar_txt_departamentos(string departamento) {
		std::string texto = departamento;
		std::ofstream archivo;
		archivo.open("reporte_departamento.txt", std::ios::out);

		archivo << texto;
		archivo.close();

		std::string sentencia = "dot -Tpng reporte_departamento.txt -o reporte_departamento.png";
		std::string sentencia2 = "start reporte_departamento.png";
		system(sentencia.c_str());
		system(sentencia2.c_str());


	}	void generar_txt_empresas(string empresa) {
		std::string texto = empresa;
		std::ofstream archivo;
		archivo.open("reporte_empresa.txt", std::ios::out);

		archivo << texto;
		archivo.close();

		std::string sentencia = "dot -Tpng reporte_empresa.txt -o reporte_empresa.png";
		std::string sentencia2 = "start reporte_empresa.png";
		system(sentencia.c_str());
		system(sentencia2.c_str());


	}



private:
	int ano;
	int mes;

	Nodo * root;




};



