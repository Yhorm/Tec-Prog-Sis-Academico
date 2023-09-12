#pragma once
#include <iostream>
#include <list>
#include "entidade.h"

using namespace std;

class Universidade;
class Disciplina;
class listaDisciplina;

class Departamento : public Entidade
{
	private: 

		string depName;
		Universidade* uniPoint;
		listaDisciplina* objListDisci;

	public:
		

		Departamento(int i = -1, bool s = true);
		~Departamento();
		
		void setDepName(std::string dName = "");
		string getDepName();
		int getId();

		void setUni(Universidade* uni);
		Universidade* getUni();

		void setDisciplina(Disciplina* dis);
		void listDisciplina();
		void listDisciplina2();

};