#pragma once
#include "HyperbolicEquation.h"


namespace HyperE {

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		static int d=0;
		HyperbolicEquation *u;
		int n,m;
		double tl;
	private: System::Windows::Forms::TextBox^  tbSpace;
	private: System::Windows::Forms::TextBox^  tbTime;

	private: System::Windows::Forms::TextBox^  tbTimeLimit;
	private: System::Windows::Forms::Label^  labelSpace;
	private: System::Windows::Forms::Label^  labelTime;
	private: System::Windows::Forms::Label^  labelTimeLimit;
	private: System::Windows::Forms::Label^  labelMaxError;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  labelTimeSpeed;
	private: System::Windows::Forms::NumericUpDown^  tbTimeSpeed;


	public: 
		static bool time = false;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				//delete u;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  btnOnOff;
	private: System::Windows::Forms::Label^  labelTimeShow;


	private: System::Windows::Forms::Timer^  timer;

	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btnOnOff = (gcnew System::Windows::Forms::Button());
			this->labelTimeShow = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->tbSpace = (gcnew System::Windows::Forms::TextBox());
			this->tbTime = (gcnew System::Windows::Forms::TextBox());
			this->tbTimeLimit = (gcnew System::Windows::Forms::TextBox());
			this->labelSpace = (gcnew System::Windows::Forms::Label());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->labelTimeLimit = (gcnew System::Windows::Forms::Label());
			this->labelMaxError = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labelTimeSpeed = (gcnew System::Windows::Forms::Label());
			this->tbTimeSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbTimeSpeed))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->AxisX->Maximum = 3.15;
			chartArea2->AxisX->Minimum = 0;
			chartArea2->AxisY->Maximum = 1;
			chartArea2->AxisY->Minimum = -1;
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(-4, -3);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->chart1->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(2) {System::Drawing::Color::Blue, System::Drawing::Color::Red};
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"Аналитическое";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->Name = L"Численное";
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(691, 390);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// btnOnOff
			// 
			this->btnOnOff->Location = System::Drawing::Point(844, 154);
			this->btnOnOff->Name = L"btnOnOff";
			this->btnOnOff->Size = System::Drawing::Size(75, 23);
			this->btnOnOff->TabIndex = 1;
			this->btnOnOff->Text = L"ON/OFF";
			this->btnOnOff->UseVisualStyleBackColor = true;
			this->btnOnOff->Click += gcnew System::EventHandler(this, &MyForm::btnOnOff_Click);
			// 
			// labelTimeShow
			// 
			this->labelTimeShow->AutoSize = true;
			this->labelTimeShow->Location = System::Drawing::Point(693, 201);
			this->labelTimeShow->Name = L"labelTimeShow";
			this->labelTimeShow->Size = System::Drawing::Size(0, 13);
			this->labelTimeShow->TabIndex = 2;
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// tbSpace
			// 
			this->tbSpace->Location = System::Drawing::Point(696, 24);
			this->tbSpace->Name = L"tbSpace";
			this->tbSpace->Size = System::Drawing::Size(223, 20);
			this->tbSpace->TabIndex = 3;
			this->tbSpace->Text = L"5";
			// 
			// tbTime
			// 
			this->tbTime->Location = System::Drawing::Point(696, 63);
			this->tbTime->Name = L"tbTime";
			this->tbTime->Size = System::Drawing::Size(223, 20);
			this->tbTime->TabIndex = 4;
			this->tbTime->Text = L"5";
			// 
			// tbTimeLimit
			// 
			this->tbTimeLimit->Location = System::Drawing::Point(696, 104);
			this->tbTimeLimit->Name = L"tbTimeLimit";
			this->tbTimeLimit->Size = System::Drawing::Size(223, 20);
			this->tbTimeLimit->TabIndex = 5;
			this->tbTimeLimit->Text = L"1";
			// 
			// labelSpace
			// 
			this->labelSpace->AutoSize = true;
			this->labelSpace->Location = System::Drawing::Point(696, 8);
			this->labelSpace->Name = L"labelSpace";
			this->labelSpace->Size = System::Drawing::Size(191, 13);
			this->labelSpace->TabIndex = 6;
			this->labelSpace->Text = L"Кол-во разделений по пространству";
			// 
			// labelTime
			// 
			this->labelTime->AutoSize = true;
			this->labelTime->Location = System::Drawing::Point(696, 47);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(166, 13);
			this->labelTime->TabIndex = 7;
			this->labelTime->Text = L"Кол-во разделений по времени";
			// 
			// labelTimeLimit
			// 
			this->labelTimeLimit->AutoSize = true;
			this->labelTimeLimit->Location = System::Drawing::Point(696, 88);
			this->labelTimeLimit->Name = L"labelTimeLimit";
			this->labelTimeLimit->Size = System::Drawing::Size(111, 13);
			this->labelTimeLimit->TabIndex = 8;
			this->labelTimeLimit->Text = L"Граница по времени";
			// 
			// labelMaxError
			// 
			this->labelMaxError->AutoSize = true;
			this->labelMaxError->Location = System::Drawing::Point(693, 226);
			this->labelMaxError->Name = L"labelMaxError";
			this->labelMaxError->Size = System::Drawing::Size(0, 13);
			this->labelMaxError->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(699, 259);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 10;
			// 
			// labelTimeSpeed
			// 
			this->labelTimeSpeed->AutoSize = true;
			this->labelTimeSpeed->Location = System::Drawing::Point(693, 141);
			this->labelTimeSpeed->Name = L"labelTimeSpeed";
			this->labelTimeSpeed->Size = System::Drawing::Size(76, 13);
			this->labelTimeSpeed->TabIndex = 11;
			this->labelTimeSpeed->Text = L"Интервал(мс)";
			// 
			// tbTimeSpeed
			// 
			this->tbTimeSpeed->Location = System::Drawing::Point(696, 157);
			this->tbTimeSpeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->tbTimeSpeed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->tbTimeSpeed->Name = L"tbTimeSpeed";
			this->tbTimeSpeed->Size = System::Drawing::Size(120, 20);
			this->tbTimeSpeed->TabIndex = 14;
			this->tbTimeSpeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(931, 387);
			this->Controls->Add(this->tbTimeSpeed);
			this->Controls->Add(this->labelTimeSpeed);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->labelMaxError);
			this->Controls->Add(this->labelTimeLimit);
			this->Controls->Add(this->labelTime);
			this->Controls->Add(this->labelSpace);
			this->Controls->Add(this->tbTimeLimit);
			this->Controls->Add(this->tbTime);
			this->Controls->Add(this->tbSpace);
			this->Controls->Add(this->labelTimeShow);
			this->Controls->Add(this->btnOnOff);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"ChartHyperbolic";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tbTimeSpeed))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		double maxErr (double** mas, double h, double i, int n, int m)
		{
			double max =0;
			int maxj,maxk;
			for (int k=0;k<=m;k++)
			{
				for (int j=0;j<=n;j++)
				{
					if (mas[j][k]>max)
					{
						max = mas[j][k]; maxj=j; maxk=k;
					}
				}
		
			}

			return max;
		}
