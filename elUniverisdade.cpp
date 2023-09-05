#include "headers/elUniverisdade.h"

elUniversidade::elUniversidade()
{
	uni = NULL;
	uProx = NULL;
	uAnt = NULL;
}
elUniversidade::~elUniversidade()
{
	uni = NULL;
	uProx = NULL;
	uAnt = NULL;
}

void elUniversidade::setUni(Universidade* u)
{
	uni = u;
}
void elUniversidade::setProx(elUniversidade* prox)
{
	uProx = prox;
}
void elUniversidade::setAnt(elUniversidade* ant)
{
	uAnt = ant;
}

Universidade* elUniversidade::getUni()
{
	return uni;
}
elUniversidade* elUniversidade::getProx()
{
	return uProx;
}
elUniversidade* elUniversidade::getAnt()
{
	return uAnt;
}

string elUniversidade::getName()
{
	return uni->getUniName();
}
