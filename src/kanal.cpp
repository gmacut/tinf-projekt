#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(int argc, char* argv[]){
	
	if (argc < 4) 
		pogreska("Program je potrebno pozvati sa 3 argumenta, imenom ulazne datoteke,\nimenom datoteke sa vektorom pogreske te imenom izlazne datoteke.\n");
	
	ifstream ulaz;
	ulaz.open(argv[1]);
	if (!ulaz.is_open())
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	
	ifstream vektorPogreske;
	vektorPogreske.open(argv[2]);
	
	if(!vektorPogreske.is_open())
		pogreska("Nije moguce otvoriti datoteku sa vektorom pogreske");
	
	ofstream izlaz;
	izlaz.open(argv[3]);
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
		
	char c,e;
	
	while(1){
		ulaz >> c;
		vektorPogreske >> e;
		if (ulaz.eof() || vektorPogreske.eof())
			break;
		if (e=='1'){
			if (c=='0')
				c='1';
			else 
				c='0';
		}
		izlaz << c;
	}
	ulaz.close();
	izlaz.close();
	return 0;
	
}