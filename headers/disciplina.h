#pragma once

#include <iostream>
#include <vector>

#include "departamento.h"
#include "elalunos.h"
#include "listaalunos.h"
#include "aluno.h"

using namespace std;

class Disciplina
{
private:
	string dNome;
	string areaConhecimento;

	int id;

	listaAlunos objlAlunos;
	Departamento* depAssociado;

	Disciplina* dProx;
	Disciplina* dAnt;

public:

	Disciplina(std::string nome = "", std::string area = "", int id = -1);
	~Disciplina();
	void Inicializa(std::string nome, std::string area, int id);

	void setName(std::string nome);
	string getName();

	void setProx(Disciplina* prox);
	void setAnt(Disciplina* ant);

	Disciplina* getProx();
	Disciplina* getAnt();

	void setId(int id);
	int getId();

	void setDep(Departamento* dep);
	Departamento* getDep();

	void setAluno(Aluno* aluno);
	void listAlunos();
	void listAlunos2();
	void resizeAlunos(int nAlunos);
};