#pragma once
class MethProgonki
{
private:
	double *c; // �������� ������� ��������� �������  
    double *b; //�������� ������� ���������
    double *a; //�������� ������ ���������
    double *D;//�������� ������� 
    double *X; //����� ������� M 
    //����������� ������������ 
    double *P;
    double *Q;
    int n; //����������� �������
	void ProgonKoef();
    void Var();
		void Solution();
public:
	void getVariables(double**,int);
	MethProgonki(int ,double*, double,double);
};

