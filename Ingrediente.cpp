#include "Ingrediente.h"
#include<math.h>
Ingrediente::Ingrediente(string nom, string tip, int ap, int dur, int cant){
	nombre = nom;
	tipo = tip;
	aporte = ap;
	duracion = dur;
	cantidad = cant;
	cont = duracion;
}

string Ingrediente::getNombre(){
	return nombre;
}

string Ingrediente::getTipo(){
	return tipo;
}

int Ingrediente::getAporte(){
	return aporte;
}

int Ingrediente::getDuracion(){
	return duracion;
}

int Ingrediente::getCantidad(){
	return cantidad;
}

void Ingrediente::agregar(){
	cantidad += rand()% 2+ 1;
}

void Ingrediente::setCantidad(int c){
	cantidad = c;
}

void Ingrediente::quitar(int n){
	cantidad -= n;
	cont --;
	if(cont <= 0){
		cont = duracion;
		cantidad -= cantidad/10;
	}
}

void Ingrediente::setNombre(string nom){
	nombre = nom;
}

void Ingrediente::setTipo(string tip){
	tipo = tip;
}

void Ingrediente::setAporte(int ap){
	aporte = ap;
}


void Ingrediente::setDuracion(int dur){
	duracion = dur;
}

Ingrediente::~Ingrediente(){
}
