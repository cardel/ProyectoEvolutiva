#include <cstdlib>
//#include <iostream>
#include "Cromosoma.h"

//using namespace std;

Cromosoma::Cromosoma(int numClausulas, int numVariables, bool maxiTerminos)
{
	estCromosoma = new bool*[numClausulas];
	
	for(int i=0; i<numClausulas; i++)
	{
		estCromosoma[i]=new bool[numVariables];
	}
	numeroClausulas = numClausulas;
	numeroVariables = numVariables;
	cromosomaEvaluado[numVariables];
}

Cromosoma::~Cromosoma()
{
		if(estCromosoma!=0)
		{
				delete [] estCromosoma;
				estCromosoma=0;
		}
}

void Cromosoma::GenerarIndividuo()
{

	for(int i=0; i<numeroClausulas; i++)
	{
		for(int j=0; j<numeroVariables; j++)
		{
			estCromosoma[i][j] = (rand() % 2);			
		}	
		
	}	

	/*for(int i=0; i<numeroClausulas; i++)
	{
		for(int j=0; j<numeroVariables; j++)
		{
			cout << estCromosoma[i][j]<<" ";
			
		}	
		cout << endl;
	}
	cout << endl;*/
		
}

bool Cromosoma::get(int x, int y)
{
	return estCromosoma[x][y];
}
void Cromosoma::set(int x, int y, bool z)
{
	estCromosoma[x][y]=z;
}

int Cromosoma::getNumeroClausulas()
{
	return numeroClausulas;
}


int Cromosoma::getNumeroVariables()
{
	return numeroVariables;
}

void evaluarCromosoma()
{
	
	
}

bool Cromosoma::obtenerSalida(int posicionDecimal)
{
	bool salida;
	for(int i=0; i<numeroClausulas; i++)
	{
		bool valorclasula;
		for(int j=0; j<numeroVariables; j++)
		{
			//Si negado es 0 la varible no es negada si es uno es negada
			int negado = j%2;
		}
	}
	return salida;
}
