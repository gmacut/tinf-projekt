#include <iostream>
#include <fstream>
#include <map>
#include "generatorSlucajnihDogadjaja.hpp"
#include <string>
#include <cstdlib>
#include <cmath>


using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(int argc, char* argv[]){
	int brojGeneriranihZnakova=10000;
	double znak_a=0.2;
	double znak_b=0.2;
	double znak_c=0.6;
	
	vector< pair<char,double> > znakovi;
	
	znakovi.push_back(pair<char,double>('a', znak_a));
	znakovi.push_back(pair<char,double>('b', znak_b));
	znakovi.push_back(pair<char,double>('c', znak_c));
	
	ofstream izlaz;
	izlaz.open(argv[1], ios::out);
	if (argc<2)
		pogreska("Programu je kao argument potrebno predati ime izlazne datoteke");
	
	if (!izlaz.is_open())
		pogreska("Izlaznu datoteku nije moguce stvoriti");

	GeneratorSlucajnihDogadjaja generator;
	map<char, int> pojavljivanjeZnakova;
	char c;
	int brojPonavljanja = brojGeneriranihZnakova;
	for (int i=0; i<brojPonavljanja; i++){
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