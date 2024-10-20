#include<iostream>

#include"caso.h"

using namespace std;

int elegirOpt(int,int);
void menuPrincipal();
void menuParte1();
void menuParte1Int();

int main (int argc, char *argv[]) {
	int opt;
	do{
		//menuPrincipal();
		opt=elegirOpt(0,2);
		switch(opt){
		case 1:
			system("cls");
			menuParte1();
			cout<<"Presione cualquier tecla para continuar...";
			getchar();
		case 2:
			menuParte1Int();
			switch(elegirOpt(0,2)){
			case 1:
				system("cls");
				caso_1_lagrange_2();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
			case 2:
				system("cls");
				
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
			}
		case 0:
			cout<<"Bye bye"<<endl;
			break;
		}
	}while(opt);
	
	return 0;
}

void menuPrincipal(){	
	system("cls");
	cout<<"\n---Menu---\n1. Parte_1(Kilovatios)\n2. Parte_2\n0. Salir"<<endl;
}

void menuParte1(){
	system("cls");
	cout<<"\n---Menu---\n1. Lineal\n2. Potencia\n3. Exponencial\n4. Cuadratica\n0. Atrás"<<endl;
}
	
void menuParte1Int(){
	system("cls");
	cout<<"\n---Menu---\n1. Parte_A(Lagrange)\n2. Parte_B(Trazador cubico)\n0. Atrás"<<endl;
}
	
int elegirOpt(int min, int max){
	int opt=-1;
	bool flag=false;
	do{
		scanf("%d",&opt);
		if(opt>max || opt<min){
			cout<<"Valor invalido!! ["<<min<<","<<max<<"]"<<endl;
			flag = true;
		}else{
			flag = false;
		}
	}while(flag);
	return opt;
}
