#include<iostream>

#include"caso.h"

using namespace std;

int elegirOpt(int,int);
void menuPrincipal();
void menuParte1();
void menuParte2();

int main (int argc, char *argv[]) {
	int opt;
	int opt2;
	do{
		menuPrincipal();
		opt=elegirOpt(0,2);
		switch(opt){
		case 1:
			menuParte1();
			opt2=elegirOpt(0,4);
			switch(opt2){
			case 1:
				parte_1_lineal();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			case 2:
				parte_1_potencial();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			case 3:
				parte_1_exponencial();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			case 4:
				parte_1_cuadratica();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			}
			break;
		case 2:
			menuParte2();
			opt2=elegirOpt(0,3);
			switch(opt2){
			case 1:
				caso_1_lagrange_2();
				caso_2_lagrange_2();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			case 2:
				caso_1_lagrange_3();
				caso_2_lagrange_3();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			case 3:
				caso_trazador_cubico();
				cout<<"Presione cualquier tecla para continuar...";
				getchar();
				getchar();
				break;
			}
			break;
		case 0:
			cout<<"Bye bye"<<endl;
			break;
		}
	}while(opt);
	
	return 0;
}

void menuPrincipal(){	
	system("cls");
	cout<<"\n---Menu taller2---\n1. Parte_1(Kilovatios)\n2. Parte_2\n0. Salir"<<endl;
}

void menuParte1(){
	system("cls");
	cout<<"\n---Menu---\n1. Lineal\n2. Potencia\n3. Exponencial\n4. Cuadratica\n0. Atrás"<<endl;
}
	
void menuParte2(){
	system("cls");
	cout<<"\n---Menu---\n1. Parte_A(Lagrange^2)\n2. Parte_A(Lagrange^3)\n3. Parte_B(Trazador cubico)\n0. Atrás"<<endl;
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
