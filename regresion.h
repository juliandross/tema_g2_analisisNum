#ifndef REGRESION_H
#define REGRESION_H
/**
* @file
* @brief
* @author
* @copyrigth
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

namespace regresion{
	struct modelo_lineal{
		vector<double> x{};
		vector<double> y{};
		double b0;
		double b1;
		bool valido;
		double sy;
		double syx;
		double y_prom;
		
		modelo_lineal (vector<double> x,vector<double> y):x(x),y(y){
			construir();
		}
		
		void construir(){
			double sx=0.0d;
			double sy=0.0d;
			double sx2=0.0d;
			double sxy=0.0d;
			double x_prom;
			
			int n=x.size();
			if(n=!y.size() || n<3){
				valido=false;
				return;
			}
			n=x.size();
			
			for(int i=0;i<n;i++){
				sx=sx+x[i];
				sy=sy+y[i];
				sxy=sxy+x[i]*y[i];
				sx2=sx2+pow(x[i],2);
			}
			x_prom=sx/(double)n;
			y_prom=sy/(double)n;
			
			b1=(sxy-y_prom*sx)/(sx2-x_prom*sx);
			b0=y_prom-b1*x_prom;
			valido=true;
		}
			
			double estimar(double x_est){
				return b1*x_est+b0;
			}
				
				/**
				* @brief Calcular desviacion estandar total
				* @param st Sumatoria de los cuadrados de las restas entre los valores medidos y la restas
				* @param n cantidad de puntos
				* @param div Division de sr/n-1
				*/
				
				double desviacionEstandarTotal(){
					double st=0;
					double div;
					int n=x.size();
					for(int i=0;i<x.size();i++){
						st+=pow(y[i]-y_prom,2);
					}
					div=st/(double)(n-1);
					if(div<0){
						div*=-1;
					}
					sy=sqrt(div);
					return st;
				}
					
					/**
					* @brief Calcular desviacion estandar de aproximacion
					* @param sr Sumatoria de los cuadrados de las restas entre el valor verdadero de y y su estimacion
					* @param n cantidad de puntos
					* @param div Division de sr/n-2
					*/
					
					double desviacionEstandarAproximacion (){
						double sr=0;
						double div;
						int n=x.size();
						for(int i=0;i<x.size();i++){
							sr+=pow(y[i]-estimar(x[i]),2);
						}
						div=sr/(double)(n-2);
						if(div<0){
							div*=-1;
						}
						syx=sqrt(div);
						return sr;
					}
						
						/**
						* @brief Verificar si la aproximacion es aceptable
						* @param sr Sumatoria de los cuadrados de las restas entre el valor verdadero de y y su estimacion
						* @param st Sumatoria de los cuadrados de las restas entre los valores medidos y la restas
						*/
						void aproximacionAceptable(){
							double st=desviacionEstandarTotal();
							double sr=desviacionEstandarAproximacion();
							if(syx<sy){
								cout<<"Aproximacion aceptable"<<endl;
							}else{
								cout<<"Aproximacion inaaceptable"<<endl;
							}
							double r2=(st-sr)/st;
							cout<<"------------------------------"<<endl;
							cout<<"------------------------------"<<endl;
							cout<<"       Resultados "<<endl;
							cout<<"------------------------------"<<endl;
							cout<<"------------------------------"<<endl;
							cout<<"b0: "<<b0<<endl;
							cout<<"b1: "<<b1<<endl;
							cout<<"------------------------------"<<endl;
							cout<<"Coeficiente de determinacion (r2): "<<r2<<endl;
							cout<<"Desviacion estandar (sy): "<<sy<<endl;
							cout<<"Error estandar de aproximacion: "<<syx<<endl;
							cout<<"------------------------------"<<endl;
							cout<<"Los resultados indican que el modelo explica el "<<r2*100.0d<<"% de la incertidumbre original"<<endl;
						}
							
	};
	
	class lineal_simple{
		
	private:
		modelo_lineal modelo;
	public:
		lineal_simple(vector <double>x,vector<double> y):modelo(x,y){
			
		}
		
		double estimar(double x_est){
			if(!modelo.valido){
				return NAN;
			}
			return modelo.estimar(x_est);
		}
			
			void aceptable(){
				modelo.aproximacionAceptable();
			}
				
	};
	
	
	
	
	
	struct modelo_potencia{
		double c;
		double a;
		double valido;
		struct modelo_lineal lineal;
		
		
		modelo_potencia(vector<double> x, vector <double>y):lineal(logD12(x),logD12(y)){
			valido = lineal.valido;
			c = pow(10.0f,lineal.b0);
			a = lineal.b1;
			
		}
		
		void aceptable(){
			lineal.aproximacionAceptable();
		}
			
			double estimar (double x_est){
				return c*pow(x_est,a);
			}
				
				vector<double> logD12(vector<double> v){
					for (auto & x:v){
						x= log10(x);
					}
					return v;
				}
					
	};
	
	class lineal_potencia{
	private: 
		modelo_potencia modelo;
	public:
		lineal_potencia(vector <double> x,vector <double> y):modelo(x,y){
			
		}
		double estimar(double x){
			if(!modelo.valido){
				return NAN;
			}
			return modelo.estimar(x);
		}
			
			void aceptable(){
				modelo.aceptable();
			}	
				
				modelo_potencia obtenerModelo(){
					return modelo;
				}
					
	};
	
	struct modelo_exponencial{
		double c;
		double a;
		double valido;
		struct modelo_lineal lineal;
		
		modelo_exponencial(vector<double> x, vector <double>y):lineal(x,ln(y)){
			valido=lineal.valido;
			c=exp(lineal.b0);
			a=lineal.b1;
		}
		
		void aceptable(){
			lineal.aproximacionAceptable();
		}
			
			double estimar (double x_est){
				return c*exp(a*x_est);
			}
				
				
				vector<double>  ln(vector<double> v){
					for (auto & x:v){
						x= log(x);
					}
					return v;
				}
	};
	
	class lineal_exponencial{
	private:
		struct modelo_exponencial modelo;
	public:
		lineal_exponencial(vector <double> x,vector <double> y):modelo(x,y){
			
		}
		double estimar(double x){
			if(!modelo.valido){
				return NAN;
			}
			return modelo.estimar(x);
		}
			
			void aceptable(){
				modelo.aceptable();
			}	
				
				modelo_exponencial obtenerModelo(){
					return modelo;
				}
					
	};
	
};
#endif
