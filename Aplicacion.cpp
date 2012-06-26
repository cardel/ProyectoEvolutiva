#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio> 
#include <cmath> 
#include <vector> 
#include "Cromosoma.h"

using namespace std;



int main(int argc, char ** argv)
{
	string nombreArchivoEntrada="input.txt";
	string nombreArchivoSalida="output.txt";
	bool usarMaxiterminos=0;
	int poblacionInicial = 200;
	int numeroDeIteracciones = 500;
	int numeroVariables=0;
	
	/*
	 * Leer argumentos de entrada
	 */
	try{
		for(int i=1; i<argc; i+=2){
			string aux = string(argv[i]);
			
		
			if(aux==string("-f"))
			{
				nombreArchivoEntrada = string(argv[i+1]);
			}
			
			if(aux==string("-o"))
			{
				nombreArchivoSalida = string(argv[i+1]);				
			}
			
			if(aux==string("-t"))
			{
				usarMaxiterminos=atoi(argv[i+1]);
			}
			
			if(aux==string("-p"))
			{
				poblacionInicial=atoi(argv[i+1]);
				
			}
			
			if(aux==string("-i"))
			{
				numeroDeIteracciones=atoi(argv[i+1]);
			}
		}
	}
	catch(...)
	{
			cout << "Problema al leer los argumentos de entrada" << endl;
	}
	
	FILE * ArchivoDeEntrada;
	
	ArchivoDeEntrada = fopen("Entrada.txt", "r");
	
	char mystring[10000];
	
	if(ArchivoDeEntrada==NULL) cout << "Error al leer entrada" << endl;
	else{
		while(!feof(ArchivoDeEntrada))
		{
			fscanf(ArchivoDeEntrada,"%d",&numeroVariables);
			
			if(numeroVariables==0)
			{
					break;
			}
			else
			{
					int numeroLineas = (int)pow(numeroVariables,2);
					
					for(int i=0; i<numeroLineas; i++)
					{
							for(int j=0; j<numeroVariables+1; j++)
							{
									int f;
									fscanf(ArchivoDeEntrada,"%d",&f);
									cout << f;
							}
							
							cout << endl;
					}
					
					//bool tablaDeFunciones[numeroLineas][sizeEntrada+1] ;
					//vector<vector <bool,bool> tabla;
			}
			
			/*
			 * Generar poblacion
			 */
			srand ( time(NULL) );
			vector<Cromosoma*> poblacion;

			for(int i=0; i<poblacionInicial; i++)
			{
				int numeroClausulas=(int)(rand() % (numeroVariables+1));
				Cromosoma * aux = new Cromosoma(numeroClausulas,numeroVariables*2);				
				aux->GenerarIndividuo();
 				poblacion.push_back(aux);
			}
			
			//Iterar N veces
			
			Cromosoma * mejorCromosoma = poblacion.at(0);	
			//Representar cromosoma
			if(!usarMaxiterminos) 
			{
				int numeroClausulas = mejorCromosoma->getNumeroClausulas();
				int numeroVariables = mejorCromosoma->getNumeroVariables();
				
				for(int i=0; i<numeroClausulas; i++)
				{
					cout << "(";
					for(int j=0; j<numeroVariables; j++)
					{
						int variable = j/2;
						cout << "x" << variable << " and ";
					}
					cout <<") or ";
				}
				cout << endl;
				
			}
			else
			{
				
				
			}
			

			
		}
		fclose(ArchivoDeEntrada);
	}
	
	return 0;	
	
}
