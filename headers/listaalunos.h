#pragma once

#include "../headers/elalunos.h"
#include "../headers/aluno.h"

using namespace std;

class listaAlunos
{
private:
	int countAlunos;
	int numAlunos;
	string nome;

	elAluno* alunoPrim;
	elAluno* alunoAtual;
public:
	listaAlunos(int n, std::string no);
	listaAlunos();
	~listaAlunos();

	void setAluno(Aluno* a);
	void listAlunos();
	void listAlunos2();

	void resizeAlunos(int n);

};

