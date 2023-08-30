#include "../Tec-Prog-Sis-Academico-master/headers/principal.h"

Principal::Principal()
{
	//Estrutura para utilizar o time.h: 
	struct tm* local;
	time_t segundos;
	time(&segundos);
	local = localtime(&segundos);

	diaAt = local->tm_mday;
	mesAt = local->tm_mon + 1;
	anoAt = local->tm_year + 1900;

	Inicializa();

}



Principal::~Principal()
{
}

void Principal::Executar()
{
	calcIdade();
	showDepAfil();
	felipe.showRA();
	jorge.showRA();
	listDiscDeps();
	listAlunosDisc();

}


void Principal::Inicializa()
{
	InicializaAlunos();	
	InicializaProfessores();
	InicializaUniversidades();
	InicializaDepartamentos();
	InicializaDisciplina();

}


void Principal::InicializaUniversidades()
{
	//Inicializa as universidades:
	UTFPR.Inicializa("UTFPR");
	cambridge.Inicializa("Cambridge");
	princeton.Inicializa("Princeton");

	//Seta os departamentos as Universidades:
	UTFPR.setDep(&DAINF, 0);
	UTFPR.setDep(&DAELN, 1);
	UTFPR.setDep(&DAMAT, 2);
	cambridge.setDep(&mathCambridge, 0);
	princeton.setDep(&physicsPrinceton, 0);

}
void Principal::InicializaProfessores()
{
	simao.Inicializa(3, 10, 1976, "Jean Simão");
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
	DAINF.setUni(&UTFPR);
	DAELN.setUni(&UTFPR);
	DAMAT.setUni(&UTFPR);
	physicsPrinceton.setUni(&princeton);
	mathCambridge.setUni(&cambridge);
}
void Principal::InicializaAlunos()
{
	felipe.Inicializa(9, 8, 2002, "Felipe Mossato");
	jorge.Inicializa(10, 4, 2000, "Jorge Jorge");

	felipe.setUniAfil(&UTFPR);
	jorge.setUniAfil(&UTFPR);

	felipe.setDepAfil(&DAINF);
	jorge.setDepAfil(&DAMAT);

	felipe.setRA(2557959);
	jorge.setRA(2541343);
}
void Principal::InicializaDisciplina()
{
	Comp1_2006.setName("Computacao 1 2006");
	Introd_Alg_2007.setName("Intro de Algde Programacao 2007");
	Comp2_2007.setName("Computao II");
	Metodos2_2007.setName("Métodos II");


	DAELN.setDisciplina(&Comp1_2006);
	DAELN.setDisciplina(&Introd_Alg_2007);
	DAELN.setDisciplina(&Comp2_2007);
	DAELN.setDisciplina(&Metodos2_2007);

	Metodos2_2007.setAluno(&felipe);
	Metodos2_2007.setAluno(&jorge);
}

void Principal::calcIdade()
{
	felipe.calcAge(diaAt, mesAt, anoAt);
	jorge.calcAge(diaAt, mesAt, anoAt);
	simao.calcAge(diaAt, mesAt, anoAt);
	newton.calcAge(diaAt, mesAt, anoAt);
	einstein.calcAge(diaAt, mesAt, anoAt);
}
void Principal::showDepAfil()
{
	printf("\n");
	felipe.showDepAfil();
	printf("\n");
	jorge.showDepAfil();
	printf("\n");
	simao.showDepAfil();
	printf("\n");
	newton.showDepAfil();
	printf("\n");
	einstein.showDepAfil();
	printf("\n");
}
void Principal::showUniAfil()
{
	printf("\n");
	felipe.showUniAfil();
	printf("\n");
	jorge.showDepAfil();
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
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
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
			cout << "OPÇÃO INVÁLIDA. " << endl;
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
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
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
				cout << "OPÇÃO INVÁLIDA." << endl;
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
		cout << "-------- SELECIONE UMA DAS OPÇÕES ABAIXO --------" << endl;
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
			cout << "OPÇÃO INVÁLIDA." << endl;
			system("Pause");
		}
		}
	}
}


void Principal::cadAluno(){}
void Principal::cadDisci(){}
void Principal::cadDep(){}
void Principal::cadUni(){}