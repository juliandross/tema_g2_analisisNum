#include <iostream>
#include <vector>

#include "caso.h"
#include "expresion.h"
#include "lagrange.h"
#include "spline3.h"
#include "regresion.h"
#include "regresion_cuadratica.h"

using interpolacion::lagrange;
using interpolacion::spline3;
using regresion::lineal_simple;
using regresion::lineal_potencia;
using regresion::lineal_exponencial;
using regresion::modelo_lineal;
using regresion::modelo_potencia;
using regresion::modelo_exponencial;
using regresion::cuadratica;
using regresion::modelo_cuadratico;
//Parte 1

void parte_1_lineal(){
	cout<<"Parte 1 funcion lineal"<<endl;
	
	vector<double> x{120.0d,125.0d,135.0d,150.0d,160.0d,170.0d,185.0d,205.0d,225.0d,270.0d};
	vector<double> y{1175.0d,1190.0d,1250.0d,1490.0d,1565.0d,1720.0d,1805.0d,1860.0d,1950.0d,1945.0d};
	
	lineal_simple ls (x,y);
	
	double x_est=210.0d;
	double y_est=ls.estimar(x_est);
	
	
	ls.aceptable();
	cout<<x_est<<" Estimacion de 210: "<<y_est<<endl;
}	
void parte_1_potencial(){
	cout<<"Parte 1 funcion potencial"<<endl;
		
	vector<double> x{120.0d,125.0d,135.0d,150.0d,160.0d,170.0d,185.0d,205.0d,225.0d,270.0d};
	vector<double> y{1175.0d,1190.0d,1250.0d,1490.0d,1565.0d,1720.0d,1805.0d,1860.0d,1950.0d,1945.0d};
		
	double xi = 210.0d;
	double y_estimado;
	lineal_potencia r(x,y); 
		
		
	y_estimado = r.estimar(xi);
	modelo_potencia modelo = r.obtenerModelo();
		
	modelo.aceptable();
	cout<<"El valor estimado para x="<<xi
		<<" es y="<<y_estimado<<endl;
}
		
void parte_1_exponencial(){
	cout<<"Parte 1 funcion exponencial"<<endl;
	vector<double> x{120.0d,125.0d,135.0d,150.0d,160.0d,170.0d,185.0d,205.0d,225.0d,270.0d};
	vector<double> y{1175.0d,1190.0d,1250.0d,1490.0d,1565.0d,1720.0d,1805.0d,1860.0d,1950.0d,1945.0d};
			
	double xi = 210.0d;
	double y_estimado;
	lineal_exponencial r(x,y); 
			
			
	y_estimado = r.estimar(xi);
	modelo_exponencial modelo = r.obtenerModelo();
			
	modelo.aceptable();
	cout<<"El valor estimado para x="<<xi
		<<" es y="<<y_estimado<<endl;
}
			
void parte_1_cuadratica(){
	cout<<"Parte 1 cuadratica"<<endl;
	vector<double> x{120.0d,125.0d,135.0d,150.0d,160.0d,170.0d,185.0d,205.0d,225.0d,270.0d};
	vector<double> y{1175.0d,1190.0d,1250.0d,1490.0d,1565.0d,1720.0d,1805.0d,1860.0d,1950.0d,1945.0d};
				
	cuadratica cuadrado(x,y);
	double y_est=cuadrado.estimar(210.0d);
				
	cout<<"Estimado de 210: "<<y_est<<endl;
				
	modelo_cuadratico m=cuadrado.obtener_modelo();
	cout<<m<<endl;
}



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
	cout << "Caso trazador cubico" << endl;
	vector<double> x = {1.25, 1.50, 1.75, 2.00};
	vector<double> y = {0.9560871, 0.8545027, 0.6762921, 0.4107813};
	spline3 sp(x,y);
	double x_int = 1.625f;
	double y_int;
	
	if(!sp.es_valido()){
		cout << "No valido para interpolar" << endl;
		return;
	}else{
		y_int = sp.interpolar(x_int);
		cout<<"\nPara x = "<<x_int<<" la interpolacion es y="<<y_int<<endl;
		sp.imprimir_error(0.775847881,y_int);
	}
}
