#pragma once

#include <iostream>

#include "aluno.h"
using namespace std;


class elAluno
{
private:
	Aluno* aluno;
	elAluno* alunoProx;
	elAluno* alunoAnt;
public:

	elAluno();
	~elAluno();

	void setAluno(Aluno* a);
	void setProx(elAluno* prox);
	void setAnt(elAluno* ant);

	elAluno* getProx();
	elAluno* getAnt();
	Aluno* getAluno();
	string getName();

};