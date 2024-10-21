#include <iostream>
#include <vector>

#include "caso.h"
#include "expresion.h"
#include "lagrange.h"

using interpolacion::lagrange;

//Parte 1







//Parte 2 A.
void caso_1_lagrange_2(){
	cout<<"Caso 1 interpolacion de lagrange con grado 2"<<endl;
	vector<double> x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00};
	vector<double> y = {0.9057510, 0.9591622, 0.9933021, 0.9969654, 0.9560871, 0.8545027, 0.6762921, 0.4107813};
	
	lagrange l(x,y);
	
	double int_x = 0.55f;
	double y_est;
	
	if(!l.es_valido()){
		cout<<"El polinomio no es valido."<<endl;
	}
	else{
		y_est = l.interpolar(int_x,2);
		cout<<"\nPara x = "<<int_x <<" la interpolacion es  y="<<y_est<<endl; 
		l.imprimir_error_relativo(0.967848271, y_est);	
		l.imprimir_error_porcentual(0.967848271, y_est);	
	}
}
void caso_2_lagrange_2(){
	cout<<"Caso 2 interpolacion de lagrange con grado 2"<<endl;
	vector<double> x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00};
	vector<double> y = {0.9057510, 0.9591622, 0.9933021, 0.9969654, 0.9560871, 0.8545027, 0.6762921, 0.4107813};
	
	lagrange l(x,y);
	
	double int_x = 1.55f;
	double y_est;
	
	if(!l.es_valido()){
		cout<<"El polinomio no es valido."<<endl;
	}
	else{
		y_est = l.interpolar(int_x,2);
		cout<<"\nPara x = "<<int_x <<" la interpolacion es  y="<<y_est<<endl; 
		l.imprimir_error_relativo(0.825450897, y_est);	
		l.imprimir_error_porcentual(0.825450897, y_est);	
	}
}
	
void caso_1_lagrange_3(){
	cout<<"Caso 1 interpolacion de lagrange con grado 3"<<endl;
	vector<double> x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00};
	vector<double> y = {0.9057510, 0.9591622, 0.9933021, 0.9969654, 0.9560871, 0.8545027, 0.6762921, 0.4107813};
	
	lagrange l(x,y);
	
	double int_x = 0.55f;
	double y_est;
	
	if(!l.es_valido()){
		cout<<"El polinomio no es valido."<<endl;
	}
	else{
		y_est = l.interpolar(int_x,3);
		cout<<"\nPara x = "<<int_x <<" la interpolacion es  y="<<y_est<<endl; 
		l.imprimir_error_relativo(0.967848271, y_est);	
		l.imprimir_error_porcentual(0.967848271, y_est);	
	}
}
	
	
void caso_2_lagrange_3(){
	cout<<"Caso 2 interpolacion de lagrange con grado 3"<<endl;
	vector<double> x = {0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.00};
	vector<double> y = {0.9057510, 0.9591622, 0.9933021, 0.9969654, 0.9560871, 0.8545027, 0.6762921, 0.4107813};
	
	lagrange l(x,y);
	
	double int_x = 1.55f;
	double y_est;
	
	if(!l.es_valido()){
		cout<<"El polinomio no es valido."<<endl;
	}
	else{
		y_est = l.interpolar(int_x,3);
		cout<<"\nPara x = "<<int_x <<" la interpolacion es  y="<<y_est<<endl; 
		l.imprimir_error_relativo(0.825450897, y_est);	
		l.imprimir_error_porcentual(0.825450897, y_est);	
	}
}

//Parte 2 B.
void caso_trazador_cubico(){
	
}
