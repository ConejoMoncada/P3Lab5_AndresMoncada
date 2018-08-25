#include"Ingrediente.h"
#include"Plato.h"
#include"Cliente.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void bodega();
void ventas();
void addi();
void addp();
void remp();
vector<Ingrediente> inv;//inventario
vector<Cliente> clientes;
vector<Plato> platos;
int main(){
	int resp;
	cout << "Bienvenido/a al restaurante 'Restaurante'"<< endl;
	do{
		cout << "1. Sistema de bodega y administrar platos"<< endl 
			<< "2. Sistema de ventas" << endl
			<< "3. Salir" << endl
			<<"Ingrese una opción: ";
		cin >> resp;
		switch(resp){
			case 1: bodega();
				break;
			case 2: ventas();
		}
	}while(resp!=3);
	return 0;
}
void bodega(){
	cout << "Bodega y Platos" << endl;
	int resp;
	do{
		cout << "1. Agregar un ingrediente" << endl
			<< "2. Crear un plato" << endl
			<< "3. Quitar un plato del menu" << endl
			<< "4. Regresar" << endl
			<< "Ingrese una opción: ";
		cin >> resp;
		switch(resp){
			case 1: addi();
				break;
			case 2: addp();
				break;
			case 3: remp();
		}
	}while(resp != 4);
}

void addi(){
	int tp;
	string nom;
	string tipo;
	int ap;
	int dur; 
	int cant;
	cout << "Nombre del Ingrediente: ";
	cin >> nom;
	cout << "Tipo:" << endl << "1. Lácteo" << endl << "2. Vegetal" << endl
		<< "3. Fruta" << endl 
		<< "Ingresar cualquier otro número para 'otros'" << endl
		<< "Ingrese una opción: ";
	cin >> tp;
	switch(tp){
		case 1: tipo = "Lácteo";
			break;
		case 2: tipo = "Vegetal";
			break;
		case 3: tipo = "Fruta";
			break;
		default: tipo = "Otro";
	}
	cout << "Ingrese el aporte de sabor: ";
	cin >> ap;
	cout << "Ingrese la duración del ingrediente: ";
	cin >> dur;
	cout << "Cuantos productos van a entrar en bodega? ";
	cin >> cant;
	Ingrediente ing(nom,tipo,ap,dur,cant);
	inv.push_back(ing);
	cout << "Ingrediente guardado" << endl;
}

void addp(){
	if(inv.size() > 0){ 
		string nom ="Comida";
		string rsa = "Bueno";//reseña, pero la ñ no funciona en variables
		double precio = 1.0;
		cout << "Ingrese el nombre del plato: ";
		//cin >> nom;
		cout << "Ingrese una reseña del plato:" << endl;
		//cin >> rsa;
		cout << "Ingrese el precio: ";
		//cin >> precio;
		cout << "A";
		//Plato p(nom,rsa,precio);
		int resp = -1;
		do{
			if(resp != -1){
				cout << "Agregar otro ingrediente? 1.Sí 2.No: ";
				cin >> resp;
			}
			if(resp == 1 && resp == -1){
				cout << "Agregar ingrediente" << endl;
				for(int i = 0; i < inv.size(); i++){
					cout << i << ". " << inv[i].getNombre()
						<< endl;
				}
				cout << "Ingrese el indice del ingrediente";
				int index;
				cin >> index;
				Ingrediente ing = inv[index];
				cout << "Ingrese la cantidad a agregar: ";
				int cant;
				cin >> cant;
				ing.setCantidad(cant);
				//p.agregar(ing);
				//platos.push_back(p);
				resp = 0;
			}
		}while(resp != 2);
		cout << "Plato agregado al menú" << endl;
	}
	else
		cout << "Agrege ingredientes a la bodega primero" << endl;
}

void remp(){
	for (int i = 0; i < platos.size(); i++){
		cout << i << ". " << platos[i].getNombre() << endl;
	}
	int index;
	cout << "Ingrese el índice del plato que desea eliminar: ";
	cin >> index;
	platos.erase(platos.begin()+index);
	cout << "Plato eliminado del menú" << endl;
}

void ventas(){
	cout << "Ya a comprado aquí antes? [s/n]";
	char r1;
	cin >> r1;
	int index;
	if(r1 == 'n'){
		cout << "Nombre del cliente: ";
		string nom;
		cin >> nom;
		Cliente cte(nom);
		index = clientes.size();
		clientes.push_back(cte);
	}
	else {
		for (int i = 0; i < clientes.size(); i++){
			cout << i << ". " << clientes[i].getNombre();
		}
		cout << "Ingrece el índice del cliente: ";
		cin >> index;
	}
	if(platos.size() > 0){
		int p;//índice plato
		int b;//índice en bodega
		int c;//cantidad
		vector<Ingrediente> ip;//ingredientes del plato
		cout << "MENÚ" << endl;
		for (int i = 0; i < platos.size(); i++){
			cout << i << ". " << platos[i].getNombre() << platos[i].getValor()<<endl;
		}
		cout << "Ingrese el numero del plato: ";
		cin >> p;
		ip = platos[p].getIngredientes();
		for(int i = 0; i < ip.size(); i++){
			string nombre = ip[i].getNombre();
			for (int j = 0; j < inv.size(); j++){
				if(nombre.compare(inv[j].getNombre()) == 0){
						while(ip[i].getCantidad() > inv[j].getCantidad()){
							inv[j].agregar();
						}
						inv[j].quitar(ip[i].getCantidad());
				}
			}
		}
		int nota;
		cout << "Cuanto le dio al plato? [1-5]: ";
		cin >> nota;
		platos[p].cocinar(nota);
		clientes[index].compra(platos[p].getNombre(),nota,platos[p].getPrecio());
	}
}
