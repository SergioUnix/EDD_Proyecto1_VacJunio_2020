#include <iostream>
#include <conio.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>       /* time */
#include <ctime>  /* time */
#include <vector> /* time */
#include "estructura_pila.h"
#include "estructura_cola.h"
#include "estructura_lista_simple.h"
#include "estructura_matriz.h"
#include "estructura_arbol_valanceado.h"
#include "estructura_circular.h"


using namespace std;


//matriz de toda la aplicacion
estructura_matriz <string> *Users = new estructura_matriz<string>();
//Estructura de transacciones
estructura_circular *transacciones = new estructura_circular();

string usuario_logueado = ""; string pass_logueado = ""; string departamento_logueado = ""; string empresa_logueado = "";


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
	//codigo_random = to_string(numeric2) + codigo_random + numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] +  to_string(numeric1)+numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)] + to_string(numeric3) + numeros[1 + rand() % (25)] + numeros[1 + rand() % (25)];
	codigo_random = codigo_random + to_string(numeric1);
	//cout<< " numero : " << codigo_random << endl;
	return codigo_random;
}





//////////////////////////////////////////////////// Menu de Administrador 
void menu_admin() {

	int  opcion, contador = 0, rep;
	char nombre[30], pass[30],departamento[30],empresa[30];
	//bool veri;

	do {
		system("cls");
		cout << "<<<<<<  Menu de la Aplicacion para el Usuario Administrador >>>>>>" << endl << endl;
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
		case 1:  system("cls"); //registro de usuario
			cout << "<<<<<<  Ingresar Datos del Usuario  >>>>>>" << endl << endl;
			cin.ignore();
			cout << "Ingresar el Nombre : " << endl;
			cin >> nombre;
			cout << "Ingresar el Password : " << endl;
			cin >> pass;
			cout << "Ingresar el Departamento :  " << endl;
			cin >> departamento;
			cout << "Ingresara la Empresa : " << endl;
			cin >> empresa;
			if (Users->login(std::string(departamento), std::string(empresa), std::string(nombre), std::string(pass))) {
				system("cls");
				cout << "Usuario Ya Existe : " << endl;  system("pause");
			}
			else {
				Users->insertar_elemento(std::string(departamento), std::string(empresa), std::string(nombre), std::string(pass));
				system("cls");
				cout << "Usuario Registrado Exitosamente : " << endl;  system("pause");
			}


			break;
		case 2: system("cls");
			Users->generar_txt(); //genero reporte de la matriz
			break;
		case 3:	system("cls"); //reporte activos por departamento
			cin.ignore();
			cout << "Ingresar el Departamento :  " << endl;
			cin >> departamento;
			Users->reporteDepartamento(std::string(departamento));
			system("pause");
			break;
		case 4:    system("cls"); //reporte activos por empresa
			cin.ignore();
			cout << "Ingresar nombre de la empresa :  " << endl;
			cin >> empresa;
			Users->reporteEmpresa(std::string(empresa));
			system("pause");
			break;
		case 5: system("cls");//reporte de las transacciones
			transacciones->generar_txt();
			system("pause");
			break;
		case 6: system("cls");//reporte Activos de un Usuario
			cout << "<<<<<<  Reporte de Activos de Un usuario >>>>>>" << endl;
			cout << "<<<<<<  Ingrese Datos del usuario >>>>>>" << endl << endl;
			cin.ignore();
			cout << "Ingresar el Nombre : " << endl;
			cin >> nombre;
			cout << "Ingresar el Password : " << endl;
			cin >> pass;
			cout << "Ingresar el Departamento :  " << endl;
			cin >> departamento;
			cout << "Ingresara la Empresa : " << endl;
			cin >> empresa;
			
			if(Users->login(std::string(departamento), std::string(empresa), std::string(nombre), std::string(pass))){
			Users->getArbol(std::string(departamento), std::string(empresa), std::string(nombre), std::string(pass))->generar_grafico();
			}
			else { cout << " El Usuario Ingresado No Existe " << endl; }
			system("pause");
			break;
		case 7: system("cls");//Activos rentados por un Usuario
			cout << "<<<<<<  Reporte de activos rentados por un usuario >>>>>>" << endl;
			cout << "<<<<<<  Ingrese Datos del usuario >>>>>>" << endl << endl;
			cin.ignore();
			cout << "Ingresar el Nombre : " << endl;
			cin >> nombre;
			cout << "Ingresar el Departamento :  " << endl;
			cin >> departamento;
			cout << "Ingresara la Empresa : " << endl;
			cin >> empresa;
			//cout << "Datos Captado: " << std::string(nombre) << " " << std::string(departamento) << " " << std::string(empresa);
			transacciones->usuarioTransaccion(std::string(nombre), std::string(departamento), std::string(empresa));


			
			system("pause");
			break;
		case 8: system("cls");//Ordenar Transacciones





			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 9);
}



//////////////////////////////////////////////////////Menu para usuarios normales

