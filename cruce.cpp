#include "cruce.h"

Cruce::Cruce(vector<Cromosoma*> poblacion, bool usarMaxiterminos)
{
    this->poblacionSeleccionada=poblacion;
    this->usarMaxiterminos=usarMaxiterminos;
}

vector<Cromosoma*> Cruce::aplicarCruce()
{
    vector<Cromosoma*> hijos;
    int size = poblacionSeleccionada.size();
    
    if(size%2==1) size--;
    
    for(int i=0; i<size; i=i+2)
    {
		 Cromosoma* padre = poblacionSeleccionada[i], *madre=poblacionSeleccionada[i+1], *hijo1, *hijo2;
		 
		 int sizePadre = padre->getNumeroClausulas();
		 int sizeMadre = madre->getNumeroClausulas();
		 
		 int numeroVariables = madre->getNumeroVariables();
		 //Igualar cromosomas
		 if(sizePadre>sizeMadre)
		 {
				int diferencia = sizePadre-sizeMadre;
				Cromosoma * nuevaMadre = new Cromosoma(sizePadre, numeroVariables, usarMaxiterminos);
				
				//Llenar con lo que hay en la madre
				for(int x=0; x<sizeMadre; x++)
				{
					nuevaMadre->setClausula(x,madre->getClausula(x));
				}
				
				//Llenar el resto
				for(int x=sizeMadre; x<sizePadre; x++)
				{
					nuevaMadre->setClausula(x,madre->getClausula(x%sizeMadre));
				}
				madre = nuevaMadre;
				sizeMadre = sizePadre;
		 }

		 if(sizePadre<sizeMadre)
		 {
				int diferencia = sizePadre-sizeMadre;
				Cromosoma * nuevoPadre = new Cromosoma(sizeMadre, numeroVariables, usarMaxiterminos);
				
				//Llenar con lo que hay en la madre
				for(int x=0; x<sizePadre; x++)
				{
					nuevoPadre->setClausula(x,padre->getClausula(x));
				}
				
				//Llenar el resto
				for(int x=sizePadre; x<sizeMadre; x++)
				{
					nuevoPadre->setClausula(x,padre->getClausula(x%sizePadre));
				}
				padre = nuevoPadre;
				sizePadre = sizeMadre;
		 }
		 //Crear dos hijos
		 int alfa = 1;
		 if(sizeMadre>1) alfa = 1 + rand()%(sizeMadre-1);
		 
		 //Hijo 1

		 hijo1= new Cromosoma(alfa,numeroVariables, usarMaxiterminos);
		 
		 //Seleccionar elementos
		 int totalMadre, totalPadre;
		 if(alfa%1==0)
		 {
			totalMadre = alfa/2;
			totalPadre = alfa/2;
		 }else
		 {
			totalMadre = alfa/2;
			totalPadre = alfa/2;
			
			if(rand()%2==0) totalMadre++;
			else totalPadre++;			 
		 }
		 
		 for(int x=0; x<alfa; x++)
		 {
			if(x<totalPadre)
			{
				hijo1->setClausula(x,padre->getClausula(x));
			}
			else
			{
				hijo1->setClausula(x,madre->getClausula(x-totalPadre));
			}
		
		 }
		 //Hijo 2
		 int sizeHijo2= sizePadre-alfa+1;
		 hijo2= new Cromosoma(sizeHijo2,numeroVariables, usarMaxiterminos);
		 
		 if(sizeHijo2%1==0)
		 {
			totalMadre = sizeHijo2/2;
			totalPadre = sizeHijo2/2;
		 }else
		 {
			totalMadre = sizeHijo2/2;
			totalPadre = sizeHijo2/2;
			
			if(rand()%2==0) totalMadre++;
			else totalPadre++;			 
		 }
		 for(int x=0; x<hijo2->getNumeroClausulas(); x++)
		 {
			if(x<totalPadre)
			{
				hijo2->setClausula(x,padre->getClausula(alfa+x-1));
			}
			else
			{
				hijo2->setClausula(x,madre->getClausula(alfa+x-totalPadre-1));
			}		
		 }

		 hijos.push_back(hijo1);
		 hijos.push_back(hijo2);
	}	
    return hijos;
}
