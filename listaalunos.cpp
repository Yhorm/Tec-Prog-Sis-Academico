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
	aux2 = aux1;

	while (aux1 != NULL)
	{
		aux2 = aux1->getProx();
		delete aux1;
		aux1 = aux2;
	}


	alunoPrim = NULL;
	alunoAtual = NULL;
}


void listaAlunos::setAluno(Aluno* aluno)
{

	elAluno* aux; 
	aux = new elAluno();
	aux->setAluno(aluno);

	aux->setAnt(NULL);
	aux->setProx(NULL);

	if (countAlunos < numAlunos && aluno != NULL || numAlunos == -1 && aluno != NULL)
	{

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

	while (aux != NULL)
	{
		cout << "O(a) aluno(a) " << aux->getName() << " estuda a disciplina: " << nome << endl;
		aux = aux->getProx();
	}
}

void listaAlunos::listAlunos2()
{
	elAluno* aux = alunoAtual;

	while (aux != NULL)
	{
		cout << "O(a) aluno(a) " << aux->getName() << " estuda a disciplina: " << nome << endl;
		aux = aux->getAnt();
	}
}

void listaAlunos::resizeAlunos(int n)
{
	numAlunos = n;

}