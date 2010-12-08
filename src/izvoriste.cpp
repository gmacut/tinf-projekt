#include <iostream>
#include <fstream>
#include "postavke.hpp"
#include "generatorSlucajnihDogadjaja.hpp"
#include <string>
#include <cstdlib>
#include <cmath>


using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(){
	Postavke postavke("izvoriste.ini");
	if (!postavke.ucitane())
		pogreska("Postavke nisu uspjesno ucitane, nije moguce otvoriti datoteku izvoriste.ini ili je ona neispravna");
	
	vector< pair<char,double> > znakovi;
	postavke.dohvatiZnakove(znakovi);
	
	ofstream izlaz;
	izlaz.open(postavke["izlaz"].c_str(), ios::out);
	
	if (!izlaz.is_open())
		pogreska("Datoteka " + postavke["izlaz"] + " nije pronadena");

	GeneratorSlucajnihDogadjaja generator;
	map<char, int> pojavljivanjeZnakova;
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
	
	double entropija=0;
	for (vector< pair<char,double> >::iterator it = znakovi.begin(); it!=znakovi.end(); ++it){
		entropija += it->second * log(it->second)/log(2);
	}
	
	entropija *= -1;
	
	cout << endl << "Entropija izvora iznosi: " << entropija << endl;
	
	return 0;
}