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
	ofstream izlaz;
	if (argc >1)
		izlaz.open(argv[1]);
	else 
		izlaz.open("err_vec.txt");
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
	GeneratorSlucajnihDogadjaja generator;
	int flag;
	int brojDogadjaja=0;
	for (int i=0; i< brojZnakova; i++){
		flag = generator.generirajDogadjaj(0.1);
		if (flag){
			if (brojDogadjaja==0)
				cout << "Prva pogreska je generirana na bitu broj " << i+1 << endl;
			brojDogadjaja++;
		}
		izlaz << flag;
	}
	
	cout << "Generirano je ukupno " << brojDogadjaja << "(" << brojDogadjaja*1.0/100 << "%) pogresaka" << endl;

	izlaz.close();
	return 0;
	
}