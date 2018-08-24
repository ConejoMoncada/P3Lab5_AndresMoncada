#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include<string>
using namespace std;
class Ingrediente{
	private:
		string nombre;
		string tipo;
		int aporte;
		int duracion;
		int cantidad;
		int cont;
	public:
		Ingrediente(string,string,int,int,int);

		string getNombre();
		string getTipo();
		int getAporte();
		int getDuracion();
		int getCantidad();

		void agregar();
		void quitar(int);

		void setNombre(string);
		void setTipo(string);
		void setAporte(int);
		void setDuracion(int);

		~Ingrediente();
};
#endif
