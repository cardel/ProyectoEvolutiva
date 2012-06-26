#ifndef CROMOSOMA_H
#define CROMOSOMA_H

class Cromosoma
{
	public:
		Cromosoma(int numClausulas, int numVariables);
		~Cromosoma();
		void GenerarIndividuo();
		
		bool get(int x, int y);
		void set(int x, int y, bool z);
		
		int getNumeroClausulas();
		int getNumeroVariables();
		
	private:
		int numeroClausulas;
		int numeroVariables;
		bool ** estCromosoma;
};
 
#endif
