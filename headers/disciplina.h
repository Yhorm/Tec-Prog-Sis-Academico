#pragma once
#include <iostream>
#include <vector>
#include "../Tec-Prog-Sis-Academico-master/headers/departamento.h"
#include "../Tec-Prog-Sis-Academico-master/headers/elalunos.h"
#include "../headers/listaalunos.h"

using namespace std;

class Aluno;

class Disciplina
{
private:
	string dNome;
	string areaConhecimento;

	int id;

	listaAlunos objlAlunos;
	Departamento* depAssociado;

public:

	elAluno* alunoPrim;
	elAluno* alunoAtual;


	Disciplina(std::string nome, std::string area, int id );
	Disciplina();
	~Disciplina();
	void Inicializa(std::string nome, std::string area, int id );

	void setName(std::string nome);
	string getName();

	void setArea(std::string area);
	string getArea();

	void setId(int id);
	int getId();

	void setDep(Departamento* dep);
	Departamento* getDep();

	void setAluno(Aluno* aluno);
	void listAlunos();
	void listAlunos2();
	void resizeAlunos(int nAlunos);
};