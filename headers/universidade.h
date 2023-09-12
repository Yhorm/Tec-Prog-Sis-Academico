#pragma once
#include <iostream>

#include "../headers/listaDepartamento.h"
#include "entidade.h"


using namespace std;


class Universidade : public Entidade
{
private:

	string uName;
	listaDepartamento objLisDep;

public:
	Universidade(std::string nome = "", int i = -1, bool s = true);
	~Universidade();

	void setName(std::string nome = "");
	string getUniName();

	void setDep(Departamento* dep);
	void printDptos1();
	void printDptos2();
};