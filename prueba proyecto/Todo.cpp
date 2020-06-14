#include <iostream>
#include <conio.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>       /* time */
#include "estructura_pila.h"
#include "estructura_cola.h"
#include "estructura_lista_simple.h"
#include "estructura_matriz.h"
#include "estructura_arbol_valanceado.h"

using namespace std;


//matriz de toda la aplicacion
estructura_matriz <string> *Users = new estructura_matriz<string>();

//string usuario_logueado = "Madelyn";string pass_logueado = "123456";string departamento_logueado = "Guatemala";string empresa_logueado = "Profutbol";
string usuario_logueado = "Ariel"; string pass_logueado = "123456"; string departamento_logueado = "Jutiapa"; string empresa_logueado = "Campero";
//string usuario_logueado = "Sergio"; string pass_logueado = "123456"; string departamento_logueado = "Zacapa"; string empresa_logueado = "Despensa";


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



string alfanumerico() {
	char numeros[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	string codigo_random = "";
	int numeric1, numeric2, numeric3;
	/* numeros random */
	srand(time(NULL));
	numeric1 = 10 + rand() % (98 - 10); //2
	numeric2 = 101 + rand() % (198 - 101);//3
	numeric3 = 101 + rand() % (298 - 201);//3
	codigo_random = codigo_random + numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] +  to_string(numeric1)+numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] + to_string(numeric2) + numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] + to_string(numeric3);
	//cout<< " numero : " << codigo_random << endl;
	return codigo_random;
}





// Menu de Administrador 
void menu_admin() {

	int  opcion, contador = 0, rep;
	char nombre[30], pass[30],departamento[30],empresa[30];
	//bool veri;

	do {
		system("cls");
		cout << "<<<<<<  Menu de la Aplicacion  >>>>>>" << endl << endl;
		cout << "1. Registrar Usuario" << endl;
		cout << "2. Reporte Matriz Dispersa " << endl;
		cout << "3. Reporte Activos Disponibles de un Departamento" << endl;
		cout << "4. Reporte Activos Disponibles de una empresa" << endl;
		cout << "5. Reporte Transacciones" << endl;
		cout << "6. Reporte Activos de un Usuario" << endl;
		cout << "7. Activos rentados por un Usuario" << endl;
		cout << "8. Ordenar Transacciones" << endl;
		cout << "9. Cerrar Sesion " << endl << endl;
		cout << "Ingresa Opcion : ";
		cin >> opcion;

		switch (opcion) {
		case 1:  system("cls");
			cout << "<<<<<<  Ingresar Datos del Usuario  >>>>>>" << endl << endl;
			cout << "Ingresar el Nombre : " << endl;
			cin >> nombre;
			cout << "Ingresar el Password : " << endl;
			cin >> pass;
			cout << "Ingresar el Departamento :  " << endl;
			cin >> departamento;
			cout << "Ingresara la Empresa : " << endl;
			cin >> empresa;
			if (Users->login(departamento, empresa, nombre, pass)) {
				system("cls");
				cout << "Usuario Ya Existe : " << endl;  system("pause");
			}
			else {
				Users->insertar_elemento(departamento, empresa, nombre, pass);
				system("cls");
				cout << "Usuario Registrado Exitosamente : " << endl;  system("pause");
			}


			break;
		case 2: system("cls");
			Users->generar_txt();
			break;
		case 3:			
			break;
		case 5:    system("cls");
			break;
		case 6:
			cout << "\n";
			system("pause");
			break;
		case 7: cout << "mostrar el arbol\n\n";

			cout << "\n";
			system("pause");
		}
		system("cls");
	} while (opcion != 9);
}



//////////////////////////////////////////////////////Menu para usuarios normales

