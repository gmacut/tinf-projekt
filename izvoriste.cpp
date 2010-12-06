#include <iostream>
#include "postavke.h"
#include "generatorVjerojatnosti.h"
#include <string.h>


using namespace std;

int main(){
	Postavke postavke("izvoriste.ini");
	GeneratorVjerojatnosti generator;
	int suma=0;
	for (int i=0; i<10000; i++){
		if(generator.generirajVjerojatnost(0.4)) suma++;
	}
	cout<<suma<<endl;
	return 0;
}