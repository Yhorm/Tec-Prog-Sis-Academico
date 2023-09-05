#include "headers/elDepartamento.h"


elDepartamento::elDepartamento()
{
	dep = NULL;
	dProx = NULL;
	dAnt = NULL;
}
elDepartamento::~elDepartamento()
{
	dep = NULL;
	dProx = NULL;
	dAnt = NULL;
}

void elDepartamento::setDep(Departamento* d)
{
	dep = d;
}
void elDepartamento::setProx(elDepartamento* prox)
{
	dProx = prox;
}
void elDepartamento::setAnt(elDepartamento* ant)
{
	dAnt = ant;
}

Departamento* elDepartamento::getDep()
{
	return dep;
}
elDepartamento* elDepartamento::getProx()
{
	return dProx;
}
elDepartamento* elDepartamento::getAnt()
{
	return dAnt;
}

string elDepartamento::getName()
{
	return dep->getDepName();
}
