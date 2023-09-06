#pragma once

#include "headers/departamento.h"
#include "headers/universidade.h"
#include "headers/disciplina.h"
#include "headers/listadisciplina.h"
#include "headers/eldisciplina.h"

//CONSTRUTORAS E DESTRUTORAS:
Departamento::Departamento()
{
	objListDisci = new listaDisciplina(-1, " ");
}


Departamento::~Departamento()
{
	if (objListDisci)
	{
		delete objListDisci;
	}

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

int Departamento::getId()
{
	return id;
}

void Departamento::setUni(Universidade* uni)
{
	uniPoint = uni;
}

Universidade* Departamento::getUni()
{
	return uniPoint;
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

