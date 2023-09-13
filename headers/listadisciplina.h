#pragma once

#include "eldisciplina.h"
#include "disciplina.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class listaDisciplina
{
private:
	string nome;
	int countDisciplinas;
	int numDisciplinas;

	elDisciplina* disAtual;
	elDisciplina* disPrim;
public:
	listaDisciplina(int nDis = 100, std::string n = "");
	~listaDisciplina();

	void setNome(std::string n);
	void setDisciplina(Disciplina* dis);

	void setAtual(elDisciplina* atual);
	void setPrim(elDisciplina* prim);

	void listDisciplina();
	void listDisciplina2();

	Disciplina* localiza(string n);

	void salvarDis();
	void recuperarDis();
};

