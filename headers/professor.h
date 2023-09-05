#pragma once

#include "headers/pessoa.h"

class Professor : public Pessoa
{
private:
	Universidade* profUniAfil;
	Departamento* profDepAfil;
public:
	Professor(int dia = -1, int mes = -1, int ano = -1, std::string = "");

	~Professor();

	void setUniAfil(Universidade* pu);
	void showUniAfil();
	void setDepAfil(Departamento* dep);
	void showDepAfil();
};