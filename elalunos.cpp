#include "headers/elalunos.h"


elAluno::elAluno()
{
	aluno = NULL;
	alunoAnt = NULL;
	alunoProx = NULL;
}

elAluno::~elAluno()
{
	aluno = NULL;
	alunoAnt = NULL;
	alunoProx = NULL;

}

void elAluno::setAluno(Aluno* a)
{
	aluno = a;
}

void elAluno::setProx(elAluno* prox)
{
	alunoProx = prox;
}
void elAluno::setAnt(elAluno* ant)
{
	alunoAnt = ant;
}

elAluno* elAluno::getProx()
{
	return alunoProx;
}
elAluno* elAluno::getAnt()
{
	return alunoAnt;
}

Aluno* elAluno::getAluno()
{
	return aluno;
}
string elAluno::getName()
{
	return aluno->getName();
}
