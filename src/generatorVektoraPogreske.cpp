#include <iostream>
#include <fstream>
#include <cstdlib>

#include "generatorSlucajnihDogadjaja.hpp"

using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(int argc, char* argv[]){
	int brojZnakova=10000;
	double vjerojatnost=0.1;
	if (argc < 2)
		pogreska("Program je potrebno pozvati sa imenom ulazne datoteke na koju ce se primjenjivati vektor pogreske, potom opcionalnim vjerojatnosti i imenom izlazne datoteke");
	ifstream ulaz;
	ulaz.open(argv[1]);
	if (!ulaz.is_open())
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	if (argc>2)
		vjerojatnost=atof(argv[2]);
	ofstream izlaz;
	if (argc >3)
		izlaz.open(argv[3]);
	else 
		izlaz.open("err_vec.txt");
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
	GeneratorSlucajnihDogadjaja generator;
	int flag,i=0;
	int brojDogadjaja=0;
	char c;
	while(ulaz >> c){
		flag = generator.generirajDogadjaj(vjerojatnost);
		if (flag){
			if (brojDogadjaja==0)
				cout << "Prva pogreska je generirana na bitu broj " << i+1 << endl;
			brojDogadjaja++;
		}
		izlaz << flag;
		i++;
	}
	
	cout << "Generirano je ukupno " << brojDogadjaja << "(" << brojDogadjaja*100.0/i << "%) pogresaka na " << i << " znakova."<<  endl;

	izlaz.close();
	return 0;
	
}