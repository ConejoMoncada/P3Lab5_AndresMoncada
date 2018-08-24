#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
#include<vector>
using namespace std;

class Cliente{
	private:
		string nombre;
		vector<string> platos;
		double valor;
		double dinero;
	public:
		Cliente(string);
		string getNombre();
		vector<string> getPlatos();
		void compra(string,int,double);
		double getValor();
		double getDinero();
		~Cliente();
};
#endif
