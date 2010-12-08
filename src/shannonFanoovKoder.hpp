#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief koder/dekoder Shannon-Fanoovim kodom
 *
 * Na osnovu konstruktoru predanih parova znakova i njima pridruženih vjerojatnosti
 * stvara se tablica kodnih riječi. Nakon toga se za svaki znak može dohvatiti njegova kodna 
 * riječ i obratno.
 */
class ShannonFanoovKoder{
	private:
		map<char,string> _tablicaKoda;
		
		bool usporedivanjeZnakova(const pair<char,double>& prvi, const pair<char,double>& drugi){
			return prvi.second > drugi.second;
		}
		
		/*
		 * Funkciji se predaje vektor parova znakova i njima pridruženih vjerojatnosti
		 * sortiran padajući po vjerojatnostima znakova, interval kojem se dodjeljuju 
		 * kodni znakovi te ukupan interval vjerojatnosti na tom intervalu znakova. 
		 * Znakovi se potom podijele na dva dijela, prvom se u kod dodaju nule, 
		 * a drugom jedinice. Nakon toga se funkcija rekurzivno poziva
		 * nad svakim od tih intervala. Donja granica rekurzije je slučaj kad je 
		 * u predanom intervalu samo jedan znak. U tom slučaju se ne dodaje niti 
		 * nula niti jedan u kodnu riječ tog znaka.
		 */
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
		/**
		 * @brief konstruktor koji prima referencu na vektor parova znakova i 
		 * 			njihovih vjerojatnosti koje određuju oblik koda
		 * @param znakovi referenca na vektor parova znakova i pridruženih vjerojatnosti
		 */
		ShannonFanoovKoder(vector< pair<char,double> >& znakovi){
			sort(znakovi.begin(),znakovi.end(),usporedivanjeZnakova);
			dodijeliKod(znakovi, 0, znakovi.size()-1, 1);
		}
		
		/**
		 * @brief za zadani znak dohvaća kodnu riječ tog znaka
		 *
		 * @param c znak koji se kodira
		 * @return kodna riječ znaka
		 */
		string kodiraj(char c){
			return _tablicaKoda[c];
		}
		
		/**
		 * @brief preopterećen operator [] kako bi se omogućilo lakše kodiranje.
		 *
		 * Interno se preusmjerava na funkciju ShannonFanoovKoder::kodiraj(char)
		 * @param c znak koji se kodira
		 * @return kodna riječ znaka
		 */
		string operator[](char c){
			return kodiraj(c);
		}
		
		/**
		 * @brief za zadani kod vraća pripadajući znak
		 * 
		 * @param kod kod znaka koji se traži
		 * @return znak ako je predana kodna riječ u kodu, inače 0
		 */
		char dekodiraj(string kod){
			for (map<char,string>::iterator it = _tablicaKoda.begin(); it!=_tablicaKoda.end(); ++it){
				if (kod==it->second)
					return it->first;
			}
			return 0;
		}
};