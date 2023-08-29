#include "professor.h"

//CONSTRUTORAS E DESTRUTORAS:
Professor::Professor(int dia, int mes, int ano, std::string nome) :
	Pessoa(dia, mes, ano, nome)
{
	profUniAfil = NULL;
	profDepAfil = NULL;
}

Professor::Professor()
{
}

Professor::~Professor()
{
}


//SETA A UNIVERSIDADE EM QUE O PROF TRABALHA
void Professor::setUniAfil(Universidade* pu)
{
	profUniAfil = pu;
}

//MOSTRA A UNIVERSIDADE EM QUE O PROF TRABALHA MAS NÃO RETORNA.
void Professor::showUniAfil()
{
	cout << pName << " trabalha na universidade: " << profUniAfil->getUniName() << "." << endl;
}


//SETA O DEPARTAMENTO EM QUE O PROF TRABALHA
void Professor::setDepAfil(Departamento* dep)
{
	profDepAfil = dep;
}

//MOSTRA AMBOS: UNIVERSIDADE E DEPARTAMENTO QUE O PROF TRABALHA, MAS N RETORNA NENHUM.
void Professor::showDepAfil()
{
	cout << pName << " trabalha na universidade " << profUniAfil->getUniName() << " no departamento " << profDepAfil->getDepName() << endl;
}

