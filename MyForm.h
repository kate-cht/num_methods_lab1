#pragma once
#include <math.h>
#include "C:\Users\User\CRZKODY_lab_1\solution\TestTask.h"
#include "C:\Users\User\CRZKODY_lab_1\solution\FirstTask.h"
#include "C:\Users\User\CRZKODY_lab_1\solution\SecondTask.h"

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  F_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  F_2;

	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button2;




	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;











	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->F_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->F_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(365, 37);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(5);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(668, 402);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(844, 475);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 36);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(1107, 37);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(593, 596);
			this->dataGridView1->TabIndex = 2;
			// 
			// X
			// 
			this->X->MinimumWidth = 6;
			this->X->Name = L"X";
			this->X->Width = 125;
			// 
			// F_1
			// 
			this->F_1->MinimumWidth = 6;
			this->F_1->Name = L"F_1";
			this->F_1->Width = 125;
			// 
			// F_2
			// 
			this->F_2->MinimumWidth = 6;
			this->F_2->Name = L"F_2";
			this->F_2->Width = 125;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(128, 484);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(63, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(128, 514);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(63, 22);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(216, 490);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Шаг метода";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(307, 484);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(80, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"0,01";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(844, 538);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(189, 36);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Увеличить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(75, 520);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"x_max";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(75, 490);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"x_min";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(466, 490);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Параметр контроля Л.П.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(466, 523);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(199, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Параметр выхода за границу";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(466, 555);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(165, 16);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Макс. количество шагов";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(675, 487);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(73, 22);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"1e-7";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(675, 520);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(73, 22);
			this->textBox5->TabIndex = 14;
			this->textBox5->Text = L"1e-7";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(675, 552);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(73, 22);
			this->textBox6->TabIndex = 15;
			this->textBox6->Text = L"1000";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(87, 552);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 16);
			this->label7->TabIndex = 16;
			this->label7->Text = L"u0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(84, 581);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 16);
			this->label8->TabIndex = 17;
			this->label8->Text = L"u\'0";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(128, 549);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(63, 22);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"7";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(128, 578);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(63, 22);
			this->textBox8->TabIndex = 19;
			this->textBox8->Text = L"12";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(75, 136);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(61, 16);
			this->label9->TabIndex = 20;
			this->label9->Text = L"ЗАДАЧА";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(75, 232);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(70, 16);
			this->label10->TabIndex = 21;
			this->label10->Text = L"СПРАВКА";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(469, 613);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(267, 20);
			this->checkBox1->TabIndex = 22;
			this->checkBox1->Text = L"Контроль Л.П за счет двойного шага";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(78, 37);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(141, 20);
			this->radioButton1->TabIndex = 23;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Тестовая задача";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(78, 63);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(153, 20);
			this->radioButton2->TabIndex = 24;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Основная задача 1";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(78, 89);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(153, 20);
			this->radioButton3->TabIndex = 25;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Основная задача 2";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(75, 171);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 16);
			this->label11->TabIndex = 26;
			this->label11->Text = L"label11";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(75, 258);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(51, 16);
			this->label12->TabIndex = 27;
			this->label12->Text = L"label12";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->Location = System::Drawing::Point(844, 613);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(237, 20);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Построить фазовый портрет";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(250, 520);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 16);
			this->label13->TabIndex = 28;
			this->label13->Text = L"alpha";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(257, 552);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(34, 16);
			this->label14->TabIndex = 29;
			this->label14->Text = L"beta";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(307, 516);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(80, 22);
			this->textBox9->TabIndex = 30;
			this->textBox9->Text = L"7";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(307, 549);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(80, 22);
			this->textBox10->TabIndex = 31;
			this->textBox10->Text = L"5";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1835, 671);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// создание столбцов таблички
		void UpdateDataGridViewWithHeaders(const std::vector<std::string>& name) {

			// Очищаем таблицу
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			// Создаем столбцы с заголовками
			for (int i = 0; i < name.size(); i++) {
				DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
				column->HeaderText = gcnew String(name[i].c_str());
				column->Name = String::Format("col{0}", i);
				column->Width = 120;
				if ((name[i] == "i")  || (name[i] == "C1") || (name[i] == "C2"))
					column->DefaultCellStyle->Format = "F0";
				else column->DefaultCellStyle->Format = "F8";
				dataGridView1->Columns->Add(column);
			}
		}

	// кнопка - рисовать
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		

		// данные с чекбоксов
		double xmin = Convert::ToDouble(textBox1->Text);
		double xmax = Convert::ToDouble(textBox2->Text);
		double h = Convert::ToDouble(textBox3->Text);
		double E_error = Convert::ToDouble(textBox4->Text);
		double E_border = Convert::ToDouble(textBox5->Text);
		double Nmax = Convert::ToDouble(textBox6->Text);
		double u0 = Convert::ToDouble(textBox7->Text);
		double _u0 = Convert::ToDouble(textBox8->Text); // производная
		double alpha = Convert::ToDouble(textBox9->Text);;
		double beta = Convert::ToDouble(textBox10->Text);;
		//TestTask task0(xmin, xmax, h, u0, E_border, E_error, Nmax);
		if (radioButton1->Checked)
		{
			PointPairList^ f1_list = gcnew ZedGraph::PointPairList(); // численное решение
			PointPairList^ f2_list = gcnew ZedGraph::PointPairList(); // истинное решение
			TestTask task0(xmin, xmax, h, u0, E_border, E_error, Nmax);
			if (checkBox1->Checked)
				task0.Solve_With_Control();
			else task0.Solve_Without_Control();
			std::list<std::vector<double>> table = task0.TABLE_INFORMATION;
			UpdateDataGridViewWithHeaders(task0.TABLE_NAME);
			int size = (table.front()).size();
			dataGridView1->Rows->Clear();
			for (auto it = table.begin(); it != table.end(); ++it) {
				f1_list->Add((*it)[1], (*it)[2]);
				f2_list->Add((*it)[1], (*it)[size - 2]);
				dataGridView1->Rows->Add();
				for (int j = 0; j < size; ++j)
					dataGridView1->Rows[static_cast<int>((*it)[0])]->Cells[j]->Value = (*it)[j];
			}
			const TestTask::Info& info = task0.get_info();
			if (checkBox1->Checked)
				this->label12->Text = String::Concat("Количество шагов: ", (info.n).ToString(), "\n", 
					"Расстояние до границы: ", (info.B_xn).ToString(), "\n", "Максимальная ОЛП: ", (info.MaxOLP).ToString("F8"), "\n",
					"Удвоений шага: ", (info.DoublingCount).ToString(), "\n", "Уменьшений шага: ", (info.ReductionCount).ToString(), "\n", 
					"Максимальный шаг: ", (info.max_hi_xi.first).ToString("F8"), "\n", " в точке x=", (info.max_hi_xi.second).ToString("F8"), "\n",
					"Минимальный шаг: ", (info.min_hi_xi.first).ToString("F8"), "\n"," в точке x=", (info.min_hi_xi.second).ToString("F8"), "\n",
					"Максимальная разность |U-V|: ", "\n", (info.maxU_V.second).ToString("F8"), " в точке x=", (info.maxU_V.first).ToString("F8"));
			
			else  this->label12->Text = String::Concat("Количество шагов: ", (info.n).ToString(), "\n", "Расстояние до границы: ", (info.B_xn).ToString(), "\n", "Максимальная разность |U-V|: ", "\n", (info.maxU_V.second).ToString(), " в точке x=", (info.maxU_V.first).ToString());

			LineItem Curve1 = panel->AddCurve("Численное решение", f1_list, Color::Red, SymbolType::Plus);
			LineItem Curve2 = panel->AddCurve("Истинное решение", f2_list, Color::Blue, SymbolType::Circle);


			double xmin_limit = xmin - 0.1;
			double xmax_limit = xmax + 0.1;
			// Устанавливаем интересующий нас интервал по оси X
			panel->XAxis->Scale->Min = xmin_limit;
			panel->XAxis->Scale->Max = xmax_limit;
		}
		if (radioButton2->Checked)
		{
			PointPairList^ f1_list = gcnew ZedGraph::PointPairList(); // численное решение
			FirstTask task0(xmin, xmax, h, u0, E_border, E_error, Nmax);
			if (checkBox1->Checked)
				task0.Solve_With_Control();
			else task0.Solve_Without_Control();
			std::list<std::vector<double>> table = task0.TABLE_INFORMATION;
			UpdateDataGridViewWithHeaders(task0.TABLE_NAME);
			int size = (table.front()).size();
			dataGridView1->Rows->Clear();
			for (auto it = table.begin(); it != table.end(); ++it) {
				f1_list->Add((*it)[1], (*it)[2]);
				dataGridView1->Rows->Add();
				for (int j = 0; j < size; ++j)
					dataGridView1->Rows[static_cast<int>((*it)[0])]->Cells[j]->Value = (*it)[j];
			}
			const TestTask::Info& info = task0.get_info();
			if (checkBox1->Checked)
				this->label12->Text = String::Concat("Количество шагов: ",
					(info.n).ToString(), "\n", "Расстояние до границы: ", (info.B_xn).ToString("F8"), "\n",
					"Максимальная ОЛП: ", (info.MaxOLP).ToString("F8"), "\n", "Удвоений шага: ", (info.DoublingCount).ToString(), "\n",
					"Уменьшений шага: ", (info.ReductionCount).ToString(), "\n",
					"Максимальный шаг: ", (info.max_hi_xi.first).ToString("F3"), "\n", " в точке x=", (info.max_hi_xi.second).ToString("F8"), "\n",
					"Минимальный шаг: ", (info.min_hi_xi.first).ToString("F8"), "\n", " в точке x=", (info.min_hi_xi.second).ToString("F8"), "\n");
			else  this->label12->Text = String::Concat("Количество шагов: ", (info.n).ToString(), "\n", "Расстояние до границы: ", (info.B_xn).ToString(), "\n");
			LineItem Curve1 = panel->AddCurve("Численное решение", f1_list, Color::Red, SymbolType::Plus);

			double xmin_limit = xmin - 0.1;
			double xmax_limit = xmax + 0.1;
			// Устанавливаем интересующий нас интервал по оси X
			panel->XAxis->Scale->Min = xmin_limit;
			panel->XAxis->Scale->Max = xmax_limit;
		}
		if (radioButton3->Checked) 
		{
			PointPairList^ f1_list = gcnew ZedGraph::PointPairList(); // численное решение
			PointPairList^ f2_list = gcnew ZedGraph::PointPairList(); // истинное решение
			PointPairList^ f_p = gcnew ZedGraph::PointPairList(); // фаз портрет
			SecondTask task0(xmin, xmax, h, u0, _u0, E_border, E_error, Nmax, alpha, beta);
			if (checkBox1->Checked)
				task0.Solve_With_Control();
			else task0.Solve_Without_Control();
			std::list<std::vector<double>> table = task0.TABLE_INFORMATION;

			UpdateDataGridViewWithHeaders(task0.TABLE_NAME);
			int size = (table.front()).size();
			dataGridView1->Rows->Clear();

			for (auto it = table.begin(); it != table.end(); ++it) {
				f1_list->Add((*it)[1], (*it)[2]); 
				f2_list->Add((*it)[1], (*it)[3]);
				f_p->Add((*it)[2], (*it)[3]);
				dataGridView1->Rows->Add();
				for (int j = 0; j < size; ++j)
					dataGridView1->Rows[static_cast<int>((*it)[0])]->Cells[j]->Value = (*it)[j];
			}
			const TestTask::Info& info = task0.get_info();
			if (checkBox1->Checked)
				this->label12->Text = String::Concat("Количество шагов: ", 
					(info.n).ToString(), "\n", "Расстояние до границы: ", (info.B_xn).ToString("F8"), "\n", 
					"Максимальная ОЛП: ", (info.MaxOLP).ToString("F8"), "\n", "Удвоений шага: ", (info.DoublingCount).ToString(), "\n", 
					"Уменьшений шага: ", (info.ReductionCount).ToString(), "\n", 
					"Максимальный шаг: ", (info.max_hi_xi.first).ToString("F3"), "\n", " в точке x=", (info.max_hi_xi.second).ToString("F8"), "\n",
					"Минимальный шаг: ", (info.min_hi_xi.first).ToString("F8"), "\n", " в точке x=", (info.min_hi_xi.second).ToString("F8"), "\n");
			else  this->label12->Text = String::Concat("Количество шагов: ", (info.n).ToString(), "\n", "Расстояние до границы: ", (info.B_xn).ToString(), "\n");
			if (checkBox2->Checked)
			{
				LineItem Curve1 = panel->AddCurve("Фазовая траектория", f_p, Color::Red, SymbolType::Plus);
				panel->XAxis->Scale->Min = u0 - 0.1;
				panel->XAxis->Scale->Max = u0 + 2.1;
			}
			else
			{
				LineItem Curve1 = panel->AddCurve("V", f1_list, Color::Red, SymbolType::Plus);
				LineItem Curve2 = panel->AddCurve("V'", f2_list, Color::Blue, SymbolType::Circle);

				double xmin_limit = xmin - 0.1;
				double xmax_limit = xmax + 0.1;
				// Устанавливаем интересующий нас интервал по оси X
				panel->XAxis->Scale->Min = xmin_limit;
				panel->XAxis->Scale->Max = xmax_limit;
			}
		}


		// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
		// В противном случае на рисунке будет показана только часть графика, 
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();

	}
	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
