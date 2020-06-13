#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "estructura_pila.h"
#include "estructura_cola.h"
#include "estructura_lista_simple.h"
#include "estructura_matriz.h"
#include "estructura_arbol_valanceado.h"

using namespace std;

//matriz de toda la aplicacion
estructura_matriz <string> *Users = new estructura_matriz<string>();


void menu() {

	int  opcion, contador = 0, rep;
	char nom[30], usuario[30];
	//bool veri;

	do {
		cout << "<<<<<<  Menu de la Aplicacion  >>>>>>" << endl << endl;
		cout << "1. Opcion 1" << endl;
		cout << "2. Opcion 2 " << endl;
		cout << "3.  Opcion 3" << endl;
		cout << "5. Reportes" << endl;
		cout << "8.Salir " << endl << endl;
		cout << "Ingresa Opcion : ";
		cin >> opcion;

		switch (opcion) {
		case 1:  system("cls");
			cout << "Datos Cargados" << endl;

			break;
		case 2: system("cls");
			cout << "Introduzca el nombre " << endl;
			cin >> usuario;

			break;

		case 3:
			
			break;
		case 5:    system("cls");
			do {
				cout << "--------   Seleccionar Reporte    -----------" << endl;
				cout << "1. Reporte 1 " << endl;
				cout << "2. Reporte 2" << endl;
				cout << "3. Reporte 3" << endl;
				cout << "4. Reporte 4" << endl;
				cout << "5. Reporte 5" << endl;
				cout << "6. Reporte 6" << endl;
				cout << "7. Reporte 7" << endl;
				cout << "8. Reporte 8" << endl;
				cout << "9. Salir del SubMenu" << endl << endl;
				cout << "Ingresar Opcion : " << endl;
				cin >> rep;
				switch (rep) {
				case 1:
					
					break;
				case 2:
					
					break;
				case 3:
					
					break;
				case 4:
					
					break;
				case 5:
					break;
				case 7:  
					break;
				case 8:
					break;
				}
				system("cls");
			} while (rep != 9);
			cout << "\n";
			system("pause");


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
	} while (opcion != 8);
}



void login() {

	int  opcion, contador = 0, rep;
	char nombre_login[30], pass_login[30];
	char departamento_login[30], empresa_login[30];
	//bool veri;

	do {
		cout << "<<<<<<  Bienvenidos a la Aplicacion  >>>>>>" << endl << endl;
		cout << "1. Loguearse " << endl;
		cout << "2. Salir " << endl << endl;
		cout << "Ingresa Opcion : ";
		cin >> opcion;

		switch (opcion) {
		case 1:  system("cls");
			cout << "<<<<<<  Ingresar Datos del Usuario  >>>>>>" << endl << endl;
			cout << "Ingresar el Nombre : " << endl;
			cin >> nombre_login;
			cout << "Ingresar el Password : " << endl;
			cin >> pass_login;
			cout << "Ingresar el Departamento :  " << endl;
			cin >> departamento_login;
			cout << "Ingresara la Empresa : " << endl;
			cin >> empresa_login;

			break;
		case 2: system("cls");
			




			

			break;

		case 3:

			break;
		case 5:    system("cls");
			do {
				cout << "--------   Seleccionar Reporte    -----------" << endl;
				cout << "1. Reporte 1 " << endl;
				cout << "2. Reporte 2" << endl;
				cout << "3. Reporte 3" << endl;
				cout << "4. Reporte 4" << endl;
				cout << "5. Reporte 5" << endl;
				cout << "6. Reporte 6" << endl;
				cout << "7. Reporte 7" << endl;
				cout << "8. Reporte 8" << endl;
				cout << "9. Salir del SubMenu" << endl << endl;
				cout << "Ingresar Opcion : " << endl;
				cin >> rep;
				switch (rep) {
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:
					break;
				case 7:
					break;
				case 8:
					break;
				}
				system("cls");
			} while (rep != 9);
			cout << "\n";
			system("pause");


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
	} while (opcion != 8);
}










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













int main()
{











//menu();
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
	


	//cout << " /////////////////////  prueba de matriz" << endl << endl;
	estructura_matriz <string> *mat = new estructura_matriz<string>();
	//mat->insertar_elemento("Departamento1", "empresa1", "Dato1");
	//mat->insertar_elemento("Departamento2", "empresa2", "Dato2");
//	mat->insertar_elemento("Departamento3", "empresa3", "Dato3");
//	mat->insertar_elemento("Departamento4", "empresa4", "Dato4");
//	mat->insertar_elemento("Departamento5", "empresa5", "Dato5");
//	mat->insertar_elemento("Departamento6", "empresa6", "Dato6");

//	mat->insertar_elemento("Departamento6", "empresa5", "Dato77");



//	mat->insertar_elemento("Departamento4", "empresa4", "Dato4_z1");
//	mat->insertar_elemento("Departamento4", "empresa4", "Dato4_z2");
	


//	mat->insertar_elemento("Departamento4", "empresa1", "Dato2");
//	mat->insertar_elemento("Departamento4", "empresa1", "Dato2_Z1");
//	mat->insertar_elemento("Departamento4", "empresa1", "Dato2_Z2");
//	mat->insertar_elemento("Departamento4", "empresa1", "Dato2_Z3");
	

	mat->insertar_elemento("SOLOLA", "ADI", "PECO","123456");

	mat->insertar_elemento( "REU","adi", "val", "123456");
	mat->insertar_elemento( "HUEHUETENANGO","adi", "Espino", "123456");
	mat->insertar_elemento( "HUEHUETENANGO","EST", "Rambo", "123456");
	mat->insertar_elemento( "PETEN","BUR", "pio", "123456");
	mat->insertar_elemento("solola", "BUR", "pol", "123456");
	mat->insertar_elemento( "PETEN","CAM", "ALI", "123456");
	mat->insertar_elemento("reu", "BUR", "pik", "123456");
	mat->insertar_elemento("reu", "BUR", "atras", "123456");

	cout << "resultado de login   es    :"<<mat->login("reu", "BUR", "atras", "123456") << endl;

	//mat->insertar_elemento( "PETEN","MAC", "simon", "123456");
	//mat->insertar_elemento( "REU","FIFA", "Ronaldo");
	//mat->insertar_elemento( "REU","MAX", "Espino");
//	mat->insertar_elemento( "SOLOLA","MAX", "pablo");







	mat->generar_txt();
	//cout << mat->grafic() << endl << endl;

	
	
	
	

	// Un árbol de enteros
	estructura_arbol_valanceado<int> Arbol; 
	//cout << "Inserción de nodos en árbol  " << endl;
	Arbol.Insertar(9);
	Arbol.Insertar(6);
	Arbol.Insertar(12);
	Arbol.Insertar(3);
	Arbol.Insertar(4);
	Arbol.Insertar(7);
	Arbol.Insertar(15);
	Arbol.Insertar(11);
	Arbol.Insertar(18);
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
	


	estructura_arbol_valanceado<string> ArbolSt;
	ArbolSt.Insertar("ariel");
	ArbolSt.Insertar("daniel");
	ArbolSt.Insertar("zorro");
	ArbolSt.Insertar("hero");
	ArbolSt.Insertar("maicol");
	ArbolSt.Insertar("pApa");
	ArbolSt.Insertar("bari");
	ArbolSt.Insertar("sonso");
	ArbolSt.Insertar("toLador");
	ArbolSt.eliminar_dato("isla");
	ArbolSt.eliminar_dato("hero");
	//ArbolSt.generar_grafico();
	ArbolSt.inOrder();


	








	system("pause");	
	return 0;
}
