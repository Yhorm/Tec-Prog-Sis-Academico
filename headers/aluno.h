#pragma once

#include "../headers/pessoa.h"

class Aluno : public Pessoa
{
private:
	Universidade* aUniMatriculado;
	Departamento* aDepAfiliado;
	int RA;
public:
	Aluno(int dia, int mes, int ano, std::string nome = "", int ra = -1);
	Aluno();
	~Aluno();

	void setRA(int ra);
	void showRA();

	void setUniAfil(Universidade* pu);
	void showUniAfil();
	void setDepAfil(Departamento* dep);
	void showDepAfil();
};