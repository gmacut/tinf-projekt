#include <iostream>
#include <fstream>
#include "postavke.hpp"
#include "generatorSlucajnihDogadjaja.hpp"
#include <string>


using namespace std;

int main(){
	Postavke postavke("izvoriste.ini");
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