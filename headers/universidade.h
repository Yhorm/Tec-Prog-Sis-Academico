#pragma once
#include <iostream>

#include "../headers/listaDepartamento.h"

#define DEP_QTD_MAX 50

using namespace std;


class Universidade
{
private:
	string uName;
	listaDepartamento objLisDep;

public:
	Universidade(std::string nome = "");
	
	~Universidade();

	void Inicializa(std::string nome = "");
	void setName(std::string nome = "");
	string getUniName();

	void setDep(Departamento* dep);
	void printDptos1();
	void printDptos2();
};