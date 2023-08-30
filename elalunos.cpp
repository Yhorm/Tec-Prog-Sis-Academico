#include "../Tec-Prog-Sis-Academico-master/headers/elalunos.h"

elAluno::elAluno(int n)
{
	countAlunos = 0;
	numAlunos = n;
	aluno = NULL;
	alunoAnt = NULL;
	alunoProx = NULL;
}

elAluno::elAluno()
{
	numAlunos = -1;
	countAlunos = -1;
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

Aluno* elAluno::getAluno()
{
	return aluno;
}
string elAluno::getName()
{
	return aluno->getName();
}
