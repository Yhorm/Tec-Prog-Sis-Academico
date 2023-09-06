#pragma once
#include <iostream>
#include <list>

using namespace std;

class Universidade;
class Disciplina;
class listaDisciplina;

class Departamento 
{
	private: 
		string depName;
		int id;
		Universidade* uniPoint;

		listaDisciplina* objListDisci;

	public:
		

		Departamento();
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