#include"Plato.h"
Plato::Plato(string nom, string res, double prec){
	nombre = nom;
	rsa = res;
	sabor = 0;
	cocinado = 0;
	valor = 0;
	precio = prec;
}

void Plato::agregar(Ingrediente i){
	ingredientes.push_back(i);
}

void Plato::cocinar(int val){
	valor *= cocinado;
	cocinado++;
	valor += val;
	valor /= cocinado;
}

string Plato::getNombre(){
	return nombre;
}

string Plato::getRsa(){
	return rsa;
}

int Plato::getSabor(){
	return sabor;
}

vector<Ingrediente> Plato::getIngredientes(){
	return ingredientes;
}

int Plato::getCantidad(){
	return cocinado;
}

double Plato::getValor(){
	return valor;
}

double Plato::getPrecio(){
	return precio;
}

Plato::~Plato(){
}
