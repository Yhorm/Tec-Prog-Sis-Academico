#pragma once

#include <iostream>
#include "departamento.h"
#include "elDepartamento.h"
#include <fstream>
#include <string>

class listaDepartamento
{
private:
	int countDeps;
	int numDeps;

	string nome;

	elDepartamento* dPrim;
	elDepartamento* dAtual;
public:
	listaDepartamento(int n = 100, std::string no = "");
	~listaDepartamento();

	void setDep(Departamento* dep);
	void setName(std::string no);
	void listDep1();
	void listDep2();

	Departamento* localizar(string n);

	void salvarDeps();
	void recuperarDeps();
};

