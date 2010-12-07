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
	Postavke postavke("koder.ini");
	if (!postavke.ucitane())
		pogreska("Postavke nisu uspjesno ucitane, nije moguce otvoriti datoteku koder.ini ili je ona neispravna");
	
	vector< pair<char,double> > znakovi;
	
	for (map<string,string>::iterator it = postavke.begin(); it!=postavke.end(); ++it){
		if (it->first.find("znak-")!=string::npos)
			znakovi.push_back(
				pair<char,double>(
					it->first[5],
					atof(it->second.c_str())
				)
			);
	}
	
	ShannonFanoovKoder koder(znakovi);
	
	ifstream ulaz;
	ulaz.open(postavke["ulaz"].c_str());
	if (!ulaz)
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	ofstream izlaz;
	izlaz.open(postavke["izlaz"].c_str());
	if (!izlaz)
		pogreska("Nije moguce otvoriti izlaznu datoteku");
		
	char c;
	while(ulaz){
		ulaz >> c;
		izlaz << koder[c];
	}
	return 0;
}