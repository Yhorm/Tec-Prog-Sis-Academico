#pragma once
#include <iostream>
#include <vector>
#include "departamento.h"


using namespace std;

class Aluno;

class Disciplina
{
private:
	string dNome;
	string areaConhecimento;

	int id;
	int numAlunos;
	int countAlunos;

	vector <Aluno*> alunos;

	Departamento* depAssociado;

public:

	Disciplina(std::string nome, std::string area, int id, int nAlunos);
	Disciplina();
	~Disciplina();
	void Inicializa(std::string nome, std::string area, int id, int nAlunos);

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

	void resizeAlunos(int nAlunos);
};