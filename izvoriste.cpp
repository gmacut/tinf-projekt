#include <iostream>
#include "postavke.h"
#include "generatorSlucajnihDogadjaja.h"
#include <string.h>


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