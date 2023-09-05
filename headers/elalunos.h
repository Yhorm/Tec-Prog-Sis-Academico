#pragma once

#include <iostream>

using namespace std;

class Aluno;

class elAluno
{
private:
	Aluno* aluno;
public:
	elAluno* alunoProx;
	elAluno* alunoAnt;
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