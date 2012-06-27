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
	
	int numeroSolucion=0;
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
	
	FILE * ArchivoDeSalida;
	ArchivoDeSalida = fopen("Salida.txt", "w");
	
	char mystring[10000];
	srand ( time(NULL) );
	
	if(ArchivoDeEntrada==NULL) cout << "Error al leer entrada" << endl;
	else{
		while(!feof(ArchivoDeEntrada))
		{
			fscanf(ArchivoDeEntrada,"%d",&numeroVariables);
			numeroSolucion++;
			
			
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
							}							
					}
					
					//bool tablaDeFunciones[numeroLineas][sizeEntrada+1] ;
					//vector<vector <bool,bool> tabla;
			}
			
			/*
			 * Generar poblacion
			 */
			
			vector<Cromosoma*> poblacion;

			for(int i=0; i<poblacionInicial; i++)
			{
				int numeroClausulas=(int)(rand() % (numeroVariables+1));
				Cromosoma * aux = new Cromosoma(numeroClausulas,numeroVariables*2, usarMaxiterminos);				
				aux->GenerarIndividuo();
 				poblacion.push_back(aux);
			}
			
			//Iterar N veces
			/*
			 * Aqui iteramos n veces
			 * 
			 */
			Cromosoma * mejorCromosoma = poblacion.at(0);
			
			int numeroClausulas = mejorCromosoma->getNumeroClausulas();
			int numeroVariables = mejorCromosoma->getNumeroVariables();
			fprintf (ArchivoDeSalida, "%s%d%s","Solución #",numeroSolucion,":\n");

			//Representar cromosoma
			if(!usarMaxiterminos) 
			{
				for(int i=0; i<numeroClausulas; i++)
				{
					fprintf (ArchivoDeSalida, "%s","(");
					for(int j=0; j<numeroVariables; j++)
					{
						if(mejorCromosoma->get(i,j)==1){	
							int variable = (numeroVariables - j)/2;
							if (j%2==0) fprintf (ArchivoDeSalida, "%s%d","x",variable);
							else fprintf (ArchivoDeSalida, "%s%d","~x",variable);
							
							if(j<numeroVariables-1) fprintf(ArchivoDeSalida, "%s"," and ");
						}
					}
					fprintf (ArchivoDeSalida, "%s",")");

					if(i<numeroClausulas-1) fprintf(ArchivoDeSalida, "%s"," or ");
				}
				
				if(numeroClausulas>0) fprintf (ArchivoDeSalida, "%s","\n");
				else fprintf (ArchivoDeSalida, "%s","0\n");	
				
			}
			else
			{
				for(int i=0; i<numeroClausulas; i++)
				{
					
					fprintf (ArchivoDeSalida, "%s","(");
					
					for(int j=0; j<numeroVariables; j++)
					{		
						if(mejorCromosoma->get(i,j)==1){				
							int variable = (numeroVariables - j)/2;
							if (j%2==0) fprintf (ArchivoDeSalida, "%s%d","x",variable);
							else fprintf (ArchivoDeSalida, "%s%d","~x",variable);
							if(j<numeroVariables-1) fprintf(ArchivoDeSalida, "%s"," or ");
						}
					}
					fprintf (ArchivoDeSalida, "%s",")");
					
					if(i<numeroClausulas-1) fprintf(ArchivoDeSalida, "%s"," and ");
				}
				
				if(numeroClausulas>0) fprintf (ArchivoDeSalida, "%s","\n");
				else fprintf (ArchivoDeSalida, "%s","0\n");	
				
			}
			
		}
		fclose(ArchivoDeEntrada);
		fclose(ArchivoDeSalida);	
		
	}
	
	return 0;	
	
}
