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
	cout << "Ingrediente guardado";
}

void addp(){
	if(inv.size() > 0){ 
		string nom;
		string rsa;//reseña, pero la ñ no funciona en variables
		double precio;
		cout << "Ingrese el nombre del plato: ";
		cin >> nom;
		cout << "Ingrese una reseña del plato:" << endl;
		//getline(cin,rsa);
		cin >> rsa;
		cout << "Ingrese el precio: ";
		cin >> precio;
		Plato p(nom,rsa,precio);
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
				p.agregar(ing);
				platos.push_back(p);
				resp = 0;
			}
		}while(resp != 2);
	}
}

void remp(){

}

void ventas(){
}
