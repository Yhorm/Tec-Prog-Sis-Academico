#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "pessoa.h"
#include "../headers/professor.h"
#include "../headers/listaalunos.h"
#include "../headers/listaDepartamento.h"
#include "../headers/listadisciplina.h"
#include "../headers/listUniversidade.h"


class Principal 
{
	private:
		Professor simao;
		Professor newton;
		Professor einstein;
		Aluno felipe;
		Aluno jorge;
		
		Universidade UTFPR;
		Universidade princeton;
		Universidade cambridge;

		Departamento DAINF, DAELN, DAMAT;
		Departamento physicsPrinceton;
		Departamento mathCambridge;

		Disciplina Comp1_2006;
		Disciplina Introd_Alg_2007;
		Disciplina Comp2_2007;
		Disciplina Metodos2_2007;

		listaAlunos listAlunos;
		listaDepartamento listDeps;
		listaDisciplina listDis;
		listUniversidade listUni;

		int diaAt = 0;
		int mesAt = 0;
		int anoAt = 0;
	public:

		Principal();
		~Principal();
		void Executar();

		void Inicializa();
		void InicializaUniversidades();
		void InicializaProfessores();
		void InicializaDepartamentos();
		void InicializaAlunos();
		void InicializaDisciplina();

		void calcIdade();
		void showDepAfil();
		void showUniAfil();
		void listDiscDeps();
		void listAlunosDisc();


		void Menu();
		void menuCad();
		void menuExec();

		void cadAluno();
		void cadDisci();
		void cadDep();
		void cadUni();

};

