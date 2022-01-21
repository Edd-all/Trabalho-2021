#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class data{
	private:
		char barra ; //  barra = "/"
		int dia, mes, ano; 
	public:
		void ler();	
		void mostrar();
		void idade();
		
		int getDia();
		int getMes();
		int getAno();
};

int data::getDia()	{  return dia;	}
int data::getMes()	{  return mes;	}
int data::getAno()	{  return ano;	}

void data::ler(){
	cin >> dia >> barra >> mes >> barra >> ano;
}
void data::mostrar(){
	cout << "Data Nascimento: ";
	if(ano < 25){
		cout << setw(2) << right << setfill('0') << dia << "/" << setw(2) << right << setfill('0') << mes << "/" << setw(2) << "20" << ano << endl;
	}else if(ano > 25 && ano < 99){
		cout << setw(2) << right << setfill('0') << dia << "/" << setw(2) << right << setfill('0') << mes << "/" << setw(2) << "19" << ano << endl;
	}else{
		cout << setw(2) << right << setfill('0') << dia << "/" << setw(2) << right << setfill('0') << mes << "/" << setw(4) << ano << endl;
	}
}
void data::idade(){
	int id;		//id = 2021 - ano;		idade em 31/12/2021
	if(ano<25){
		id = 21 - ano;
	}else if(ano > 25 && ano < 99){
		id = 2021 - (ano + 1900);
	}else{
		id = 2021 - ano;
	}
	cout << "Idade          : ";
	cout << id << endl;
}


class pessoa{
	private:
		data vet[100];
		string nome;
		double altura;
	public:
		void ler();
		void mostrar();
};

void pessoa::ler(){
	data d;
	
	cin.ignore();
	getline(cin,nome);
	d.ler();
	cin >> altura;
}

void pessoa::mostrar(){
	data d;
	
	cout << "Nome           : ";
	cout << nome << endl;
	d.mostrar();
	cout << "Altura         : ";		
	cout << altura << endl;
	d.idade();	
	cout << endl;	
}

int main(){
	pessoa p;
	int qtd;
	
	cin >> qtd;
	
	for(int i=0;i<qtd;i++){
		p.ler();
		p.mostrar();
	}
}
