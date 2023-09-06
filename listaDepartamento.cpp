#include "../Tec-Prog-Sis-Academico/headers/listaDepartamento.h"

listaDepartamento::listaDepartamento(int n, std::string no)
{
	countDeps = 0;
	numDeps = n;
	nome = no;

	dPrim = NULL;
	dAtual = NULL;

}
listaDepartamento::~listaDepartamento()
{
	countDeps = -1;
	numDeps = -1;
	nome = "";

	elDepartamento* aux1;
	elDepartamento* aux2;

	aux1 = dPrim;
	aux2 = aux1;

	while (aux1 != NULL)
	{
		aux2 = aux1->getProx();
		delete aux1;
		aux1 = aux2;
	}

	dPrim = NULL;
	dAtual = NULL;
}

void listaDepartamento::setDep(Departamento* dep)
{
	elDepartamento* aux; 
	aux = new elDepartamento();
	aux->setDep(dep);

	aux->setAnt(NULL);
	aux->setProx(NULL);

	if (countDeps < numDeps && dep != NULL || numDeps == -1 && dep != NULL)
	{

		if (dPrim == NULL)
		{
			dPrim = aux;
			dAtual = aux;
		}
		else
		{
			dAtual->setProx(aux);
			aux->setAnt(dAtual);
			dAtual = aux;
		}
		countDeps++;
	}
	else
	{
		cout << "LIMITE ATINGIDO: DEPARTAMENTO N INSERIDO" << endl;
	}
}

void listaDepartamento::setName(string no)
{
	nome = no;
}
void listaDepartamento::listDep1()
{
	elDepartamento* aux = dPrim;

	while (aux != NULL)
	{
		cout << "Departamento: " << aux->getName() << endl;
		aux = aux->getProx();
	}
}
void listaDepartamento::listDep2()
{
	elDepartamento* aux = dAtual;

	while (aux != NULL)
	{
		cout << "Departamento: " << aux->getName() << endl;
		aux = aux->getAnt();
	}
}

Departamento* listaDepartamento::localizar(string n)
{
	elDepartamento* aux;
	aux = dPrim;

	while (aux != NULL)
	{
		if (0 == n.compare(aux->getName()))
		{
			return aux->getDep();
		}
		aux = aux->getProx();
	}
	return NULL;
}