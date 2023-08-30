#pragma once

#include "../headers/eldisciplina.h"
#include "../headers/disciplina.h"

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

	void listDisciplina();
	void listDisciplina2();
};

