#ifndef TABLADEVERDAD_H
#define TABLADEVERDAD_H

#include <vector>

class TablaDeVerdad
{
	public:
		TablaDeVerdad(int numVariables);
		~TablaDeVerdad();
		
		bool obtenerSalida(int posicionDecimal);		
		void escribirTablaDeVerdad(int posicionDecimal, bool valor);
		
		
		int getNumeroClausulas();
		
	private:
		int numVariables;
		vector<bool> tablaDeVerdad;
 
#endif
