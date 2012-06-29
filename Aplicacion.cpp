/*! 
 * \brief 
  <b>Proyecto de computación evolutiva</b><br/><br/>
	Este proyecto implementa la simplificación de funciones booleanas, proceso que normalmente se utiliza con mapas de Karnaugh.<br/><br/>
	El proceso se utiliza con maxitérminos y minitérminos.<br/>
	<br/> 
	La ejecución es de la siguiente forma:<br/><br/>
	<code>
	 ./exe -p <archivo de entrada> -o <archivo de salida> -i <número iteracciones máxima> -t <usar maxiterminos (0) o minitérminos> -p <población inicial>
	</code><br/><br/>
	La entrada del problema debe ser el número de bits  y  una función binaria, con sus entradas ordenadas por ejemplo:
	<code>
	2<br/>
    0 0 1<br/>
    0 1 0<br/>
    1 0 1<br/>
    1 1 0<br/>
    0
	</code><br/><br/>
	Pueden existir varias entradas, hasta que encuentra un 0 como número de bits<br/>
	<br/> 
	La salida, es la ecuación del mejor cromosoma<br/>
	<code>
	(x0 and x1) or (x0)
	</code>
 *  \author    Carlos Andres Delgado
 *  \author    Edgar Andres Moncada
 *  \author    Luis Felipe Vargas
 *  \version   1.0
 *  \date      2012
 *  \bug       No funciona con entradas con funciones desordenadas
 *  \warning   Evitar usar con entradas muy grandes
 *  \copyright GNU Public License.  
 *  \mainpage Descripción del proyecto.
 */

 

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstdio> 
#include <cmath> 
#include <vector> 
#include "Cromosoma.h"
#include "TablaDeVerdad.h"
#include "funcionSeleccionCruce.h"
#include "cruce.h"
#include "mutacion.h"
#include "seleccion.h"
#include "funcionaptitud.h"
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
	ArchivoDeEntrada = fopen(nombreArchivoEntrada.c_str(), "r");
	
	FILE * ArchivoDeSalida;
	ArchivoDeSalida = fopen(nombreArchivoSalida.c_str(), "w");
	
	char mystring[10000];
	srand ( time(NULL) );
	
	if(ArchivoDeEntrada==NULL) cout << "Error al leer entrada" << endl;
	else{
		while(!feof(ArchivoDeEntrada))
		{
			fscanf(ArchivoDeEntrada,"%d",&numeroVariables);
			numeroSolucion++;
			
			TablaDeVerdad * tablaVerdad = new TablaDeVerdad();
			int numeroLineas = (int)pow(numeroVariables,2);
			
			if(numeroVariables==0)
			{
					break;
			}
			else
			{
				for(int i=0; i<numeroLineas; i++)
				{
					
					for(int j=0; j<numeroVariables+1; j++)
					{
						int f;
						fscanf(ArchivoDeEntrada,"%d",&f);						
						if(j==numeroVariables) tablaVerdad->escribirTablaDeVerdad(f);
					}							
				}
			}
			
			//Población
			vector<Cromosoma*> poblacion;

			for(int i=0; i<poblacionInicial; i++)
			{
				int numeroClausulas=(int)(rand() % (numeroVariables))+1;
				Cromosoma * aux = new Cromosoma(numeroClausulas,numeroVariables, usarMaxiterminos);				
 				poblacion.push_back(aux);
			}


			//Iteracciones
                        for(int i=0; i<numeroDeIteracciones; i++)
			{
                            FuncionAptitud fa(poblacion, tablaVerdad, !usarMaxiterminos);
                            vector<Cromosoma*> poblacionOrganizadaAptitud = fa.aplicarAptitud();
                            FuncionSeleccionCruce fsc(poblacionOrganizadaAptitud,fa.obtenerMejorAptitud());
                            vector<Cromosoma*> poblacionCruzar = fsc.aplicarSeleccionCruce();
                            Cruce c(poblacionCruzar);
                            vector<Cromosoma*> hijos = c.aplicarCruce();
                            Mutacion m(hijos);
                            //vector<Cromosoma*> hijosMutados = m.aplicarMutacion();
//                            Seleccion s(poblacion,hijosMutados);
//                            poblacion= s.aplicarSeleccion();

                        }
			 
			Cromosoma * mejorCromosoma = poblacion.at(0);
			
		
			int numeroClausulas = mejorCromosoma->getNumeroClausulas();
			int numeroVariables = mejorCromosoma->getNumeroVariables();
			fprintf (ArchivoDeSalida, "%s%d%s","Solución #",numeroSolucion,":\n");
			
			for(int i=0; i<numeroClausulas; i++)
			{
				fprintf (ArchivoDeSalida, "%s","(");
				vector<string> escribirClausula;
				
				string operadorInterno;
				string operadorClausulas;
				
				if(!usarMaxiterminos)
				{
					operadorInterno=" and ";
					operadorClausulas=" or ";
				}
				else
				{
					operadorInterno=" or ";
					operadorClausulas=" and ";				
				}
				
				for(int j=0; j<numeroVariables; j++)
				{
					if(mejorCromosoma->get(i,j)==1){	
						int variable = (numeroVariables - j -1)/2;
						stringstream out;
						out << variable;
						
						if (j%2==0) escribirClausula.push_back("x"+out.str());
						else escribirClausula.push_back("~x"+out.str());						
					}
				}
				
				for(int k=0; k<escribirClausula.size(); k++)
				{
					fprintf (ArchivoDeSalida, "%s", escribirClausula.at(k).c_str());
					if(k<(escribirClausula.size()-1)) fprintf(ArchivoDeSalida,"%s", operadorInterno.c_str());
				}
				
				if(escribirClausula.size()==0) fprintf (ArchivoDeSalida, "%s","0");
				fprintf (ArchivoDeSalida, "%s",")");

				if(i<numeroClausulas-1) fprintf(ArchivoDeSalida, "%s",operadorClausulas.c_str());
			}

			if(numeroClausulas>0) fprintf (ArchivoDeSalida, "%s","\n");
			else fprintf (ArchivoDeSalida, "%s","0\n");	

		}
		fclose(ArchivoDeEntrada);
		fclose(ArchivoDeSalida);	
		
	}
	
	return 0;	
	
}
