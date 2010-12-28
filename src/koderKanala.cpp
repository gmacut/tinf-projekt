#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>


using namespace std;

void pogreska(string str){
	cerr << str << endl;
	exit(-1);
}

int main(int argc, char* argv[]){
	int velicinaBloka=5;
	ifstream ulaz;	
	if (argc < 3)
		pogreska("Program je potrebno pozvati sa imenom ulazne i imenom izlazne datoteke\n");
	
	ulaz.open(argv[1]);
	if (!ulaz.is_open())
		pogreska("Nije moguce otvoriti ulaznu datoteku");
	
	ofstream izlaz;
	izlaz.open(argv[2]);
	if (!izlaz.is_open())
		pogreska("Nije moguce otvoriti izlaznu datoteku");
		
	char c;
	char paritet='0';
	while(1){
		for (int i=0; i<velicinaBloka; i++){
			ulaz >> c;
			if (ulaz.eof())
				break;
			if (c=='1'){
				if (paritet=='0')
					paritet='1';
				else 
					paritet='0';
			}
			izlaz << c;
		}
		izlaz << paritet;
		paritet='0';
		if (ulaz.eof())
			break;
	}
	ulaz.close();
	izlaz.close();
	cout << "Poruka je zastitno kodirana parnim paritetom sa velicinom bloka " << velicinaBloka << endl;
	return 0;
}