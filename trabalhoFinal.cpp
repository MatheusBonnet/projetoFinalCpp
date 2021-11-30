#include "funcoes.cpp"

int main () {
	Aluno aluno[100];
	
	char opcao = ' ';
	do {
	   opcao = menu();	
	   switch (opcao) {
	   		case '1':
	   			for(int i = 0; i <= 50; i++){
	   					entradaDeDados(aluno[i]);
				    std::cout << "Deseja continuar? Digite 1 para sim e 2 para nao!\n";
				    int resposta;
					std::cin >> resposta;
					if(resposta == '1'){
						100 + 1;
					}else if(resposta == '2'){
						break;
					}else{
						std::cout << "Digite uma opcao valida!";
					}	
				} 
	   		break;
	   		case '2':
	   			realizaLeituraArquivo();
	   		break;
			   case '3':
	   			
	   		break;
	   		case '0':
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		// demais funcoes deverão ser chamadas aqui
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != '0');	
}