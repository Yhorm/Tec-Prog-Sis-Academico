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
#include <string>

using namespace std;

class Principal 
{
	private:
		Professor simao;
		Professor newton;
		Professor einstein;

		Aluno felipe;
		Aluno BBB;
		Aluno CCC;
		Aluno DDD;
		
		Universidade UTFPR;
		Universidade princeton;
		Universidade cambridge;

		Departamento DAINF, DAELN, DAMAT;
		Departamento physicsPrinceton;
		Departamento mathCambridge;

		Disciplina Comp1_2006;
		Disciplina IntrodAlg_2007;
		Disciplina Comp2_2007;
		Disciplina Metodos2_2007;

		listaDepartamento listDeps;
		listaDisciplina listDis;
		listUniversidade listUni;
		listaAlunos listAlunos;


		int diaAt = 0;
		int mesAt = 0;
		int anoAt = 0;

		int idProf = 0;
		int idAluno = 0;
		int idDisci = 0;
		int idDep = 0;
		int idUni = 0;
	public:

		Principal();
		~Principal();
		void Executar();

		void Inicializa();
		void InicializaUniversidades();
		void InicializaDepartamentos();
		void InicializaProfessores();
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
		void menuSalvar();
		void menuRecuperar();

		void cadAluno();
		void cadDisci();
		void cadDep();
		void cadUni();


		void salvarTudo();
		void salvarAlunos();
		void salvarDisci();
		void salvarDeps();
		void salvarUnis();

		void recuperarTudo();
		void recuperarAlunos();
		void recuperarDis();
		void recuperarDeps();
		void recuperarUnis();
};

