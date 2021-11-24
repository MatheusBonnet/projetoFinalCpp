#include "funcoes.h"

char menu () {	
	char escolha = ' ';
	std::cout << "\n==============================";
	std::cout << "\n=======PROJETO FINAL==========";
	std::cout << "\n==============================";
	std::cout << "\n==SELECIONE UMA OPCAO ABAIXO==";
	std::cout << "\n=========DIGITE O NUMERO=======";
	std::cout << "\n==========1 - CADASTRAR ALUNO===========";
	std::cout << "\n==========2 - LEITURA===========";
	std::cout << "\n==========0 - FINALIZA========\n";
	std::cin >> escolha;
	system("cls");
	return escolha;
}

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}


bool realizaLeituraArquivo () {
	std::ifstream arquivo;
	arquivo.open("database.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	for (int i = 0; i < 100; i++) {
		std::cout << "Aluno n " << i+1 << "\n";
		std::cout << "Nome: " << alunos[i].nome << "\n";
		std::cout << "Matricula: " << alunos[i].matricula << "\n";
	}
	
	return true;
}

void entradaDeDados(Aluno aluno) {
	
	std::cout << "Digite seu nome: ";
	std::cin >> aluno.nome;
	std::cout << "Digite sua matricula: ";
	std::cin >> aluno.matricula;
	std::cout <<"Digite a nota da AEP 1: ";
	std::cin >> aluno.aep1;
	std::cout << "Digite o valor da primeira prova: ";
	std::cin >> aluno.prova1;
	std::cout <<"Digite a nota da AEP 2: ";
	std::cin >>aluno.aep2;
	std::cout <<"Digite valor da segunda prova: ";
	std::cin >> aluno.prova2;
	aluno.media = ((aluno.aep1 + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2)/2);
	if(aluno.media >= 6){
		std::cin >> aluno.media;
		aluno.status = "APROVADO";
		std::cin >> aluno.status;
	}
	else{
		std::cout << "Digite o valor da substutiva: ";
		std::cin >> aluno.sub;
		aluno.media = ((aluno.aep1 + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2 + aluno.sub)/2);
		std::cin >> aluno.media;
		if(aluno.media >= 6){
			aluno.status = "APROVADO";
			std::cin >> aluno.status;
	    }else{
	    	aluno.status = "REPROVADO";
			std::cin >> aluno.status;
		}
	}
	
	if (cadastraAluno (aluno)) {
		std::cout << "Aluno cadastrado\n";
	} else {
		std::cout << "Erro ao cadastrar aluno\n";
	}
}
