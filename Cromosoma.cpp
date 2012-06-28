#include "Cromosoma.h"

Cromosoma::Cromosoma(int numClausulas, int numVariables, bool maxiTerminos)
{
	estCromosoma = new bool*[numClausulas];
	
	for(int i=0; i<numClausulas; i++)
	{
		estCromosoma[i]=new bool[numVariables];
	}
	numeroClausulas = numClausulas;
	numeroVariables = numVariables;
	usarMaxiTerminos=maxiTerminos;
	
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
	evaluarCromosoma();	
}


string Cromosoma::decimalABinario(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return decimalABinario(number / 2) + "0";
    else
        return decimalABinario(number / 2) + "1";
}

void Cromosoma::evaluarCromosoma()
{
	//Este S se incrementa 0 1 --> 10 11 --> 100 ... etc

	for(int s=0; s<numeroVariables; s++)
	{
		string representacionBinaria = decimalABinario(s);
		
		int correccion = log2(numeroVariables)-representacionBinaria.size();
		
		for(int k=0; k<correccion; k++)
		{
			representacionBinaria="0"+representacionBinaria;
		}
		
		bool resultado;
		if(!usarMaxiTerminos) resultado=0;
		else resultado=1;
		
		//Evaluar
		for(int i=0; i<numeroClausulas; i++)
		{
			bool resultadoClausula;
			for(int j=0; j<numeroVariables; j++)
			{
				if(!usarMaxiTerminos)
				{
					if(j==0) resultadoClausula = 1;					
					if(representacionBinaria==string("1"))
					{
						//Si es variable o variable negada
						if(j%2==0)	resultadoClausula&=estCromosoma[i][j];
						else resultadoClausula&=(!estCromosoma[i][j]);
					} 
				}
				else
				{
					if(j==0) resultadoClausula = 0;
					if(representacionBinaria==string("1"))
					{
						resultadoClausula|=estCromosoma[i][j];
					} 
				}
		
			}
			
			if(!usarMaxiTerminos) resultado|=resultadoClausula;
			else resultado&=resultadoClausula;

		
		}
                cromosomaEvaluado[s]==resultado;
	}

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


bool Cromosoma::obtenerSalida(int posicionDecimal)
{
    return cromosomaEvaluado[posicionDecimal];
}

double Cromosoma::getAptitud() const
{
    return aptitud;
}

void Cromosoma::setAptitud(double value)
{
    aptitud=value;
}

