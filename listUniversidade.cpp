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
	aux2 = aux1;

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
	elUniversidade* aux; 
	aux = new elUniversidade();
	
	aux->setAnt(NULL);
	aux->setProx(NULL);
	
	if (countUni < numUni && uni != NULL || numUni == -1 && uni != NULL)
	{
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

void listUniversidade::listUnis1()
{
	elUniversidade* aux = uPrim;
	while (aux != NULL)
	{
		cout << "Universidade: " << aux->getName() << endl;
		aux = aux->getProx();
	}
}
void listUniversidade::listUnis2()
{
	elUniversidade* aux = uAtual;
	while (aux != NULL)
	{
		cout << "Universidade: " << aux->getName() << endl;
		aux = aux->getAnt();
	}
}

Universidade* listUniversidade::localizar(string n)
{
	elUniversidade* aux;
	aux = uPrim;
	while (aux != NULL)
	{
		if (0 == n.compare(aux->getName()))
		{
			return aux->getUni();
		}
		aux = aux->getProx();
	}
	return NULL;
}
