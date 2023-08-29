#pragma once
#include <iostream>
#include <list>

using namespace std;

class Universidade;
class Disciplina;

class Departamento 
{
	private: 
		string depName;
		int id;
		Universidade* uniPoint;
		
		std::list<Disciplina*> disciplinas;


	public:
		
		Departamento(std::string dName = "");
		~Departamento();
		
		void Inicializa(std:: string dName = "");
		void setDepName(std::string dName = "");
		string getDepName();
		void printDepName();
		int getId();

		void setUni(Universidade* uni);

		void setDisciplina(Disciplina* dis);
		void listDisciplina();

};