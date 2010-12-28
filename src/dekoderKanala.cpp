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
		
	char c, prosliZnak;
	int paritet=0;
	int brojacBloka=0;
	while(1){	
		for (int i=0; i<velicinaBloka; i++){
			ulaz >> c;
			if (ulaz.eof())
				break;
			prosliZnak=c;
			if (c=='1'){
				paritet=(paritet+1)%2;
			}
			if (ulaz.peek()!=EOF)
				izlaz << c;
		}
		if (ulaz.eof()){
			if (prosliZnak=='1') 
				paritet = (paritet + 1)%2;
			break;
		} else {
			ulaz >> c;
			if ((paritet==1 && c == '0') || (paritet==0 && c=='1'))
				cout << "Detektirana je pogreska izmedju znakova " << brojacBloka*5 << " i " << (brojacBloka+1)*5 << endl;
		} 
		paritet=0;
		brojacBloka++;
	}
	ulaz.close();
	izlaz.close();

	return 0;
}