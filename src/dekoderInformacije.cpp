#include <string>
#include <vector>
#include <utility>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "shannonFanoovKoder.hpp"

using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(int argc, char* argv[]){
	double znak_a=0.2;
	double znak_b=0.2;
	double znak_c=0.6;
	
	vector< pair<char,double> > znakovi;
	znakovi.push_back(pair<char, double>('a', znak_a));
	znakovi.push_back(pair<char, double>('b', znak_b));
	znakovi.push_back(pair<char, double>('c', znak_c));
	
	ShannonFanoovKoder koder(znakovi);
	
	cout << "Konstruiran je Shannon-Fanoov koder koji se koristi za dekodiranje:" << endl;
	double duljina = 0;
	for (int i=0; i<znakovi.size(); i++){
		cout << "Znak " << znakovi[i].first << "(p=" << znakovi[i].second << "): " << koder[znakovi[i].first] << endl;
		duljina += znakovi[i].second * koder[znakovi[i].first].size();
	}
	
	if (argc < 3)
		pogreska("Program je potrebno pozvati sa imenom ulazne i imenom izlazne datoteke\n");
	
	ifstream ulaz;
	ulaz.open(argv[1]);
	if (!ulaz.is_open())
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	
	ofstream izlaz;
	izlaz.open(argv[2]);
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
		
	char c;
	string kod="";
	
	while(true){
		ulaz.get(c);
		if (!ulaz.good())
			break;
		kod+=c;
		c=koder.dekodiraj(kod);
		if (c==0)
			continue;
		kod="";
		izlaz.put(c);
	}
	
	ulaz.close();
	izlaz.close();
	return 0;
}