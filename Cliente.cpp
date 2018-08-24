#include"Cliente.h"
Cliente::Cliente(string nom){
	nombre = nom;
	valor = 0;
	dinero = 0;
}

string Cliente::getNombre(){
	return nombre;
}

vector<string> Cliente::getPlatos(){
	return platos;
}

void Cliente::compra(string p, int val, double prec){
	valor *= platos.size();
	platos.push_back(p);
	valor += val;
	valor /= platos.size();
	dinero += prec;
}

double Cliente::getValor(){
	return valor;
}

double Cliente::getDinero(){
	return dinero;
}

Cliente::~Cliente(){
}
