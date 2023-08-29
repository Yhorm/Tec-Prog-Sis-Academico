#pragma once

#include "departamento.h"
#include "universidade.h"
#include "disciplina.h"

//CONSTRUTORAS E DESTRUTORAS:
Departamento::Departamento(std::string dName)
{
	Inicializa(dName);

}


Departamento::~Departamento()
{
}

void Departamento::Inicializa(std::string dName)
{
	setDepName(dName);
}

void Departamento::setDepName(std::string dName)
{
	depName = dName;
}

string Departamento::getDepName()
{
	return depName;
}

void Departamento::printDepName()
{
	cout << "Trabalha no departamento " << depName << endl;
}

int Departamento::getId()
{
	return id;
}

void Departamento::setUni(Universidade* uni)
{
	uniPoint = uni;
}

void Departamento::setDisciplina( Disciplina* dis)
{
	if (disciplinas.empty())
	{
		disciplinas.push_front(dis);
	}
	else
	{
		disciplinas.push_back(dis);
	}
}

void Departamento::listDisciplina()
{
	for (const auto &i: disciplinas)
	{
		cout << "Disciplina: " << i->getName() << "do departamento" << depName <<"." << endl;
	}
}

