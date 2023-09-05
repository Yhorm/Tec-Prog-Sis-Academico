#include <iostream>
#include "headers/universidade.h"

using namespace std;

//CONSTRUTORAS E DESTRUTORAS:
Universidade::Universidade(std::string nome) :
	objLisDep(-1, "")
{
	Inicializa(nome);
}

Universidade::~Universidade()
{
}

void Universidade::Inicializa(std:: string nome)
{
	setName(nome);
}

//SETA O NOME
void Universidade::setName(std::string nome)
{
	uName = nome;
	objLisDep.setName(nome);
}
//RETORNA O NOME
string Universidade::getUniName()
{
	return uName;
}
//SETA O DEPARTAMENTO
void Universidade::setDep(Departamento* dep)
{
	objLisDep.setDep(dep);
}
//MOSTRA TODOS OS DEPARTAMENTOS:
void Universidade::printDptos1()
{
	objLisDep.listDep1();
}
void Universidade::printDptos2()
{
	objLisDep.listDep2();
}