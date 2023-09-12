#pragma once

#include <iostream>

#include "departamento.h"
#include "listaalunos.h"
#include "entidade.h"


using namespace std;

class Disciplina : public Entidade
{
private:

	string dNome;
	string areaConhecimento;
	listaAlunos objlAlunos;
	Departamento* depAssociado;

	Disciplina* dProx;
	Disciplina* dAnt;

public:

	Disciplina(std::string nome = "", std::string area = "", int i = -1, bool s = true);
	~Disciplina();

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