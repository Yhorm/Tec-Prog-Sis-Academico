#pragma once

#include "../headers/aluno.h"
#include <iostream>

using namespace std;


class elAluno
{
private:
	int numAlunos;
	int countAlunos;
	Aluno* aluno;
public:
	elAluno* alunoProx;
	elAluno* alunoAnt;
	elAluno(int n);
	elAluno();
	~elAluno();

	void setAluno(Aluno* a);

	Aluno* getAluno();
	string getName();

};