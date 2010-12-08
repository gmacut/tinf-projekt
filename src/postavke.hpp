#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

/**
 * @brief Klasa koja učitava postavke iz ini datoteke
 * Klasa pruža sučelje slično mapi kojim se može pristupiti 
 * postavkama spremljenim u datoteci u obliku parova postavka=vrijednost.
 * prazne linije i linije koje počinju znakom '#' se ignoriraju. 
 * Očekuje se jedan par postavka-vrijednost po liniji
 */
class Postavke{
	private:
		std::map<std::string,std::string> _postavke;
		int _ucitane;
	public:
		/**
		 * @brief konstruktor koji učitava podatke iz konfiguracijske daototeke
		 * 
		 * @param imeDatoteke putanja do datoteka
		 */
		Postavke(std::string imeDatoteke){
			std::ifstream ulaznaDatoteka;
			_ucitane=0;
			ulaznaDatoteka.open(imeDatoteke.c_str());
			if (ulaznaDatoteka){
				_ucitane = 1;
				std::string linija;
				while(std::getline(ulaznaDatoteka, linija)){
					if (linija.size()>0 && linija[0]!='#'){
						_postavke.insert(
							std::pair<std::string,std::string>(
								linija.substr(0,linija.find('=')), 
								linija.substr(linija.find('=')+1)
							)
						);
					}
				}
			}
		}
		
		/**
		 * @brief dohvaća iterator koji pokazuje na prvu spremljenu postavku
		 * @return iterator koji pokazuje na par ključ-vrijednost prve 
		 *  spremljene postavke
		 */
		std::map<std::string, std::string>::iterator begin(){
			return _postavke.begin();
		}
		
		/**
		 * @brief dohvaća iterator koji pokazuje na posljednju spremljenu postavku
		 * @return iterator koji pokazuje na par ključ-vrijednost posljednje 
		 *  spremljene postavke
		 */
		std::map<std::string, std::string>::iterator end(){
			return _postavke.end();
		}
		
		/**
		 * @brief operator kojim se dohvaća vrijednost tražene postavke
		 * @param kljuc ime traženog parametra
		 * @return vrijednost tražene postavke
		 */
		std::string operator[](std::string kljuc){
			return _postavke[kljuc];
		}
		
		/**
		 * @brief provjerava jesu li postavke ispravno procitane
		 * @return 1 ako su postavke dobro učitane ili 0 ako nisu
		 */
		int ucitane(){
			return _ucitane;
		}
		
		/**
		 * @brief dohvaća znakove i njihove vjerojatnosti
		 *
		 * @param znakovi vektor parova znakova i njihovih vjerojatnosti
		 */
		void dohvatiZnakove(std::vector< std::pair<char,double> >& znakovi){
			for (std::map<std::string,std::string>::iterator it = _postavke.begin(); it!=_postavke.end(); ++it){
			if (it->first.find("znak-")!=std::string::npos)
				znakovi.push_back(
					std::pair<char,double>(
						it->first[5],
						atof(it->second.c_str())
					)
				);	
		}
	}
};