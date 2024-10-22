#ifndef REGRESION_CUADRATICA_H
#define REGRESION_CUADRATICA_H
#include <vector>
#include "gausiano.h"

using std::vector;

namespace regresion {
	struct modelo_cuadratico{
		vector<double> x; // var independiente
		vector<double> y; // var dependiente
		vector<double> a;
		double st; // sumatoria de la diferencia cuadratica de y con y_prom
		double sr; // sumatoria de la diferencia cuadratica de y con y estimado
		double sy; // desviacion estandar
		double syx; // error estandar de aproximacion
		double r2; // coeficiente de determinacion
		bool valido = false;
		
		modelo_cuadratico(vector <double> x, vector<double> y): x(x), y(y){
			construir();
		}
		
		
		void construir(){
			// Crear la matriz de coeficientes
			size_t n = x.size();
			
			if(n <= 3){
				//Datos insuficientes
				return;
			}
			
			if(n != y.size()){
				// X e Y diferente tamaño
				return;
			}
			//  Invocar gauss para obtener los coeficientes
			
			double sum_x = 0.0f, sum_x2 = 0.0f, sum_x3 = 0.0f, sum_x4 = 0.0f,
						   sum_xy = 0.0f, sum_x2y = 0.0f,
						   sum_y = 0.0f;
			
			for(size_t i = 0; i < n; i++){
				sum_x += x[i];
				sum_x2 += pow(x[i],2);
				sum_x3 += pow(x[i],3);
				sum_x4 += pow(x[i],4);
				
				sum_xy += x[i]*y[i];
				sum_x2y += pow(x[i],2)*y[i];
				
				sum_y += y[i];
			};
			
			vector<vector<double>> m_gauss = {
				{(double)n, sum_x, sum_x2, sum_y},
			{sum_x, sum_x2, sum_x3,sum_xy},
				{sum_x2, sum_x3, sum_x4, sum_x2y}
			};
			
			a = gauss(m_gauss);
			
			valido = (!std::isnan(a[0]) && !std::isnan(a[1]) && !std::isnan(a[2]));
			
			if(!valido){
				return;
			}
			
			// calcular los estadisticos
			double y_prom = sum_y / (double)n;
			
			st = 0.0f;
			sr = 0.0f;
			
			for(size_t i = 0; i < n; i++){
				st += pow(y[i] - y_prom, 2);
				sr += pow(y[i] - estimar(x[i]), 2);
			}
			
			sy = sqrt(st/(double)(n-1));
			// Para un modelo cuadratico, m = 2, (m + 1) = 3
			syx = sqrt(sr / (double)(n-3));
			
			r2 = (st - sr)/st;
		}
			
			// calcula el valor estimado de x_est usando la regresion cuadratica
			// param x_est valor de x a estimar
			// return valor del polinomio cuadratico para x_est
			double estimar(double x_est){
				if(!valido){return NAN;}
				return a[0]+(a[1]*x_est) + (a[2]*x_est*x_est);
			}
				
				friend ostream& operator<<(ostream & os, const modelo_cuadratico & m){
					if(!m.valido){
						os << "El modelo no es valido" << endl;
						return os;
					}
					
					os << "===========================================" << endl;
					os << "            Resultados de la Regresion      " << endl;
					os << "===========================================" << endl;
					
					os << "Ecuacion cuadratica: " << endl;
					os << "   y = " << m.a[2] << " * x^2"
						<< ((m.a[1] < 0.0f) ? " - " : " + ")
						<< fabs(m.a[1]) << " * x"
						<< ((m.a[0] < 0.0f) ? " - " : " + ")
						<< fabs(m.a[0]) << endl;
					
					os << "-------------------------------------------" << endl;
					
					os << "Coeficiente de determinacion (r2): " << m.r2 << endl;
					os << "Desviacion estandar (sy): " << m.sy << endl;
					os << "Error estandar de aproximacion (syx): " << m.syx << endl;
					os << "Los resultados indican que el modelo explica el "<<m.r2*100.0f<<"% de la incertidumbre original"<<endl;
					
					os << "===========================================" << endl;
					
					return os;
				}
				
	};
	
	class cuadratica {
	private:
		modelo_cuadratico modelo;
		
	public:
		cuadratica(vector<double> x, vector <double> y):modelo(x,y){
		}
		double estimar(double x_est){
			
			if(!modelo.valido){
				return NAN;
			}
			
			return modelo.estimar(x_est);
		}
			
			modelo_cuadratico obtener_modelo(){
				return modelo;
			}
				
	};
	
	
};
#endif
