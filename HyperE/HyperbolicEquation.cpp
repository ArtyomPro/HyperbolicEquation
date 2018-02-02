#include "HyperbolicEquation.h"
#include "MethProgonki.h"
#include <math.h>

HyperbolicEquation::HyperbolicEquation(int n, int m, double l, double tl)
{
	HyperbolicEquation::a = 1;
	if (n<=0) throw "некорректная размерность сетки";
	HyperbolicEquation::n = n+1;
	if (m<=0) throw "некорректная размерность сетки";
	HyperbolicEquation::m = m+1;
		
	HyperbolicEquation::l = l;

	if (tl<=0) throw "некорректное ограничение по t";

	u = new double *[HyperbolicEquation::n];
		for (int j=0; j<HyperbolicEquation::n; j++) u[j] = new double [HyperbolicEquation::m]; 
	u_ = new double *[HyperbolicEquation::n];
		for (int j=0; j<HyperbolicEquation::n; j++) u_[j] = new double [HyperbolicEquation::m]; 
	h = l/n;
	i = tl/m;
}



void HyperbolicEquation::explicit_solution ()
{
	double sign = (i*i)/(h*h);

	if (sign>=1) throw "система неустойчива";

	for (int k=0;k<m;k++)
	{
		for (int j=0;j<n;j++)
		{
			u_[j][k]=analiticSolution(j*h,k*i);
			if (j==0) {u[j][k]=Uot(k*i); continue;}
			if (j==n-1) {u[j][k]=Utl(k*i);  continue;}
			if (k==1) {u[j][k]=DuX0_dt(j*h); continue;}
			if (k==0) {u[j][k]=Uxo(j*h); continue;}
			u[j][k]=(2-2*sign+3*i*i)*u[j][k-1]+sign*sign*(u[j+1][k-1]+u[j-1][k-1])-u[j][k-2];
		}
	}

}

void HyperbolicEquation::implicit_solution()
{
	double *d = new double [n];

	double s = (i*i)/(h*h);

	for (int k=0;k<m;k++)
	{

		for (int j=0;j<n;j++)
		{
			u_[j][k]=analiticSolution(j*h,k*i);
			if (k==1) {u[j][k]=DuX0_dt(j*h); continue;}
			if (k==0) {u[j][k]=Uxo(j*h); continue;}
			if (j==0) 
			{u[j][k]=Uot(k*i); continue;}
			if (j==1) 
			{
				d[j] = -2*u[j][k-1]+u[j][k-2]-s*u[j-1][k];
				continue;
			}
			if (j==n-2) 
			{
				d[j] = -2*u[j][k-1]+u[j][k-2]-s*Utl(k*i);
				continue;
			}
			if (j==n-1) 
			{u[j][k]=Utl(k*i);  
			continue;}
			d[j]= -2*u[j][k-1]+u[j][k-2];

		}

		if (k>=2)
		{
			MethProgonki *m = new MethProgonki(n,d,s,i);
			m->getVariables(u,k);
			delete m;
		}

	}
}

double HyperbolicEquation::analiticSolution (double x, double t)
{
	if (x/pi == 0 ) return sin(2*t);
	if (x/pi == 1 ) return -sin(2*t);
	return cos(x)*sin(2*t);
}

double** HyperbolicEquation::getU ()
{
	if (u != nullptr)
	return u;
	else throw "пустой массив u";
}

double** HyperbolicEquation::getU_ ()
{
	if (u_ != nullptr)
	return u_;
	else throw "пустой массив u_";
}

double** HyperbolicEquation::getError ()
{
		if (u_ != nullptr && u != nullptr)
	{
		double ** err = new double *[n];
		for (int j=0; j<n; j++) err[j] = new double [m]; 

		for (int k=0;k<m;k++)
		{
			for (int j=0;j<n;j++)
			{
				err[j][k]= fabs(u[j][k]-u_[j][k]);
			}
		}

		return err;
	}
	
	else throw "пустой массив u";
}



double HyperbolicEquation::getH ()
{
	return h;
}

double HyperbolicEquation::getI ()
{
	return i;
}

double HyperbolicEquation::Uxo (double x) 
{
	return 0;
}
double HyperbolicEquation::Utl (double t) 
{
	return -sin(2*t);
}
double HyperbolicEquation::Uot (double t)
{
	return sin(2*t);
}
double HyperbolicEquation::DuX0_dt (double x)
{
	return 2*i*cos(x);
}

HyperbolicEquation::~HyperbolicEquation(void)
{
	for (int j=0;j<n;j++) delete [] u[j];
	delete [] u;
	for (int j=0;j<n;j++) delete [] u_[j];
	delete [] u_;
}

double* HyperbolicEquation::getU_t (int t)
{
    double *u1 = new double [n];
    if (u_ != nullptr){
        for(int j=0; j<n; j++)
        {
            u1[j] = u_[j][t];
        }

        return u1;
    }
    else throw "пустой массив u_";
}

double* HyperbolicEquation::getUt (int t)
{
    double *u1 = new double [n];
    if (u != nullptr){
        for(int j=0; j<n; j++)
        {
            u1[j] = u[j][t];
        }

        return u1;
    }
    else throw "пустой массив u_";
}

double* HyperbolicEquation::getX ()
{
    double *x = new double [n];
    if (u != nullptr){
        for(int j=0; j<n; j++)
        {
            x[j] = h*j;
        }

        return x;
    }
    else throw "пустой массив u_";
}