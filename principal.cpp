#include "headers/principal.h"
#include "Windows.h"

Principal::Principal()
{
	//Estrutura para utilizar o time.h: 
	SYSTEMTIME st;
	GetSystemTime(&st);

	diaAt = st.wDay;
	mesAt = st.wMonth;
	anoAt = st.wYear;

	Inicializa();
}


Principal::~Principal()
{
}

void Principal::Executar()
{
	/*
	calcIdade();
	showUniAfil();
	showDepAfil();
	listDiscDeps();
	listAlunosDisc();
	*/
	Menu();
}


void Principal::Inicializa()
{
	InicializaAlunos();	
	InicializaUniversidades();
	InicializaDepartamentos();
	InicializaDisciplina();
	InicializaProfessores();

}


void Principal::InicializaUniversidades()
{
	UTFPR.setName("UTFPR");
	listUni.setUni(&UTFPR);

	cambridge.setName("Cambridge");
	listUni.setUni(&cambridge);

	princeton.setName("Princeton");
	listUni.setUni(&princeton);

}
void Principal::InicializaProfessores()
{
	simao.setName("Jean Simao");
	simao.setBirthdate(3, 10, 1976);

	newton.setName("Sir Isaac Newton");
	newton.setBirthdate(4, 1, 1643);

	einstein.setName("Albert Einstein");
	einstein.setBirthdate(14, 3, 1879);

	simao.setUniAfil(&UTFPR);
	simao.setDepAfil(&DAELN);

	newton.setUniAfil(&cambridge);
	newton.setDepAfil(&mathCambridge);

	einstein.setUniAfil(&princeton);
	einstein.setDepAfil(&physicsPrinceton);

}
void Principal::InicializaDepartamentos()
{
	DAINF.setDepName("DAINF");
	DAELN.setDepName("DAELN");
	DAMAT.setDepName("DAMAT");
	physicsPrinceton.setDepName("FISICA - PRINCETON");
	mathCambridge.setDepName("MATEMATICA - CAMBRIDGE");

	listDeps.setDep(&DAINF);
	listDeps.setDep(&DAELN);
	listDeps.setDep(&DAMAT);

	listDeps.setDep(&physicsPrinceton);
	
	listDeps.setDep(&mathCambridge);

	UTFPR.setDep(&DAINF);
	UTFPR.setDep(&DAELN);
	UTFPR.setDep(&DAMAT);

	princeton.setDep(&physicsPrinceton);

	cambridge.setDep(&mathCambridge);
}
void Principal::InicializaAlunos()
{
	felipe.setName("Felipe");
	felipe.setBirthdate(9, 8, 2002);

	BBB.setName("BBB");
	CCC.setName("CCC");
	DDD.setName("DDD");

	listAlunos.setAluno(&felipe);
	listAlunos.setAluno(&BBB);
	listAlunos.setAluno(&CCC);
	listAlunos.setAluno(&DDD);

}
void Principal::InicializaDisciplina()
{
	Comp1_2006.setName("Computação 1 - 2006");
	IntrodAlg_2007.setName("Introdução a Algoritmos - 2007");
	Comp2_2007.setName("Computação 2 - 2007");
	Metodos2_2007.setName("Metodos 2 - 2007");

	listDis.setDisciplina(&Comp1_2006);
	listDis.setDisciplina(&IntrodAlg_2007);
	listDis.setDisciplina(&Comp2_2007);
	listDis.setDisciplina(&Metodos2_2007);

	Comp1_2006.setDep(&DAELN);
	IntrodAlg_2007.setDep(&DAINF);
	Comp2_2007.setDep(&DAELN);
	Metodos2_2007.setDep(&DAELN);

	IntrodAlg_2007.setAluno(&felipe);
	IntrodAlg_2007.setAluno(&BBB);
	IntrodAlg_2007.setAluno(&CCC);

	Comp2_2007.setAluno(&BBB);
	Comp2_2007.setAluno(&DDD);

}

void Principal::calcIdade()
{
	felipe.calcAge(diaAt, mesAt, anoAt);
	simao.calcAge(diaAt, mesAt, anoAt);
	einstein.calcAge(diaAt, mesAt, anoAt);
	newton.calcAge(diaAt, mesAt, anoAt);

}
void Principal::showDepAfil()
{
	simao.showDepAfil();
	einstein.showDepAfil();
	newton.showDepAfil();
}
void Principal::showUniAfil()
{
	simao.showUniAfil();
	einstein.showUniAfil();
	newton.showUniAfil();
}
void Principal::listDiscDeps()
{
	DAELN.listDisciplina();
	printf("\n");
	DAINF.listDisciplina();
	printf("\n");
}

void Principal::listAlunosDisc()
{
	IntrodAlg_2007.listAlunos();
	printf("\n");
	Comp2_2007.listAlunos();
	printf("\n");
}

void Principal::Menu()
{
	int opt = 0;

	while (opt != 3)
	{
		system("cls");
		cout << "-------- SELECIONE UMA DAS OP��ES ABAIXO --------" << endl;
		cout << "-------- 1 - CADASTRAR --------" << endl;
		cout << "-------- 2 - EXECUTAR --------" << endl;
		cout << "-------- 3 - SAIR  --------" << endl;
		cin >> opt;


		switch (opt)
		{
		case 1: {
			menuCad();
		}
			  break;
		case 2: {
			menuExec();
		}
			  break;
		case 3: {
			cout << "SAINDO DO SISTEMA" << endl;
		}
			  break;
		default: {
			cout << "OPÇÃO INV�LIDA. " << endl;
			system("Pause");
		}
		}
	}
}


