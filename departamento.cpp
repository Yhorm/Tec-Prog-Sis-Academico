#pragma once

#include "headers/departamento.h"
#include "headers/universidade.h"
#include "headers/disciplina.h"
#include "headers/listadisciplina.h"
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