void menu_usuario() {

	int  opcion, contador = 0, rep;
	char nom[30], usuario[30],descripcion[30],id[30];
	char activo[30], dias[30], nom_activo[30];
	Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->Insertar(alfanumerico(), "edific", "jajajajafdsa");
	system("pause");
	Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->Insertar(alfanumerico(), "edificio", "nifdsnguna");
	system("pause");
	Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->Insertar(alfanumerico(), "edificiodsa", "ffffy");
	system("pause");
	do {
		system("cls");
		cout << "<<<<<<  Menu de la Aplicacion  >>>>>>" << "       Bienvenido :" << usuario_logueado << endl << endl;
		cout << "1. Agregar Activo" << endl;
		cout << "2. Eliminar Activo" << endl;
		cout << "3. Modificar Activo" << endl;
		cout << "4. Renta Activo" << endl;
		cout << "5. Activos Rentados" << endl;
		cout << "6. Mis Activos Rentados" << endl;
		cout << "7. Cerrar Sesion " << endl << endl;
		cout << "Ingresa Opcion : ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:  system("cls");

			cout << "Ingresar el Nombre : " << endl;
			cin.ignore();
			cin.getline(nom_activo, 30, '\n');
			cout << "Ingresar Descripcion " << endl;
			cin.getline(descripcion, 30, '\n');


		Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->Insertar(alfanumerico(),nom_activo,descripcion);
		Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->generar_grafico();
		//	ArbolSt.Insertar("aklskf142", "edificio1", "este es un inmueble");


			break;
		case 2: system("cls");
			system("cls");
			cout << "<<<<<<<<<<<<<< Muestra de Activos Disponibles >>>>>>>>>>>>>" << endl;
			Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->inOrder();
			cout << "\nIngresar Id del activo a eliminar " << endl;
			cin.ignore();
			cin.getline(id, 30, '\n');
			cout << "Eliminando Activo " << endl;
			Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->eliminar_dato(std::string(id));
			Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->generar_grafico();
			system("pause");
			break;
		case 3:system("cls");
			cout << "Activos Disponibles a Modificar " << endl;
			Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->inOrder();
			cout << "\nIngresar Id del activo a Modificar " << endl;
			cin.ignore();
			cin.getline(id, 30, '\n');
			cout << "\nNueva Descripcion :" << endl;
			cin.getline(descripcion, 30, '\n');
			Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->actualizar(std::string(id),std::string(descripcion));
		//	cout << "Modificando Activo Activo " << endl;

			system("pause");
			break;
		case 4:    system("cls");


			do {
				cout << "--------   Catalogo de Activos   -----------" << endl;
				Users->catalogo(usuario_logueado,pass_logueado);
				
				cout << "\n\n1. Rentar Activo " << endl;
				cout << "2. Salir del SubMenu" << endl << endl;
				cout << "Ingresar Opcion : " << endl;
				cin >> rep;
				switch (rep) {
				case 1:
					cout << "Ingresar Activo a Rentar  " << endl;
					cin.ignore();
					cin.getline(activo, 30, '\n');

					cout << "Mostrar Activo a modificar , graficar el cubo para ver " << endl;
					Users->generar_txt();

					cout << "Ingresar Dias por Rentar  " << endl;
					cin.getline(dias, 30, '\n');

					break;
			}
				system("cls");
			} while (rep != 2);
			cout << "\n";
			system("pause");


			break;
		case 5: system("cls");


			do {
				cout << "--------    Lista Activos Rentados   -----------" << endl;


				cout << "1. Registrar Devolucion " << endl;
				cout << "2. Salir del SubMenu" << endl << endl;
				cout << "Ingresar Opcion : " << endl;
				cin >> rep;
				switch (rep) {
				case 1:
					cout << "Ingresar Activo a Devolver  " << endl;
					cin.ignore();
					cin.getline(activo, 30, '\n');

					cout << "Mostrar Activo a Devolver  " << endl;

					system("pause");

					break;
				}
				system("cls");
			} while (rep != 2);
			cout << "\n";
			system("pause");



			break;
		case 6:  system("cls");
				
				cout << "--------    Mis Activos Rentados   -----------" << endl;


			system("pause");


			break;
		}
		system("cls");
	} while (opcion != 7);
}





void login() {

	int  opcion, contador = 0, rep;
	char nombre_login[30], pass_login[30];
	char departamento_login[30], empresa_login[30];
	//bool veri;

	do {
		system("cls");
		cout << "<<<<<<  Bienvenidos a la Aplicacion  >>>>>>" << endl << endl;
		cout << "1. Loguearse " << endl;
		cout << "4. Salir " << endl << endl;
		cout << "Ingresa Opcion : ";
		cin >> opcion;

		switch (opcion) {
		case 1:  system("cls");
			cout << "<<<<<<  Ingresar Datos del Usuario  >>>>>>" << endl << endl;
			cout << "Ingresar el Nombre : " << endl;
			cin.ignore();
			cin.getline(nombre_login,30, '\n');			
			cout << "Ingresar el Password : " << endl;
		 	cin.getline(pass_login, 30, '\n');			
			cout << "Ingresar el Departamento :  " << endl;
			cin.getline(departamento_login, 30, '\n');
			cout << "Ingresara la Empresa : " << endl;
			cin.getline(empresa_login, 30, '\n');				
			//cout << "variables captadas : " <<nombre_login <<" "<<pass_login<<" "<<departamento_login<<" "<<empresa_login << endl;

			system("pause");
			if (comparar(std::string(nombre_login), "admin") == 0 && comparar(std::string(pass_login), "admin") == 0 && comparar(std::string(departamento_login), "admin") == 0 && comparar(std::string(empresa_login), "admin") == 0)
			{
				system("cls");
				cout << "El Usuario Administrador : " << endl;
				menu_admin();
			}else if(Users->login(std::string(departamento_login), std::string(empresa_login), std::string(nombre_login), std::string(pass_login))==true){
				system("cls");
				cout << "Usuario Logueado : " << endl;  system("pause");
				menu_usuario();
			}
			else { system("cls"); cout << "El Usuario no Existe : " << endl; system("pause"); }

			break;
		case 2: system("cls");
			




			

			break;

				}
		system("cls");
	} while (opcion != 4);
}






















