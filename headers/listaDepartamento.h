#pragma once

#include <iostream>
#include "departamento.h"
#include "elDepartamento.h"


class listaDepartamento
{
private:
	int countDeps;
	int numDeps;

	string nome;

	elDepartamento* dPrim;
	elDepartamento* dAtual;
public:
	listaDepartamento(int n = -1, std::string no = "");
	~listaDepartamento();

	void setDep(Departamento* dep);
	void setName(string no);
	void listDep1();
	void listDep2();
};

