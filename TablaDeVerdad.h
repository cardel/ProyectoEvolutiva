#ifndef TABLADEVERDAD_H
#define TABLADEVERDAD_H

#include <vector>
using namespace std;

class TablaDeVerdad
{
	public:
                TablaDeVerdad();
		TablaDeVerdad(int numVariables);
		~TablaDeVerdad();
		
		bool obtenerSalida(int posicionDecimal);		
		void escribirTablaDeVerdad(int posicionDecimal, bool valor);
		
		
		int getNumeroClausulas();
		
	private:
		int numVariables;
		vector<bool> tablaDeVerdad;
};
 
#endif
