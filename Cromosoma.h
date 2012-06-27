#ifndef CROMOSOMA_H
#define CROMOSOMA_H

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
		
	private:
		int numeroClausulas;
		int numeroVariables;
		bool ** estCromosoma;
		
		bool cromosomaEvaluado[];
		bool usarMaxiTerminos;
		void evaluarCromosoma();
};
 
#endif
