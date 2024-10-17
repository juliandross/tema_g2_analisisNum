#ifndef SPLINE3_H
#define SPLINE3_H

#include <cmath>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;


namespace interpolacion{
	class spline3{
		
	public:
		/**
		*@brief crea una nueva instancia de interpolador por splines cubicos
		*/
		spline3(vector<double>x, vector<double>y):x(x), y(y){
			construir();
		}	
		bool es_valido(){
			return valido;
		}
		/**
		*@brief Evalua el spline del intervalo en el que se encuentra x_in
		*@param x_int valor a interpolar
		*@return valor de spline en x_int
		*/
		double interpolar(double x_int){
			int i;
			for(i = 0; (int)i < x.size() && x_int > x[i]; i++);
			cout<<"intervalo en el que se encuentra el dato"<< x_int <<" : "<<
				i<<endl;
			//Usando los nodos intermedios
			if((int)i == 0 || (int)i == x.size()){
				return NAN;
			}
			return evaluar(i,x_int);
			
		}	
	private:
		vector<double>x;//Var independiente
		vector<double>y;//Var dependiente
		vector<double>f2;//segundas derivadas
		bool valido = false;//verifica si el interpolador es valido
		void construir(){
			if(x.size()!=y.size() || x.size()<3){
				valido = false;
				printf("interpolacion invalida");
				return;
			}
			int n = (int)x.size();
			//1. Crear el sistema de ecuaciones
			vector<vector<double>> m_f2(n-2);
			for(auto & fila: m_f2){
				fila.resize(n + 1);
			}
			int i = 0;
			int j = 0;
			int intervalo;
			for(i = 0; i < n; i++){
				intervalo = i + 1;
				cout << "Construir la ecuacion para el intervalo"<<intervalo<<endl;
				for( j = 0; j < n; j++){
					m_f2[i][j] = 0;
					double t1 = 0.0f;
					double t2 = 0.0f;
					double t3 = 0.0f;
					
					
					if(j == i - 1 && j < n -1){
						//Primer termino de la ecuacion 18.37(intervalo)
						cout << "primer termino" << "i = "<< i <<" j = "<< j << endl;
						t1 = x[intervalo]-x[intervalo - 1];
					}else if(j == i){
						//Segundo termino de la ecuacion 18.37(inteevalo)
						cout << "segundo termino"  << "i = "<< i <<" j = "<< j << endl;
						//t2
						
					}else if(j == i + 1){
						//Tercer termino de la ecuacion 18.37(inteevalo)
						cout << "tercer termino"  << "i = "<< i <<" j = "<< j << endl;
						//t3
					}
					//Calcular y guardar el termino independiente 
				}
			}


			
			//2. Resolver el sistema de ecuaciones para obtener f2
			//vector<double> sol = gauss(m_f2)
			//f2 = [0, ...sol,.. 0]
			//3. 
			valido = true;	
		}
			/**
			*@brief Evaluar el spline del inervalo i para x_int 
			*@param i intervalo
			*/
		double evaluar(int i, double x_int){
			if(!valido){
				return NAN;
			}
			//TODO evaluar la ecuacion 18.36 en el intervalo i
			return NAN;
		}

	};
};
#endif
