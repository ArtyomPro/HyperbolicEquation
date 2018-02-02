#include "MethProgonki.h"
#include <math.h>


MethProgonki::MethProgonki(int n,double *D,double s,double i)
{
	 MethProgonki::n =n;
     //диагонали  
     a = new double [n];
     b = new double [n];
     c = new double [n];
               
     for (int j=1; j<n-1;j++)
		{
			a[j] =s;
			c[j] =s;
			b[j] = -2*s-1-3*i*i;
			if (j==1) a[j]=0; 
			if (j==n-2) c[j] =0;
		}
              
	MethProgonki::D = D;
           
                
    //выделение динамической памяти для матрицы Х
	X = new double [n];
    //создание динамической памяти для матрицыы  коэффициентов P    
	P = new double [n]; 
    //создание динамической памяти для матрицыы  коэффициентов Q 
	Q = new double [n]; 

	Solution();
}

void MethProgonki::Solution()
{            
    ProgonKoef();
    Var();		
}


    
//вычисление прогончных коэффициентов
void MethProgonki::ProgonKoef()
{   
	for (int i=0; i<n ;i++)
	{
		Q[i]=0; P[i]=0;
	}

	for (int i=1; i<n; i++ )   
	{ 
		P[i]=-c[i]/(b[i]+a[i]*P[i-1]);
		Q[i]=(D[i]-a[i]*Q[i-1])/(b[i]+a[i]*P[i-1]);
	}		
}
    
//Обратный ход
 void MethProgonki::Var(){
	for (int i = 0; i < n ; i++)
		X[i] = 0;
	for (int i=n-1; i>0; i--) 
	{
	  X[i]=P[i]*X[i+1]+Q[i]; 
	}    
}
    
void MethProgonki::getVariables(double ** mas, int k)
{
	for (int j=1;j<n-1;j++)
	{
		mas[j][k] = X[j];
	}
}