#pragma endregion
	private: System::Void btnOnOff_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				  label6->Text = " ";
				 if(!time){
					tbSpace->Enabled = false;
					tbTime->Enabled = false;
					tbTimeLimit->Enabled = false;
					tbTimeSpeed->Enabled = false;
					time = true;
					n = Convert::ToInt32(tbSpace->Text);
					m = Convert::ToInt32(tbTime->Text);
					tl = Convert::ToDouble(tbTimeLimit->Text);
					u = new HyperbolicEquation(n,m,pi,tl);
					u->implicit_solution();
					//u->explicit_solution();
					labelMaxError->Text = "Макс погрешность: "+Convert::ToString( maxErr(u->getError(),u->getH(),u->getI(),n,m));
					timer->Interval = Convert::ToInt32(tbTimeSpeed->Text);
					timer->Start();
				 }
				 else 
				 {
					timer->Stop();
					chart1->Series["Аналитическое"]->Points->Clear();
					chart1->Series["Численное"]->Points->Clear();
					d=0;
					tbSpace->Enabled = true;
					tbTime->Enabled = true;
					tbTimeLimit->Enabled = true;
					tbTimeSpeed->Enabled = true;
					time = false;
					labelTimeShow->Text ="";
					labelMaxError->Text ="";
					delete u;
				 }
			 }

private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {

				 chart1->Series["Аналитическое"]->Points->Clear();
				 chart1->Series["Численное"]->Points->Clear();

				 try{
				
					double *xa = u->getX();
					double *za = u->getU_t(d);

					double *xn = u->getX();
					double *zn = u->getUt(d);

					for(int i=0; i<n; i++){
						chart1->Series["Аналитическое"]->Points->AddXY(xa[i],za[i]);
						chart1->Series["Численное"]->Points->AddXY(xn[i],zn[i]);
					}
					labelTimeShow->Text = "t = "+d*u->getI();
					d++;
					if (d==m) d=0;
					delete xa,xn,zn,za;
				 }
				 catch(const char * c)
				 {
					 //label6->Text = printf("error: ,%s",c);
					 
				 }
		 }
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}