void Principal::menuCad()
{
	int opt = 0;

	while (opt != 5)
	{
		system("cls");
		cout << "-------- SELECIONE UMA DAS OP��ES ABAIXO --------" << endl;
		cout << "-------- 1 - CADASTRAR UMA UNIVERSIDADE --------" << endl;
		cout << "-------- 2 - CADASTRAR UM DEPARTAMENTO --------" << endl;
		cout << "-------- 3 - CADASTRAR UMA DISCIPLINA  --------" << endl;
		cout << "-------- 4 - CADASTRAR UM ALUNO --------" << endl;
		cout << "-------- 5 - SAIR --------" << endl;
		cin >> opt;

		switch (opt)
		{
			case 1:
			{
				cadUni();
			}
			break;
			case 2:
			{
				cadDep();
			}
			break;
			case 3:
			{
				cadDisci();
			}
			break;
			case 4:
			{
				cadAluno();
			}
			case 5:
			{
				cout << "SAINDO DO SISTEMA" << endl;
			}
			break;
			default: 
			{
				cout << "OPÇÃO INV�LIDA." << endl;
				system("Pause");
			}
		}
	}
}

void Principal::menuExec()
{
	int opt = 0;
	while(opt != 5)
	{
		system("cls");
		cout << "-------- SELECIONE UMA DAS OP��ES ABAIXO --------" << endl;
		cout << "-------- 1 - LISTAR ALUNOS --------" << endl;
		cout << "-------- 2 - LISTAR AS UNIVERSIDADES --------" << endl;
		cout << "-------- 3 - LISTAR OS DEPARTAMENTOS --------" << endl;
		cout << "-------- 4 - LISTAR AS DISCIPLINAS  --------" << endl;
		cout << "-------- 5 - SAIR --------" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1:
		{
			listAlunos.listAlunos();
			fflush(stdin);
			getchar();
		}
		break;
		case 2:
		{
			listUni.listUnis1();
			fflush(stdin);
			getchar();
		}
		break;
		case 3:
		{
			listDeps.listDep1();
			fflush(stdin);
			getchar();
		}
		break;
		case 4:
		{
			listDis.listDisciplina();
			fflush(stdin);
			getchar();
		}
		case 5:
		{
			cout << "SAINDO DO SISTEMA." << endl;
		}
		break;
		default:
		{
			cout << "OPÇÃO INV�LIDA." << endl;
			system("Pause");
		}
		}
	}
}


void Principal::cadAluno()
{
	string nomeAluno;
	string nomeDisci;
	string nomeUni;
	string nomeDep;

	int dia = 0, mes = 0, ano = 0, RA = 0;

	Aluno* aluno;
	Universidade* uni;
	Departamento* dep;
	Disciplina* dis;


	cout << "Digite o nome da universidade do departamento: " << endl;
	cin >> nomeUni;

	uni = listUni.localizar(nomeUni);
	if (uni != NULL)
	{
		cout << "Digite o nome do departamento: " << endl;
		cin >> nomeDep;
		dep = listDeps.localizar(nomeDep);
		if (dep != NULL)
		{
			cout << "Digite o nome da disciplina: " << endl;
			cin >> nomeDisci;
			dis = listDis.localiza(nomeDisci);
			if (dis != NULL)
			{
				cout << "Digite o nome do aluno." << endl;
				cin >> nomeAluno;

				aluno = new Aluno();
				aluno->setName(nomeAluno);
				
				cout << "Digite a data de nascimento do aluno no formado DDMMYYYY: " << endl;
				cin >> dia >> mes >> ano;

				aluno->setBirthdate(dia, mes, ano);

				cout << "Digite o RA do aluno: " << endl;
				cin >> RA;
				aluno->setRA(RA);

				listAlunos.setAluno(aluno);
				dis->setAluno(aluno);

				aluno->calcAge(diaAt, mesAt, anoAt);

			}
			else
			{
				cout << "Disciplina não existente." << endl;
			}
		}
		else
		{
			cout << "Departamento não existente." << endl;
		}
	}
	else
	{
		cout << "Universidade não existente." << endl;
	}
}


void Principal::cadDisci()
{
	string nomeDisci;
	string nomeUni;
	string nomeDep;

	Universidade* uni;
	Departamento* dep;
	Disciplina* dis;


	cout << "Digite o nome da universidade do departamento: " << endl;
	cin >> nomeUni;

	uni = listUni.localizar(nomeUni);
	if (uni != NULL)
	{
		cout << "Digite o nome do departamento: " << endl;
		cin >> nomeDep;
		dep = listDeps.localizar(nomeDep);
		if (dep != NULL)
		{
			cout << "Digite o nome da disciplina: " << endl;
			cin >> nomeDisci;

			dis = new Disciplina();
			dis->setName(nomeDisci);
			dis->setDep(dep);
			listDis.setDisciplina(dis);
		}
		else
		{
			cout << "Departamento não existente." << endl;
		}
	}
	else
	{
		cout << "Universidade não existente." << endl;
	}
}
void Principal::cadDep()
{
	string nomeUni;
	string nomeDep;

	Universidade* uni;
	Departamento* dep;

	cout << "Digite o nome da universidade do departamento: " << endl;
	cin >> nomeUni;
	
	uni = listUni.localizar(nomeUni);
	if (uni != NULL)
	{
		cout << "Digite o nome do departamento: " << endl;
		cin >> nomeDep;
		
		dep = new Departamento();
		dep->setDepName(nomeDep);
		dep->setUni(uni);
		listDeps.setDep(dep);
		uni->setDep(dep);
	}
	else
	{
		cout << "Universidade não existente." << endl;
	}


}
void Principal::cadUni()
{
	string nome;
	Universidade* univ = NULL;
	
	cout << "Digite o nome da universidade: " << endl;
	cin >> nome;

	univ = new Universidade();
	univ->setName(nome);
	listUni.setUni(univ);

}