void menu_usuario() {

	int  opcion, contador = 0, rep;
	char nom[30], usuario[30],descripcion[30],id[30];
	char activo[30], dias[30], nom_activo[30];

	time_t tmFechaHora = time(NULL);
	char* strFechaHora = ctime(&tmFechaHora);

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
		case 1:  system("cls"); ///Agregar Activo

			cout << "Ingresar el Nombre : " << endl;
			cin.ignore();
			cin.getline(nom_activo, 30, '\n');
			cout << "Ingresar Descripcion " << endl;
			cin.getline(descripcion, 30, '\n');


		Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->Insertar(alfanumerico(),nom_activo,descripcion);
		Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->generar_grafico();
		//	ArbolSt.Insertar("aklskf142", "edificio1", "este es un inmueble");


			break;
		case 2: system("cls");  //Eliminar Activo
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
		case 3:system("cls"); //Modificar Activo
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
		case 4:    system("cls");   //Rentar Activos

			

			do {
				cout << "--------   Catalogo de Activos   -----------" << endl;
				Users->catalogo(usuario_logueado,pass_logueado); ///muestra solo los disponibles
				
				cout << "\n\n1. Rentar Activo " << endl;
				cout << "2. Salir del SubMenu" << endl << endl;
				cout << "Ingresar Opcion : " << endl;
				cin >> rep;
				switch (rep) {
				case 1:

					tmFechaHora = time(NULL);
					strFechaHora = ctime(&tmFechaHora);
					cout << "\nIngresar Activo a Rentar  " << endl;
					cin.ignore();
					cin.getline(activo, 30, '\n');
					//cout << "Mostrar Activo a Rentar " << endl;
					//if (Users->getArbol(departamento_logueado, empresa_logueado, usuario_logueado, pass_logueado)->buscarDato(std::string(activo))) {//si lo encontre procedo a crear la transaccion
					
					cout << "Ingresar Dias por Rentar  " << endl;
					cin.getline(dias, 30, '\n');

					transacciones->add_ordenado(alfanumerico(), std::string(activo), usuario_logueado,departamento_logueado, std::string(strFechaHora), std::string(dias),empresa_logueado);
					cout << "  Se creo correctamente la transaccion " << endl;
					Users->activoNoDisponible(std::string(activo)); // pasar a No disponible un activo en toda la matriz


					//}
					//else { cout << "  NO SE ENCONTRO EL DATO BUSCADO , NO SE CREO LA TRANSACCION " << endl; };
					
					system("pause");
					break;
			}
				system("cls");
			} while (rep != 2);
			cout << "\n";
			system("pause");


			break;
		case 5: system("cls"); ////Activos ya rentados


			do {
				cout << "--------    Lista Activos Rentados   -----------" << endl;
				transacciones->usuarioTransaccion(usuario_logueado,departamento_logueado,empresa_logueado);

				cout << "1. Registrar Devolucion " << endl;
				cout << "2. Salir del SubMenu" << endl << endl;
				cout << "Ingresar Opcion : " << endl;
				cin >> rep;
				switch (rep) {
				case 1:
					cout << "Ingresar Id de transaccion para devolver " << endl;
					cin.ignore();
					cin.getline(activo, 30, '\n');

					cout << "Devolviendo Activo....  " << endl;
					Users->activoDisponible( transacciones->remove_cadena(std::string(activo)));     

					system("pause");

					break;
				}
				system("cls");
			} while (rep != 2);
			cout << "\n";
			system("pause");



			break;
		case 6:  system("cls");   ///Mis Activos Rentados
				
				cout << "--------    Mis Activos Rentados   -----------" << endl;
				transacciones->usuarioTransaccion(usuario_logueado, departamento_logueado, empresa_logueado);

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
				cout << "El Usuario Administrador se logueo : " << endl;
				 usuario_logueado = "admin"; pass_logueado = "admin";  departamento_logueado = "admin"; empresa_logueado = "admin";
				 system("pause");
				menu_admin();
			}else if(Users->login(std::string(departamento_login), std::string(empresa_login), std::string(nombre_login), std::string(pass_login))==true){
				system("cls");
				cout << "Usuario Logueado : " << endl;  system("pause");
				usuario_logueado = std::string(nombre_login); pass_logueado = std::string(pass_login);  departamento_logueado = std::string(departamento_login); empresa_logueado = std::string(empresa_login);
				system("pause");
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
Users->insertar_elemento("guatemala", "profutbol", "madelyn","123456");
Users->insertar_elemento("guatemala", "profutbol", "veronica", "123456");
Users->insertar_elemento("guatemala", "profutbol", "jony", "123456");
Users->insertar_elemento("guatemala", "profutbol", "heroe", "123456");

Users->insertar_elemento("zacapa", "despensa", "sergio","123456");
Users->insertar_elemento("zacapa", "despensa", "daniel", "123456");

Users->insertar_elemento("jutiapa", "campero", "ariel","123456");
Users->insertar_elemento("jutiapa", "campero", "roberto", "123456");

Users->insertar_elemento("progreso", "cemaco", "lorena", "123456");

Users->insertar_elemento("guatemala", "empresa1", "pablo", "123456");
Users->insertar_elemento("guatemala", "empresa1", "pedrito", "123456");



Users->getArbol("zacapa", "despensa", "sergio", "123456")->Insertar(alfanumerico(), "edificiosergio", "descriSergio");
Sleep(2000);
Users->getArbol("zacapa", "despensa", "sergio", "123456")->Insertar(alfanumerico(), "cuartosergio", "descriSergio");
Sleep(2000);
Users->getArbol("zacapa", "despensa", "daniel", "123456")->Insertar(alfanumerico(), "edificiodaniel", "descri daniel");
Sleep(2000);
Users->getArbol("zacapa", "despensa", "daniel", "123456")->Insertar(alfanumerico(), "cuartodaniel", "descri/daniel");
Sleep(2000);

Users->getArbol("jutiapa", "campero", "ariel", "123456")->Insertar(alfanumerico(), "ediAriel", "descriAriel");
Sleep(2000);
Users->getArbol("progreso", "cemaco", "lorena", "123456")->Insertar(alfanumerico(), "ediLorena", "descriLorena");
Sleep(2000);

login();


//menu_usuario();
//menu_admin();



	system("pause");	
	return 0;
}
