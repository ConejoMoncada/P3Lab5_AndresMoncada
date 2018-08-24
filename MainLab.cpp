#include"Ingrediente.h"
#include"Plato.h"
#include"Cliente.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int resp;
	cout << "Bienvenido/a al restaurante 'Restaurante'"<< endl;
	do{
		cout << "1. Sistema de bodega"<< endl 
			<< "2. Sistema de ventas" << endl
			<< "3. Salir" << endl
			<<"Ingrese una opción: ";
		cin >> resp;
	}while(resp!=3);
	return 0;
}
