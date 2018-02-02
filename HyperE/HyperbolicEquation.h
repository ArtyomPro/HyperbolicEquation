#pragma once

const double pi = 3.1415926535897932;

// d2u/dt2 = d2u/dx2 -3u;
// 0<x<pi
// 0<t<t1
// a = 1;


class HyperbolicEquation
{
private:
	double a; // ��������� ���������
	double h; // ��� � ������������
	double i; // ��� �� �������
	double l; // ������� x
	double** u; 
	double** u_; // ������������� �������
	int n,m; //- ���-�� ������� � �����;
	//������� �������
	double Uxo (double) ;
	double Utl (double) ;
	double Uot (double) ;
	double DuX0_dt (double) ;
	// �������
	double analiticSolution(double, double);
public:
	HyperbolicEquation(int , int , double, double);
	~HyperbolicEquation(void);
	 double** getU();
    double* getUt(int);
    double** getU_();
    double* getU_t(int);
    double** getError();
    double getH();
    double getI();
    double* getX();
    double* getT();
	void explicit_solution();
	void implicit_solution();
};


