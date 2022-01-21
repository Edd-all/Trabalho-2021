#include<iostream>//cin e cout 
#include<string>  //string
#include<cctype>  //tolower
#include<sstream> //stringstream
#include <cmath>  //M_PI

using namespace std;

class jogador{
	public:
		virtual void ler()       		{           }
     	virtual int aposentadoria()     { return 0; }
     	virtual string getNome() 		{ return "";}	
};


class defensor : public jogador{
	private:
		string nome;
		int idade;
		string nacionalidade;
		double altura;
		double peso;
	public:	
	  void ler();
      int aposentadoria();
      string getNome();	
};
void defensor::ler(){
	getline(cin,nome);
	cin >> idade;
	cin.ignore();
	getline(cin,nacionalidade);
	cin >> altura;
	cin >> peso;
}
int defensor::aposentadoria(){
	return 40 - idade;
}
string defensor::getNome(){
	stringstream resposta;
   	resposta << "nome : "<< nome << endl;
   	resposta << "posicao : Defesa" << endl;
   	resposta << "idade : " << idade << " anos" << endl;
   	resposta << "nacionalidade : " << nacionalidade << endl;
   	resposta << "altura : "<< altura << " m" << endl;
   	resposta << "peso : "<< peso  << " kg" << endl;
   	return resposta.str();
} 


class meiocampo : public jogador{
	private:
		string nome;
		int idade;
		string nacionalidade;
		double altura;
		double peso;
	public:	
	  void ler();
      int aposentadoria();
      string getNome();	
};
void meiocampo::ler(){
	getline(cin,nome);
	cin >> idade;
	cin.ignore();
	getline(cin,nacionalidade);
	cin >> altura;
	cin >> peso;
}
int meiocampo::aposentadoria(){
	return 38 - idade;
}
string meiocampo::getNome(){
	stringstream resposta;
   	resposta << "nome : "<< nome << endl;
   	resposta << "posicao : Meio Campo" << endl;
   	resposta << "idade : " << idade << " anos" << endl;
   	resposta << "nacionalidade : " << nacionalidade << endl;
   	resposta << "altura : "<< altura << " m" << endl;
   	resposta << "peso : "<< peso  << " kg" << endl;
   	return resposta.str();
} 


class atacante : public jogador{
	private:
		string nome;
		int idade;
		string nacionalidade;
		double altura;
		double peso;
	public:	
	  void ler();
      int aposentadoria();
      string getNome();	
};
void atacante::ler(){
	getline(cin,nome);
	cin >> idade;
	cin.ignore();
	getline(cin,nacionalidade);
	cin >> altura;
	cin >> peso;
}
int atacante::aposentadoria(){
	return 35 - idade;
}
string atacante::getNome(){
	stringstream resposta;
   	resposta << "nome : "<< nome << endl;
   	resposta << "posicao : Atacante" << endl;
   	resposta << "idade : " << idade << " anos" << endl;
   	resposta << "nacionalidade : " << nacionalidade << endl;
   	resposta << "altura : "<< altura << " m" << endl;
   	resposta << "peso : "<< peso << " kg" << endl;
   	return resposta.str();
} 



class jogadores{
	private:
		jogador* vet[100];
		int qtd;
		jogador* criarJogador();
	public:
		jogadores();
		~jogadores();
		void ler();
		void listar();	
};

jogadores::jogadores(){
    qtd = 0;
}

jogadores::~jogadores(){
    for(int i=0;i<qtd;i++)
	delete vet[i];
}

jogador* jogadores::criarJogador(){
      string posicao;
      
      cin.ignore();
      getline(cin,posicao);		
        
      if(posicao == "meio campo"){
      	return new meiocampo();
	  }
	  else if(posicao == "defesa"){
	  	return new defensor();
	  }
	  else if(posicao == "ataque"){
	  	return new atacante();
	  }
	  else{
	  	return NULL;
	  }
}

void jogadores::ler(){
	
   //cout << "entre com a quantidade de Jogadores:";
   cin >> qtd;
   for(int i=0; i<qtd; i++)
   {
   	//cout << "Digite os dados do jogador " << i+1 << endl;
      vet[i] = criarJogador();
      vet[i]-> ler();        
   }  
}

void jogadores::listar(){
   for(int i=0; i<qtd; i++)
   	cout << vet[i]->getNome() << "tempo util : " << vet[i]->aposentadoria() << " anos" << endl;
   	//cout << endl;
}


int main(){
	jogadores j;
	
	j.ler();
	j.listar();
	return 0;
}
