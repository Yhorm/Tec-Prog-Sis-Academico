#pragma once

#include "elalunos.h"
#include "aluno.h"

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
	listaAlunos(int n = -1, std::string no = "");
	~listaAlunos();

	void setAluno(Aluno* a);
	void listAlunos();
	void listAlunos2();

	void resizeAlunos(int n);

};

