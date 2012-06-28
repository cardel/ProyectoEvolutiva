#ifndef CROMOSOMA_H
#define CROMOSOMA_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Cromosoma
{
	public:
		Cromosoma(int numClausulas, int numVariables, bool maxiTerminos);
		~Cromosoma();
		void GenerarIndividuo();
		
		bool get(int x, int y);
		void set(int x, int y, bool z);
		
		int getNumeroClausulas();
		int getNumeroVariables();
		
                bool obtenerSalida(int posicionDecimal);

                 //! adicionado por edgar//
                double getAptitud();
                void setAptitud(double value);
		
	private:
		int numeroClausulas;
		int numeroVariables;
		bool ** estCromosoma;
		
		bool cromosomaEvaluado[];
		bool usarMaxiTerminos;
		void evaluarCromosoma();
		
		string decimalABinario(int number);

                //! adicionado por edgar//
                double aptitud;
};
 
#endif
