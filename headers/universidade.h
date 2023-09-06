#pragma once
#include <iostream>

#include "../headers/listaDepartamento.h"



using namespace std;


class Universidade
{
private:

	string uName;
	listaDepartamento objLisDep;

public:
	Universidade(std::string nome = "");
	~Universidade();

	void setName(std::string nome = "");
	string getUniName();

	void setDep(Departamento* dep);
	void printDptos1();
	void printDptos2();
};