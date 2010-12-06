#include <cstdlib>
#include <ctime>

/**
 * @brief klasa pomoću koje možemo generirati slučajne događaje
 * sa zadanom vjerojatnosti
 */
class GeneratorVjerojatnosti{
	public:
		/**
		 * @brief Stvara novi generator vjerojatnosti
		 */
		GeneratorVjerojatnosti(){
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
		int generirajVjerojatnost(double vjerojatnost){
			return rand() < vjerojatnost*RAND_MAX;
		}
};