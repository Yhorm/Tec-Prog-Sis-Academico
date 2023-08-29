#include <iostream>
#include "../headers/universidade.h"

using namespace std;

//CONSTRUTORAS E DESTRUTORAS:
Universidade::Universidade(std::string nome)
{
	Inicializa(nome);
	for (int i = 0; i < DEP_QTD_MAX; i++)
	{
		depAfil[i] = NULL;
	}

}

Universidade::Universidade()
{
	Inicializa("");
	for (int i = 0; i < DEP_QTD_MAX; i++)
	{
		depAfil[i] = NULL;
	}

}

Universidade::~Universidade()
{
}

void Universidade::Inicializa(std:: string nome)
{
	for (int i = 0; i < DEP_QTD_MAX; i++)
	{
		depAfil[i] = NULL;
	}
	setName(nome);
}

//SETA O NOME
void Universidade::setName(std::string nome)
{
	uName = nome;
}
//RETORNA O NOME
string Universidade::getUniName()
{
	return uName;
}
//MOSTRA O NOME, MAS NÃO O RETORNA.
void Universidade::printUniName()
{
	cout << "O nome da universidade eh: " << uName << endl;
}
//SETA O DEPARTAMENTO
void Universidade::setDep(Departamento* dep, int ctd)
{
	depAfil[ctd] = dep;
}
//MOSTRA TODOS OS DEPARTAMENTOS:
void Universidade::printDptos()
{
	for (int i = 0; i < DEP_QTD_MAX; i++)
	{
		if (depAfil[i] != NULL)
		{
			cout << i << " - " << depAfil[i]->getDepName() << endl;
		}
	}
}