main: MainLab.o Cliente.o Plato.o Ingrediente.o
	g++ Ingrediente.o Plato.o Cliente.o MainLab.o -o main
	rm *.o

MainLab.o:	MainLab.cpp Cliente.h Plato.h Ingrediente.h
	g++ -c MainLab.cpp

Ingrediente.o:	Ingrediente.h Ingrediente.cpp
	g++ -c Ingrediente.cpp

Plato.o: Ingrediente.h Plato.h Plato.cpp
	g++ -c Plato.cpp

Cliente.o: Cliente.h Cliente.cpp
	g++ -c Cliente.cpp