// кнопка - зум
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	GraphPane^ panel = zedGraphControl1->GraphPane;
	double xmin = Convert::ToDouble(textBox1->Text);
	double xmax = Convert::ToDouble(textBox2->Text);
	// Устанавливаем интересующий нас интервал по оси X
	panel->XAxis->Scale->Min = xmin;
	panel->XAxis->Scale->Max = xmax;

	// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
	// В противном случае на рисунке будет показана только часть графика, 
	// которая умещается в интервалы по осям, установленные по умолчанию
	zedGraphControl1->AxisChange();
	// Обновляем график
	zedGraphControl1->Invalidate();

}


private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button1->PerformClick();
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	button1->PerformClick();
}

private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	GraphPane^ panel = zedGraphControl1->GraphPane;
	panel->Title->Text = "Графики";
	panel->XAxis->Title->Text = L"Ось X";            
	panel->YAxis->Title->Text = L"Ось Y";
	this->label11->Text = L"du/dx = u\n u(0) = u0\n";
	this->label12->Text = L"Здесь будут данные справки";
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->label11->Text = L"du/dx = u\n u(0) = u0\n";
	button1->PerformClick();
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->label11->Text = L"du/dx = xu^2/(1+x^2) + u - u^3*sin(10x)\n u(0) = u0\n";
	button1->PerformClick();
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->label11->Text = L"d2u/dx2 + alpha * u' + beta * u = 0\n u(0) = u0\n u'(0) = u'0";
	button1->PerformClick();
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
