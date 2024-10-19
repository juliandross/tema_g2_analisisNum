#include<iostream>
using namespace std;

int elegirOpt(int,int);
void menuPrincipal();
void menuParte1();
void menuParte1Int();

int main (int argc, char *argv[]) {
	menuPrincipal();
	switch(elegirOpt(0,2)){
		case 1:
			menuParte1();
		case 2:
			menuParte1Int();
			switch(elegirOpt(0,2)){
				case 1:
					
				case 2:
					
				case 0:
					break;
			}
		case 0:
			cout<<"Bye bye"<<endl;
			break;
	}
	return 0;
}

void menuPrincipal(){	
	system("cls");
	cout<<"\n---Menu---\n1. Parte_1\n2. Parte_2\n0. Salir"<<endl;
}

void menuParte1(){
	system("cls");
	cout<<"\n---Menu---\n1. Lineal\n2. Potencia\n3. Exponencial\n4. Cuadratica\n0. Atrás"<<endl;
}
	
void menuParte1Int(){
	system("cls");
	cout<<"\n---Menu---\n1. Parte_A\n2. Parte_B\n0. Atrás"<<endl;
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
