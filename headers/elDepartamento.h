#pragma once

#include <iostream>
#include "departamento.h"


class elDepartamento
{
private:
	Departamento* dep;
	elDepartamento* dProx;
	elDepartamento* dAnt;
public:

	elDepartamento();
	~elDepartamento();

	void setDep(Departamento* d);
	void setProx(elDepartamento* prox);
	void setAnt(elDepartamento* ant);

	Departamento* getDep();
	elDepartamento* getProx();
	elDepartamento* getAnt();

	string getName();
};

