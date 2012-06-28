#ifndef TABLADEVERDAD_H
#define TABLADEVERDAD_H

#include <vector>
using namespace std;

class TablaDeVerdad
{
	public:
		TablaDeVerdad();
		~TablaDeVerdad();
		
		bool obtenerSalida(int posicionDecimal);		
		void escribirTablaDeVerdad(bool valor);		
		
	private:
		vector<bool> tablaDeVerdad;
};
 
#endif
