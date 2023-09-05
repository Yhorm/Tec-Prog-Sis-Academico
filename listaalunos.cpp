#include "headers/listaalunos.h"


listaAlunos::listaAlunos(int n, std::string no)
{
	countAlunos = 0;
	numAlunos = n;
	nome = no;
	alunoPrim = NULL;
	alunoAtual = NULL;
}

listaAlunos::~listaAlunos()
{
	countAlunos = -1;
	numAlunos = -1;
	nome = "";
	
	elAluno* aux1 = NULL;
	elAluno* aux2 = NULL;

	aux1 = alunoPrim;

	while (aux1 != NULL)
	{
		aux2 = aux1->alunoProx;
		delete aux1;
		aux1 = aux2;
	}


	alunoPrim = NULL;
	alunoAtual = NULL;
}


void listaAlunos::setAluno(Aluno* aluno)
{

	if (countAlunos < numAlunos && aluno != NULL)
	{
		elAluno* aux = new elAluno();
		aux->setAluno(aluno);
		if (alunoPrim == NULL)
		{
			alunoAtual = aux;
			alunoPrim = aux;
		}
		else
		{
			alunoAtual->setProx(aux);
			aux->setAnt(alunoAtual);
			alunoAtual = aux;
		}
		countAlunos++;
	}
	else
	{
		cout << "TURMA LOTADA, ALUNO NÃO SERA INCLUIDO." << endl;
	}

}
void listaAlunos::listAlunos()
{

	elAluno* aux = alunoPrim;

	while (aux->getProx() != NULL)
	{
		cout << "O(a) aluno(a) " << aux->getName() << " estuda a disciplina: " << nome << endl;
		aux = aux->getProx();
	}
}

void listaAlunos::listAlunos2()
{
	elAluno* aux = alunoAtual;

	while (aux->alunoAnt != NULL)
	{
		cout << "O(a) aluno(a) " << aux->getName() << " estuda a disciplina: " << nome << endl;
		aux = aux->alunoAnt;
	}
}

void listaAlunos::resizeAlunos(int n)
{
	numAlunos = n;

}