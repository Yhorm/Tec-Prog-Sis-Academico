#pragma once
#include <iostream>
#include "universidade.h"
#include <locale.h>
#include <list>
#include <vector>

using namespace std;


class Pessoa {
protected:
	int bDay;
	int bMonth;
	int bYear;
	int age;
	string pName;

	Universidade* uniFiliado;
	Departamento* uniDepAfil;

public:
	Pessoa(int dia = -1, int mes = -1, int ano = -1, std::string nome = "");
	~Pessoa();
	
	void setName(string nome);
	void setBirthdate(int dia, int mes, int ano);


	void calcAge(int dia, int mes, int ano);
	int getAge();


	string getName();



};
