#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(int argc, char* argv[]){
	if (argc!=3){
		string msg("Odrediste je namjenjeno usporedbi znakova koje je poslalo izvoriste");
		msg+= " i znakova koje je primilo odrediste\n";
		msg+= "\nOdredistu je putem komandne linije potrebno predati putanje do dvije";
		msg+= " datoteke, izlazne datoteke izvorista i izlazne datoteke dekodera informacije\n";
		pogreska(msg);
	}
	
	
	ifstream ulaz1;
	ulaz1.open(argv[1]);
	if (!ulaz1.is_open()){
		string msg("Nije moguce otvoriti datoteku ");
		msg += argv[1];
		msg += "\n";
		pogreska(msg);
	}
	ifstream ulaz2;
	ulaz2.open(argv[2]);
	if (!ulaz2.is_open()){
		string msg("Nije moguce otvoriti datoteku ");
		msg += argv[2];
		msg += "\n";
		pogreska(msg);
	}
	
	int i=1;
	int brojRazlika=0;
	while(!ulaz1.eof()||!ulaz2.eof()){
		if (ulaz1.get()!=ulaz2.get()){
			brojRazlika++;
			cout << "Razlika u bitovima na rednom broju " << i << endl;
		}
		i++;
	}
	
	cout << "Pronadena je razlika u " << brojRazlika << "(" << (brojRazlika*100.0)/i << "%) bitova" << endl;
	return 0;
}