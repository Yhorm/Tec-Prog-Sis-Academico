#pragma once
#include <iostream>

#include "departamento.h"

#define DEP_QTD_MAX 50

using namespace std;


class Universidade
{
private:
	string uName;

	Departamento* depAfil[DEP_QTD_MAX];

public:
	Universidade(std::string nome);
	Universidade();
	~Universidade();

	void Inicializa(std::string nome = "");
	void setName(std::string nome = "");
	string getUniName();
	void printUniName();

	void setDep(Departamento* dep, int ctd);
	void printDptos();
};