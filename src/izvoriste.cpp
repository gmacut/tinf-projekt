#include <iostream>
#include <fstream>
#include "postavke.hpp"
#include "generatorSlucajnihDogadjaja.hpp"
#include <string>
#include <cstdlib>


using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(){
	Postavke postavke("izvoriste.ini");
	if (!postavke.ucitane())
		pogreska("Postavke nisu uspjesno ucitane, nije moguce otvoriti datoteku izvoriste.ini ili je ona neispravna");
	
	GeneratorSlucajnihDogadjaja generator;
	vector< pair<char,double> > znakovi;
	map<char, int> pojavljivanjeZnakova;
	
	for (map<string,string>::iterator it = postavke.begin(); it!=postavke.end(); ++it){
		if (it->first.find("znak-")!=string::npos)
			znakovi.push_back(
				pair<char,double>(
					it->first[5],
					atof(it->second.c_str())
				)
			);
	}
	ofstream izlaz;
	izlaz.open(postavke["izlaz"].c_str(), ios::out);
	
	if (!izlaz.is_open())
		pogreska("Datoteka " + postavke["izlaz"] + " nije pronadena");

	char c;
	for (int i=0; i<10000; i++){
		c = generator.odaberiZnak(znakovi);
		izlaz << c;
		pojavljivanjeZnakova[c]++;
	}
	izlaz.close();
	
	cout << "Znakovi su generirani: " << endl;
	for (map<char, int>::iterator it = pojavljivanjeZnakova.begin(); it!=pojavljivanjeZnakova.end(); ++it){
		cout << it->first << ": " << it->second << " puta" << endl;
	}
	return 0;
}