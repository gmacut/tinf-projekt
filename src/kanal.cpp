#include <iostream>
#include <fstream>
#include <cstdlib>

#include "postavke.hpp"
#include "generatorSlucajnihDogadjaja.hpp"

using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(){
	Postavke postavke("kanal.ini");
	if (!postavke.ucitane())
		pogreska("Postavke nisu uspjesno ucitane, nije moguce otvoriti datoteku kanal.ini ili je ona neispravna");
	
	ifstream ulaz;
	ulaz.open(postavke["ulaz"].c_str());
	if (!ulaz.is_open())
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	
	ofstream izlaz;
	izlaz.open(postavke["izlaz"].c_str());
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
		
	char c;
	GeneratorSlucajnihDogadjaja generator;
	double vjerojatnost=atof(postavke["vjerojatnostPogreske"].c_str());
	while(1){
		ulaz >> c;
		if (ulaz.eof())
			break;
		if (generator.generirajDogadjaj(vjerojatnost)){
			if (c=='0')
				c='1';
			else 
				c='0';
		}
		izlaz << c;
	}
	ulaz.close();
	izlaz.close();
	return 0;
	
}