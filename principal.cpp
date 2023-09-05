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
	showDepAfil();
	listDiscDeps();
	listAlunosDisc();
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
	//Inicializa as universidades:
	UTFPR.Inicializa("UTFPR");
	listUni.setUni(&UTFPR);
	cambridge.Inicializa("Cambridge");
	listUni.setUni(&cambridge);
	princeton.Inicializa("Princeton");
	listUni.setUni(&princeton);

}
void Principal::InicializaProfessores()
{
	simao.Inicializa(3, 10, 1976, "Jean Sim�o");
	newton.Inicializa(4, 1, 1643, "Isaac Newton");
	einstein.Inicializa(14, 3, 1879, "Albert Einstein");

	simao.setUniAfil(&UTFPR);
	newton.setUniAfil(&cambridge);
	einstein.setUniAfil(&princeton);

	simao.setDepAfil(&DAELN);
	newton.setDepAfil(&mathCambridge);
	einstein.setDepAfil(&physicsPrinceton);
}
void Principal::InicializaDepartamentos()
{
	//Inicializa os departamentos:
	DAINF.Inicializa("DAINF");
	DAELN.Inicializa("DAELN");
	DAMAT.Inicializa("DAMAT");
	mathCambridge.Inicializa("Matematica na Universidade de Cambridge");
	physicsPrinceton.Inicializa("Fisica na Universidade de Princeton");

	//Filia os departamentos as universidades:
	listDeps.setDep(&DAINF);
	listDeps.setDep(&DAELN);
	listDeps.setDep(&DAMAT);
	listDeps.setDep(&mathCambridge);
	listDeps.setDep(&physicsPrinceton);

	UTFPR.setDep(&DAINF);
	UTFPR.setDep(&DAELN);
	UTFPR.setDep(&DAMAT);

	princeton.setDep(&physicsPrinceton);

	cambridge.setDep(&mathCambridge);
}
void Principal::InicializaAlunos()
{
	felipe.setName("Felipe Mossato");
	jorge.setName("Jorge Jorge");

}
void Principal::InicializaDisciplina()
{
	Comp1_2006.setName("Computacao 1 2006");
	Introd_Alg_2007.setName("Intro de Algde Programacao 2007");
	Comp2_2007.setName("Computao II");
	Metodos2_2007.setName("M�todos II");

	listDis.setDisciplina(&Comp1_2006);
	listDis.setDisciplina(&Introd_Alg_2007);
	listDis.setDisciplina(&Comp2_2007);
	listDis.setDisciplina(&Metodos2_2007);

	Comp1_2006.setDep(&DAELN);
	Introd_Alg_2007.setDep(&DAELN);
	Comp2_2007.setDep(&DAELN);
	Metodos2_2007.setDep(&DAELN);

	Metodos2_2007.setAluno(&felipe);
	Metodos2_2007.setAluno(&jorge);
}

void Principal::calcIdade()
{
	simao.calcAge(diaAt, mesAt, anoAt);
	newton.calcAge(diaAt, mesAt, anoAt);
	einstein.calcAge(diaAt, mesAt, anoAt);
}
void Principal::showDepAfil()
{
	
}
void Principal::showUniAfil()
{
	printf("\n");
	simao.showUniAfil();
	printf("\n");
	newton.showDepAfil();
	printf("\n");
	einstein.showDepAfil();
	printf("\n");
}
void Principal::listDiscDeps()
{
	printf("\n");
	DAELN.listDisciplina();
	printf("\n");
}

void Principal::listAlunosDisc()
{
	printf("\n");
	Metodos2_2007.listAlunos();
	printf("\n");
}

void Principal::Menu()
{
	int opt = 0;

	while (opt != -3)
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
			cout << "OP��O INV�LIDA. " << endl;
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
		cout << "-------- 1 - CADASTRAR UM ALUNO --------" << endl;
		cout << "-------- 2 - CADASTRAR UMA UNIVERSIDADE --------" << endl;
		cout << "-------- 3 - CADASTRAR UM DEPARTAMENTO --------" << endl;
		cout << "-------- 4 - CADASTRAR UMA DISCIPLINA  --------" << endl;
		cin >> opt;

		switch (opt)
		{
			case 1:
			{
				cadAluno();
			}
			break;
			case 2:
			{
				cadUni();
			}
			break;
			case 3:
			{
				cadDep();
			}
			break;
			case 4:
			{
				cadDisci();
			}
			case 5:
			{
				cout << "SAINDO DO SISTEMA" << endl;
			}
			break;
			default: 
			{
				cout << "OP��O INV�LIDA." << endl;
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
		cout << "-------- 2 - LISTAR AS UNIVERSIDADE --------" << endl;
		cout << "-------- 3 - LISTAR OS DEPARTAMENTO --------" << endl;
		cout << "-------- 4 - LISTAR AS DISCIPLINAS  --------" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1:
		{
		}
		break;
		case 2:
		{
		}
		break;
		case 3:
		{
		}
		break;
		case 4:
		{
		}
		case 5:
		{
			cout << "SAINDO DO SISTEMA." << endl;
		}
		break;
		default:
		{
			cout << "OP��O INV�LIDA." << endl;
			system("Pause");
		}
		}
	}
}


void Principal::cadAluno(){}
void Principal::cadDisci(){}
void Principal::cadDep(){}
void Principal::cadUni(){}