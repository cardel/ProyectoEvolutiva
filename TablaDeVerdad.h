#ifndef TABLADEVERDAD_H
#define TABLADEVERDAD_H

class TablaDeVerdad
{
	public:
		TablaDeVerdad(int numVariables);
		~TablaDeVerdad();
		
		bool obtenerValor(int posicionDecimal);
		
		void escribirTablaDeVerdad(int posicionDecimal, bool valor);
		
		
		int getNumeroClausulas();
		
	private:
		int numVariables;
		bool ** tablaDeVerdad;
};
 
#endif
