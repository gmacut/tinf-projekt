#include <iostream>
#include "postavke.hpp"
#include "generatorSlucajnihDogadjaja.hpp"
#include <string>


using namespace std;

int main(){
	Postavke postavke("izvoriste.ini");
	GeneratorSlucajnihDogadjaja generator;
	int suma=0;
	for (int i=0; i<10000; i++){
		if(generator.generirajDogadjaj(0.4)) suma++;
	}
	cout<<suma<<endl;
	return 0;
}