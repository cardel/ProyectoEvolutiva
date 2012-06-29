#include "Cromosoma.h"

Cromosoma::Cromosoma(int numClausulas, int numVariables, bool maxiTerminos)
{
	
	for(int i=0; i<numClausulas; i++)
	{
		bool * aux = new bool[numVariables];
		estadoCromosoma.push_back(aux);
	}
        aptitud=-1;
	numeroClausulas = numClausulas;
	numeroVariables = numVariables;
	numeroVariablesARepresentar = numVariables*2;
	numeroEntrada = pow(numVariables,2);
	usarMaxiTerminos = maxiTerminos;
	GenerarIndividuo();
}

Cromosoma::~Cromosoma()
{

}


void Cromosoma::GenerarIndividuo()
{
	for(int i=0; i<numeroClausulas; i++)
	{
		for(int j=0; j<numeroVariablesARepresentar; j++)
		{
			estadoCromosoma.at(i)[j] = (rand() % 2);			
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
	for(int s=0; s<numeroEntrada; s++)
	{
		string representacionBinaria = decimalABinario(s);
		
		int correccion = log2(numeroVariables)-representacionBinaria.size();
		
		for(int k=0; k<correccion; k++)
		{
			representacionBinaria="0"+representacionBinaria;
		}
		bool resultado=0;
		if(!usarMaxiTerminos) resultado=0;
		else resultado=1;	

		
		for(int i=0; i<numeroClausulas; i++)
		{
			bool evaluo = 0;
			bool resultadoClausula = 0;
			for(int j=0; j<representacionBinaria.size(); j++)
			{
				bool valor = representacionBinaria.at(j) - '0';
				if(!usarMaxiTerminos)
				{
					if(j==0) resultadoClausula = 1;					
					if(estadoCromosoma.at(i)[j*2]==1)
					{	
						evaluo=1;				
						resultadoClausula&=valor;
					} 
					if(estadoCromosoma.at(i)[j*2+1]==1)
					{
						evaluo=1;
						resultadoClausula&=(!valor);
					} 
				}
				else
				{
					if(j==0) resultadoClausula = 0;					
					if(estadoCromosoma.at(i)[j*2]==1)
					{	
						evaluo=1;				
						resultadoClausula|=valor;
					} 
					if(estadoCromosoma.at(i)[j*2+1]==1)
                        Cromosoma		{
						evaluo=1;
						resultadoClausula|=(!valor);
					} 
				}				

			}

			if(!evaluo) resultadoClausula=0;
			if(!usarMaxiTerminos) resultado|=resultadoClausula;
			else resultado&=resultadoClausula;		
			
	
		}
		cromosomaEvaluado.push_back(resultado);
	}

}

bool Cromosoma::get(int x, int y)
{
	return estadoCromosoma.at(x)[y];
}

vector<bool> Cromosoma::getClausula(int x)
{
	vector <bool> clausula;
	
	for(int y=0; y<numeroVariablesARepresentar; y++)
	{
		clausula.push_back(estadoCromosoma.at(x)[y]);
	}
	
	return clausula;
	
}

void Cromosoma::setClausula(int x, vector<bool> z)
{
	for(int y=0; y<z.size(); y++)
	{
		estadoCromosoma.at(x)[y] = z.at(y);
	}		
	
}

void Cromosoma::set(int x, int y, bool z)
{
	estadoCromosoma.at(x)[y]=z;
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
    return cromosomaEvaluado.at(posicionDecimal);
}

double Cromosoma::getAptitud()
{
    return aptitud;
}

void Cromosoma::setAptitud(double value)
{
    aptitud=value;
}

void Cromosoma::deleteClausula(int x)
{
    estadoCromosoma.erase(estadoCromosoma.begin()+x);
    numeroClausulas--;
}
