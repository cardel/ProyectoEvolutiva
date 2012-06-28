#include "TablaDeVerdad.h"


TablaDeVerdad::TablaDeVerdad(){
}
TablaDeVerdad::~TablaDeVerdad(){
}


bool TablaDeVerdad::obtenerSalida(int posicionDecimal)
{
	return tablaDeVerdad.at(posicionDecimal);
}

void TablaDeVerdad::escribirTablaDeVerdad(bool valor)
{
	tablaDeVerdad.push_back(valor);
}
