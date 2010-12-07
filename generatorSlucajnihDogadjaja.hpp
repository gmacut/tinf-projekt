#include <cstdlib>
#include <ctime>
#include <vector>

/**
 * @brief klasa pomoću koje možemo generirati slučajne događaje
 * sa zadanom vjerojatnosti
 */
class GeneratorSlucajnihDogadjaja{
	public:
		/**
		 * @brief Stvara novi generator slučajnih događaja
		 */
		GeneratorSlucajnihDogadjaja(){
			srand((unsigned)time(NULL));
		}
		
		/**
		 * @brief metoda koja generira nasumične istinite 
		 * ili lažne vrijednosti. Ovisno o predanoj vrijednosti
		 * mijenja se vjerojatnost generiranja istinite vrijednosti.
		 * Za predanu vrijednost 0.2 očekuje se da će metoda u 
		 * otprilike 20% slučajeva generirati istinitu vrijednost
		 * 
		 * @param vjerojatnost vjerojatnost generiranja istinite vrijednosti
		 * @return istinita ili lažna vrijednost
		 */
		int generirajDogadjaj(double vjerojatnost){
			return rand() < vjerojatnost*RAND_MAX;
		}
		
		/**
		 * @brief metoda koja bira znak iz vektora znakova ovisno o njihovim
		 * vjerojatnostima pojavljivanja
		 * 
		 * @param znakovi vektor parova znakova i njihovih vjerojatnosti
		 * @return nasumičan znak iz liste znakova
		 */
		char odaberiZnak(std::vector< std::pair<char,double> > znakovi){
			double vjerojatnostDosad = 0;
			int nasumicnaVrijednost = rand();
			for (std::vector< std::pair<char,double> >::iterator it=znakovi.begin(); it != znakovi.end(); ++it){
				vjerojatnostDosad += it->second;
				if (nasumicnaVrijednost < vjerojatnostDosad * RAND_MAX)
					return it->first;
			}
			return znakovi[znakovi.size()-1].first;
		}
};