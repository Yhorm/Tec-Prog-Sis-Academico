#pragma once

#include "../Tec-Prog-Sis-Academico-master/headers/departamento.h"
#include "../Tec-Prog-Sis-Academico-master/headers/universidade.h"
#include "../Tec-Prog-Sis-Academico-master/headers/disciplina.h"
#include "../Tec-Prog-Sis-Academico-master/headers/listadisciplina.h"
#include "headers/eldisciplina.h"

//CONSTRUTORAS E DESTRUTORAS:
Departamento::Departamento(std::string dName)
{
	Inicializa(dName);
	objListDisci = new listaDisciplina(-1, " ");
}


Departamento::~Departamento()
{
	if (objListDisci)
	{
		delete objListDisci;
	}
}

void Departamento::Inicializa(std::string dName)
{
	setDepName(dName);
}

void Departamento::setDepName(std::string dName)
{
	depName = dName;
	objListDisci->setNome(dName);
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
	objListDisci->setDisciplina(dis);
}

void Departamento::listDisciplina()
{

	objListDisci->listDisciplina();
}
void Departamento::listDisciplina2()
{

	objListDisci->listDisciplina2();
}

