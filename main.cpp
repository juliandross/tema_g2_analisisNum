#include<iostream>
using namespace std;

int elegirOpt(int,int);
void menuPrincipal();
void menuParte1();
void menuParte1Int();

int main (int argc, char *argv[]) {
	menuPrincipal();
	int opt=elegirOpt(0,2);
	switch(opt){
		case 1:
			menuParte1();
			break;
		case 2:
			menuParte1Int();
			switch(elegirOpt(0,2)){
				case 1:
					break;
				case 2:
					break;
			}
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
	cout<<"\n---Menu---\n1. Lineal\n2. Potencia\n3. Exponencial\n4. Cuadratica\n0. Atr�s"<<endl;
}
	
void menuParte1Int(){
	system("cls");
	cout<<"\n---Menu---\n1. Parte_A\n2. Parte_B\n0. Atr�s"<<endl;
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