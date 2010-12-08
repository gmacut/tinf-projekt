#include <string>
#include <vector>
#include <utility>
#include <map>
#include <cstdlib>
#include <fstream>

#include "postavke.hpp"
#include "shannonFanoovKoder.hpp"

using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(){
	Postavke postavke("dekoderInformacije.ini");
	if (!postavke.ucitane())
		pogreska("Postavke nisu uspjesno ucitane, nije moguce otvoriti datoteku dekoderInformacije.ini ili je ona neispravna");
	
	vector< pair<char,double> > znakovi;
	postavke.dohvatiZnakove(znakovi);
	
	ShannonFanoovKoder koder(znakovi);
	
	cout << "Konstruiran je Shannon-Fanoov koder koji se koristi za dekodiranje:" << endl;
	double duljina = 0;
	for (int i=0; i<znakovi.size(); i++){
		cout << "Znak " << znakovi[i].first << "(p=" << znakovi[i].second << "): " << koder[znakovi[i].first] << endl;
		duljina += znakovi[i].second * koder[znakovi[i].first].size();
	}
	
	ifstream ulaz;
	ulaz.open(postavke["ulaz"].c_str());
	if (!ulaz.is_open())
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	
	ofstream izlaz;
	izlaz.open(postavke["izlaz"].c_str());
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
		
	char c;
	string kod="";
	while(ulaz){
		do {
			ulaz.get(c);
			kod += c;
			c = koder.dekodiraj(kod);
		} while (!c && !ulaz.eof());
		kod = "";
		izlaz.put(c);
	}
	
	ulaz.close();
	izlaz.close();
	return 0;
}