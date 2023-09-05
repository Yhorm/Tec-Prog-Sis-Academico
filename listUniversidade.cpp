#include "headers/listUniversidade.h"

listUniversidade::listUniversidade(int n , string no)
{
	countUni = 0;
	numUni = n;
	nome = no;
	
	uPrim = NULL;
	uAtual = NULL;
}
listUniversidade::~listUniversidade()
{
	countUni = -1;
	numUni = -1;
	nome = "";

	elUniversidade* aux1;
	elUniversidade* aux2;

	aux1 = uPrim;

	while (aux1 != NULL)
	{
		aux2 = aux1->getProx();
		delete aux1;
		aux1 = aux2;
	}

	uPrim = NULL;
	uAtual = NULL;
}

void listUniversidade::setUni(Universidade* uni)
{
	if (countUni < numUni && uni != NULL)
	{
		elUniversidade* aux = new elUniversidade();
		aux->setUni(uni);
		if (uPrim == NULL)
		{
			uPrim = aux;
			uAtual = aux;
		}
		else
		{
			uAtual->setProx(aux);
			aux->setAnt(uAtual);
			uAtual = aux;
		}
		countUni++;
	}
	else
	{
		cout << "QUANTIDADE LIMITE DE UNIVERSIDADES ATINGIDA." << endl;
	}
}

void listUniversidade::setName(string no)
{
	nome = no;
}

void listUniversidade::getUnis1()
{
	elUniversidade* aux = uPrim;
	while (aux->getProx() != NULL)
	{
		cout << "Universidade: " << aux->getName() << endl;
		aux = aux->getProx();
	}
}
void listUniversidade::getUnis2()
{
	elUniversidade* aux = uAtual;
	while (aux->getAnt() != NULL)
	{
		cout << "Universidade: " << aux->getName() << endl;
		aux = aux->getAnt();
	}
}