int main()
{
Users->insertar_elemento("Guatemala", "Profutbol", "Madelyn","123456");
Users->insertar_elemento("Zacapa", "Despensa", "Sergio","123456");
Users->insertar_elemento("Jutiapa", "Campero", "Ariel","123456");
Users->insertar_elemento("Progreso", "Cemaco", "Lorena", "123456");

Users->getArbol("Zacapa", "Despensa", "Sergio", "123456")->Insertar(alfanumerico(), "ediSergio", "DescriSergio");
system("pause");
Users->getArbol("Zacapa", "Despensa", "Sergio", "123456")->Insertar(alfanumerico(), "ediSergio22", "DescriSergio22");
system("pause");
Users->getArbol("Jutiapa", "Campero", "Ariel", "123456")->Insertar(alfanumerico(), "ediAriel", "DescriAriel");
system("pause");
Users->getArbol("Progreso", "Cemaco", "Lorena", "123456")->Insertar(alfanumerico(), "ediLorena", "DescriLorena");
system("pause");

	//login();

//alfanumerico();

menu_usuario();

	//cout << " /////////////////////  datos de la pila" << endl;
	estructura_pila<std::string> * pil = new estructura_pila<std::string>();
	pil->push("elemento 1");
	pil->push("elemento 2");
	pil->push("elemento 3");
	pil->push("elemento 4");
	//pil->imprimir_pila();
	//pil->pop();
	//pil->imprimir_pila();
	//cout << pil->cadena_grafic() << endl;
//	pil->generar_abrir();


	//cout << " /////////////////////  datos de la cola " << endl;
	estructura_cola<std::string> *prueba = new estructura_cola<std::string>();
	prueba->insertar("primer dato");
	prueba->insertar("segundo dato");
	prueba->insertar("tercer dato");
	prueba->insertar("cuarto dato");
	//cout << " boolean de la cola " << true << endl;
	//prueba->imprimir();
	//prueba->extraer();
	
	//cout << prueba->cadena_grafic() << endl;
	//prueba->generar_abrir();


	//cout << " /////////////////////  prueba de lista Simple ordenada " << endl << endl;
	estructura_lista_simple *lista = new estructura_lista_simple();
	lista->add_en_orden("Heidy");
	lista->add_en_orden("Carlos");
	lista->add_en_orden("Antonio");
	lista->add_en_orden("Eduardo");
	lista->add_en_orden("Rodrigo");
	//lista->mostrar_lista();
	//cout<<lista->cadena_grafic() << endl;
	//lista->generar_abrir();  
	


	
	

	// Un árbol de enteros
	estructura_arbol_valanceado<int> Arbol; 
	//cout << "Inserción de nodos en árbol  " << endl;
	//Arbol.Insertar(9);
	//Arbol.Insertar(6);
	//Arbol.Insertar(12);
	//Arbol.Insertar(3);
	//Arbol.Insertar(4);
	//Arbol.Insertar(7);
	//Arbol.Insertar(15);
	//Arbol.Insertar(11);
	//Arbol.Insertar(18);
	//cout << "\n\n Genero grafico  " << endl;
//	Arbol.inOrder();
	//Arbol.generar_grafico();
	//Sleep(5000);


	//cout << "\n\n Elimino Datos " << endl;
	//Arbol.eliminar_dato(6);
	//Arbol.eliminar_dato(25);
	//Arbol.eliminar_dato(3);
	//cout << "\n\n Genero grafico  " << endl;
	//Arbol.inOrder();
	//Arbol.generar_grafico();
	//cout << "\n\n Busco Dato  " << endl;
	//cout << "Existe Dato :  " << Arbol.buscarDato(20) << "  <-----  Si fue 1 es true y si es 0 es false \n\n";
	



	








	system("pause");	
	return 0;
}
