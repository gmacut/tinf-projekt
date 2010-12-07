#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool usporedivanjeZnakova(const pair<char,double>& prvi, const pair<char,double>& drugi){
	return prvi.second > drugi.second;
}

class ShannonFanoovKoder{
	private:
		map<char,string> _tablicaKoda;
		
		void dodijeliKod(vector< pair<char,double> > znakovi, int pocetak, int kraj, double preostalaVjerojatnost){
			if (pocetak < kraj){
				double prijedenaVjerojatnost = 0;
				int indeksGranice=pocetak;
				while(prijedenaVjerojatnost<(preostalaVjerojatnost/2.0)){
					_tablicaKoda[znakovi[indeksGranice].first] += '0';
					prijedenaVjerojatnost += znakovi[indeksGranice].second;
					indeksGranice++;
				}

				dodijeliKod(znakovi, pocetak, indeksGranice-1, prijedenaVjerojatnost);
				for (int i=indeksGranice; i<=kraj; i++)
				{
					_tablicaKoda[znakovi[i].first] += '1';
				}
				dodijeliKod(znakovi, indeksGranice, kraj, preostalaVjerojatnost-prijedenaVjerojatnost);
			}
		}
		
	public:
		ShannonFanoovKoder(vector< pair<char,double> > znakovi){
			sort(znakovi.begin(),znakovi.end(),usporedivanjeZnakova);
			for (int i=0;i<znakovi.size(); i++)
				cout << znakovi[i].first << znakovi[i].second << endl;
			
			dodijeliKod(znakovi, 0, znakovi.size()-1, 1);
		}
		string operator[](char c){
			return _tablicaKoda[c];
		}
};