#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "estructura_pila.h"
#include "estructura_cola.h"
#include "estructura_lista_simple.h"
#include "estructura_matriz.h"

using namespace std;
void menu() {

	int  opcion, contador = 0, rep;
	char nom[30], usuario[30];
	//bool veri;

	do {
		cout << "<<<<<<  Menu de la Aplicacion  >>>>>>" << endl << endl;
		cout << "1. Cargar Archivo" << endl;
		cout << "2. Agregar Jugador " << endl;
		cout << "3. JUGAR" << endl;
		cout << "5. Reportes" << endl;
		cout << "8.Salir " << endl << endl;
		cout << "Ingresa Opcion : ";
		cin >> opcion;

		switch (opcion) {
		case 1:  system("cls");
			cout << "Datos Cargados" << endl;

			break;
		case 2: system("cls");
			cout << "Introduzca el nombre del Jugador" << endl;
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





int main()
{
//menu();
	cout << " /////////////////////  datos de la pila" << endl;
	estructura_pila<std::string> * pil = new estructura_pila<std::string>();
	pil->push("elemento 1");
	pil->push("elemento 2");
	pil->push("elemento 3");
	pil->push("elemento 4");
	pil->imprimir_pila();
	pil->pop();
	//pil->imprimir_pila();
	//cout << pil->cadena_grafic() << endl;
//	pil->generar_abrir();


	cout << " /////////////////////  datos de la cola " << endl;
	estructura_cola<std::string> *prueba = new estructura_cola<std::string>();
	prueba->insertar("primer dato");
	prueba->insertar("segundo dato");
	prueba->insertar("tercer dato");
	prueba->insertar("cuarto dato");
	cout << " boolean de la cola " << true << endl;
	prueba->imprimir();
	prueba->extraer();
	
	//cout << prueba->cadena_grafic() << endl;
	//prueba->generar_abrir();


	cout << " /////////////////////  prueba de lista Simple ordenada " << endl << endl;
	estructura_lista_simple *lista = new estructura_lista_simple();
	lista->add_en_orden("Heidy");
	lista->add_en_orden("Carlos");
	lista->add_en_orden("Antonio");
	lista->add_en_orden("Eduardo");
	lista->add_en_orden("Rodrigo");
	lista->mostrar_lista();
	//cout<<lista->cadena_grafic() << endl;
	//lista->generar_abrir();  
	


	//cout << " /////////////////////  prueba de matriz" << endl << endl;
	estructura_matriz <string> *mat = new estructura_matriz<string>();
	mat->insertar_elemento("Departamento1", "empresa1", "Dato1");
	mat->insertar_elemento("Departamento2", "empresa2", "Dato2");
	mat->insertar_elemento("Departamento3", "empresa3", "Dato3");
	mat->insertar_elemento("Departamento4", "empresa4", "Dato4");

	mat->insertar_elemento("Departamento4", "empresa4", "Dato4_z1");
	mat->insertar_elemento("Departamento4", "empresa4", "Dato4_z2");
	


	mat->insertar_elemento("Departamento4", "empresa1", "Dato2");
	mat->insertar_elemento("Departamento4", "empresa1", "Dato2_Z1");
	mat->insertar_elemento("Departamento4", "empresa1", "Dato2_Z2");
	mat->insertar_elemento("Departamento4", "empresa1", "Dato2_Z3");
	//

	cout << "\n\n\n\n\n\n" << endl;
	mat->generar_txt();
	cout << mat->grafic() << endl << endl;




	system("pause");	
	return 0;
}
