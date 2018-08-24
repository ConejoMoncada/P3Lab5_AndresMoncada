#ifndef PLATO_H
#define PLATO_H

#include"Ingrediente.h"
#include<vector>
#include<string>
using namespace std;
class Plato{
	private:
		string nombre;
		string rsa;
		int sabor;
		vector<Ingrediente> ingredientes;
		int cocinado;
		double valor;
		double precio;
	public:
		Plato(string,string,double);
		void agregar(Ingrediente);
		void cocinar(int);
		string getNombre();
		string getRsa();
		int getSabor();
		vector<Ingrediente> getIngredientes();
		int getCantidad();
		double getValor();
		double getPrecio();
		~Plato();
};
#endif
