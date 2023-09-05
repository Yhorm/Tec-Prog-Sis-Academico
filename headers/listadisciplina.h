#pragma once

#include "eldisciplina.h"
#include "disciplina.h"

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
	listaDisciplina(int nDis, std::string n);
	listaDisciplina();
	~listaDisciplina();

	void setNome(std::string n);
	void setDisciplina(Disciplina* dis);

	void setAtual(elDisciplina* atual);
	void setPrim(elDisciplina* prim);

	void listDisciplina();
	void listDisciplina2();
};

