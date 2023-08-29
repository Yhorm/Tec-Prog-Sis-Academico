#pragma once

#include "../headers/pessoa.h"

class Professor : public Pessoa
{
private:
	Universidade* profUniAfil;
	Departamento* profDepAfil;
public:
	Professor(int dia, int mes, int ano, std::string = "");
	Professor();
	~Professor();

	void setUniAfil(Universidade* pu);
	void showUniAfil();
	void setDepAfil(Departamento* dep);
	void showDepAfil();
};