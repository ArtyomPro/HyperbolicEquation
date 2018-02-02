#pragma once
class MethProgonki
{
private:
	double *c; // элементы верхней диагонали матрицы  
    double *b; //элементы главной диагонали
    double *a; //элементы нижней диагонали
    double *D;//значения матрицы 
    double *X; //корни матрицы M 
    //прогоночные коэффициенты 
    double *P;
    double *Q;
    int n; //размерность матрицы
	void ProgonKoef();
    void Var();
		void Solution();
public:
	void getVariables(double**,int);
	MethProgonki(int ,double*, double,double);
};

