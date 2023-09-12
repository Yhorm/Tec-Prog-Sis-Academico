#pragma once

#include "pessoa.h"

class Aluno : public Pessoa
{
private:
	Departamento* aDepAfiliado;
	Disciplina* aDiscAfiliado;
	int RA;
public:

	Aluno* alunoProx;
	Aluno* alunoAnt;

	Aluno(int dia = -1, int mes = -1, int ano = -1, std::string nome = "", int r = -1, int i = -1, bool s = true);
	~Aluno();

	void setRA(int ra);
	int getRA();

	void setDepAfil(Departamento* dep);
	Departamento* getDepAfil();

	void setDisAfil(Disciplina* dis);
	Disciplina* getDisAfil();
};