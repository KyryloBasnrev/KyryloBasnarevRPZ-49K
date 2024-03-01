#pragma once
#include "Clas.h"
#include <Windows.h>
#include <iostream>
#include <msclr/marshal_cppstd.h>


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
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
			}
		}

	protected:


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::Button^ button2;






	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(165, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->id, this->name });
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(381, 208);
			this->dataGridView1->TabIndex = 2;
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			// 
			// name
			// 
			this->name->HeaderText = L"Name";
			this->name->Name = L"name";
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(399, 111);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(324, 18);
			this->textBox->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(545, 305);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(749, 401);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		/*String^ conectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\C++_Proj\\Life1\\Life1\\Database.accdb";
		OleDbConnection^ dbConection = gcnew OleDbConnection(conectionString);

		dbConection->Open();
		String^ query = "SELECT ID, TYPE FROM [MedPlcTable]";

		OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConection);
		OleDbDataReader^ dbReader = dbComand->ExecuteReader();

		if (dbReader->HasRows == false) {
			MessageBox::Show("Erorr", "Erorr");
		}
		else {
			while (dbReader->Read()) {
				dataGridView1->Rows->Add (dbReader["ID"], dbReader["TYPE"]);
			}
		}

		dbReader->Close();
		dbConection->Close();*/
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\C++_Proj\\Life1\\Life1\\Database.accdb";
		OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

		try
		{
			// Открытие соединения
			connection->Open();

			// Выполнение запроса
			String^ query = "SELECT * FROM [MedPlcTable]";
			OleDbCommand^ command = gcnew OleDbCommand(query, connection);
			OleDbDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				String^ data = "";
				for (int i = 0; i < reader->FieldCount; i++)
				{
					data += reader->GetValue(i)->ToString() + "\t";
				}
				textBox->AppendText(data + Environment::NewLine);
			}

			// Закрытие соединения и отображение формы
			reader->Close();
			connection->Close();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message);
		}
	}
};
}
