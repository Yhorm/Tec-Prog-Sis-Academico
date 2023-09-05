#pragma once

#include "pessoa.h"

class Aluno : public Pessoa
{
private:

	Departamento* aDepAfiliado;
	int id;
	int RA;
public:

	Aluno* alunoProx;
	Aluno* alunoAnt;

	Aluno(int dia = -1, int mes = -1, int ano = -1, std::string nome = "", int r = -1, int i = -1);
	~Aluno();

	void setRA(int ra);
	void showRA();

	void setDepAfil(Departamento* dep);
};