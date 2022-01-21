#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class filme{
	private:
		string titulo;
		string estilo;
		int ano;
		int duracao;
		int codigo;
	public:
		string getTitulo();
		string getEstilo();
		int    getAno();
		int    getDuracao();
		int    getCodigo();	
		
		void ler();
		double aluguel();
};
string filme::getTitulo()                 {    return titulo;     }
string filme::getEstilo()                 {    return estilo;     }
int    filme::getAno()                	  {    return ano;     	  }
int    filme::getDuracao()                {    return duracao;    }
int    filme::getCodigo()                 {    return codigo;     }

void filme::ler(){
	cin >> codigo;
	cin.ignore();
	getline(cin,titulo);
	getline(cin,estilo);
	cin >> ano;
	cin >> duracao;
}

double filme::aluguel(){
	
	if(getAno() < 2020){
		return 3;
	}
	else{
		return 5;
	}
}

class locadora{
	private:
		filme vet[100];
        	int qtd;
        	int obterIndice(int cod); 
        public:	
		locadora();
		void inserir(filme f);
                void remover(int cod);
        	void alterar(int cod, filme f);
        	filme obterFilme(int pos);
		int obterQtd();
		void listar();
		void listarAluguel(int cod);
		void listar(string titulo, string estilo);
		
		bool existe(int cod);
		
		void esperaOk();
};

locadora::locadora()	{	qtd=0;	}

int locadora::obterIndice(int cod){
   bool achou;
   int i;
   i = 0;
   achou = false;
   while (!achou && i<qtd)
     if (vet[i].getCodigo() == cod)
        achou = true;
     else
        i++;
   return achou?i:-1; 
}

void locadora::inserir(filme f){
   vet[qtd] = f;
   qtd++;     
}

bool locadora::existe(int cod){
  return obterIndice(cod)!=-1;
}

void locadora::remover(int cod){
   int pos=obterIndice(cod);
   if ( pos!=-1 )
   {
        vet[pos] = vet[qtd-1];
        qtd--;    
   } 
}

void locadora::alterar(int cod, filme f){
   int pos=obterIndice(cod);
   if ( pos!=-1 )
        vet[pos] = f;
}

filme locadora::obterFilme(int pos){
    return vet[pos];
}

int locadora::obterQtd(){
    return qtd;
}

void locadora::listar(){
	cout << fixed << setprecision(2);
	cout << setw(3) <<  right << setfill(' ') << "COD" << "!" <<
	left << 
	setw(30) << "Titulo" << "!" <<
	setw(20) << "Estilo" << "!" <<
	setw(5) << "R$     "<< 		
	setw(10) << "aluguel" << endl;	
	
	for(int i=0; i<qtd; i++){
        filme f = vet[i];
        	cout << setw(3) << right << setfill('0') << f.getCodigo() << "!" <<
        	left <<
                setw(30) << setfill(' ') << f.getTitulo() << "!" <<
                setw(20) << f.getEstilo() << "!" <<
				setw(5) << "R$     " << 
				right <<
				setw(7) << f.aluguel() << endl;    
    }	
}

void locadora::listarAluguel(int cod){
	cout << fixed << setprecision(2);
	
        for(int i=0; i<qtd; i++){
        	filme f = vet[i];
        		if(f.getCodigo() == cod)
        		cout << "aluguel = R$   " << f.aluguel() << endl; 
    	}
}

void locadora::listar(string titulo, string estilo){
	cout << fixed << setprecision(2);
	cout << setw(3) <<  right << setfill(' ') << "COD" << "!" <<
	left << 
	setw(30) << "Titulo" << "!" <<
	setw(20) << "Estilo" << "!" <<
	setw(5) << "R$     " << 		
	setw(10) << "aluguel" << endl;	
	
	for(int i=0; i<qtd; i++){
        filme f = vet[i];
        if (f.getTitulo() == titulo || f.getEstilo() == estilo)
        	cout << setw(3) << right << setfill('0') << f.getCodigo() << "!" <<
        	left <<
                setw(30) << setfill(' ') << f.getTitulo() << "!" <<
                setw(20) << f.getEstilo() << "!" <<
				setw(5) << "R$     " << 
				right <<
				setw(7) << f.aluguel() << endl;    
    }
}

void esperaOk(){
   string linha;
   
   do {
      getline(cin, linha);
   } while (linha != "ok" );
   
}

int menu(){
   int opc;
   do{  
   	 cout << "1 - inserir um filme" << endl;
   	 cout << "2 - remover dado o codigo" << endl;
   	 cout << "3 - alterar dado o codigo" << endl;
   	 cout << "4 - pesquisar valor do aluguel dado o codigo" << endl;
   	 cout << "5 - listar todos" << endl;
   	 cout << "6 - listar dado parte titulo ou estilo" << endl;
   	 cout << "7 - sair" << endl;
   	 cout << "Entre com a sua escolha:" << endl;
     cin >> opc;  
   } while( opc<1 || opc>7);
   return opc;
}

void sucesso(string msg){
    cout << msg << endl;
    system("pause"); 
}

int main(){
	bool acabou;
	acabou = false;
	
	filme f;
	locadora l;
	
	int codigo;
	string texto;
	
	while (!acabou){
      switch( menu() ){
      	
      		case 1:
      		f.ler();
      		l.inserir(f);
      		break;
      		case 2:
      		cin >> codigo;
      		if (l.existe(codigo)){
      			l.remover(codigo);
      			sucesso("Removido com sucesso!");
      		}else{
      			cout <<  "filme nao encontrado!" << endl;
			  }
		  	break;	
		case 3:
      		cin >> codigo;
      		if(l.existe(codigo)){
      			f.ler();
      			l.alterar(codigo, f);
      			sucesso("Alterado com sucesso!");
			  }else{
      			cout <<  "filme nao encontrado!" << endl;
			  }
		  	break;  
		case 4:
      		cin >> codigo;
      		if(l.existe(codigo)){
      			l.listarAluguel(codigo);
			}else{
      			cout <<  "filme nao encontrado!" << endl;
			  }
		  	break;
		case 5:
      		l.listar();
      		esperaOk();
		  	break;
		case 6:
      		cin.ignore();
                getline(cin,texto);  
                l.listar(texto, texto);
                esperaOk();
		  	break;	  	  	  	
      		case 7:
		  	acabou = true;
			break;	
      }
   }
   return 0;     	
}

