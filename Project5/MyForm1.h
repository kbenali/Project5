#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	using namespace std;

	/// <summary>
	/// Description résumée de Mygridview
	/// </summary>
	public ref class Mygridview : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlconn = gcnew MySqlConnection();
		MySqlCommand^ sqlcmd = gcnew MySqlCommand();
		DataTable^ sqldt = gcnew DataTable();
		MySqlDataAdapter^ sqldta = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlrd;

	public:
		Mygridview(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Mygridview()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnsearch;
	private: System::Windows::Forms::TextBox^ txtsearch;
	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbltime;

	private: System::Windows::Forms::Label^ lbldate;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ bntdisplay;
	private: System::Windows::Forms::Button^ btnexit;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnsearch = (gcnew System::Windows::Forms::Button());
			this->txtsearch = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbltime = (gcnew System::Windows::Forms::Label());
			this->lbldate = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bntdisplay = (gcnew System::Windows::Forms::Button());
			this->btnexit = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(27, 82);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1243, 453);
			this->dataGridView1->TabIndex = 0;
			// 
			// btnsearch
			// 
			this->btnsearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnsearch->Location = System::Drawing::Point(1087, 20);
			this->btnsearch->Name = L"btnsearch";
			this->btnsearch->Size = System::Drawing::Size(183, 46);
			this->btnsearch->TabIndex = 1;
			this->btnsearch->Text = L"Search";
			this->btnsearch->UseVisualStyleBackColor = true;
			this->btnsearch->Click += gcnew System::EventHandler(this, &Mygridview::btnsearch_Click);
			this->btnsearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Mygridview::btnsearch_KeyPress);
			// 
			// txtsearch
			// 
			this->txtsearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtsearch->Location = System::Drawing::Point(893, 20);
			this->txtsearch->Multiline = true;
			this->txtsearch->Name = L"txtsearch";
			this->txtsearch->Size = System::Drawing::Size(194, 46);
			this->txtsearch->TabIndex = 2;
			this->txtsearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Mygridview::txtsearch_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(303, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// lbltime
			// 
			this->lbltime->AutoSize = true;
			this->lbltime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltime->Location = System::Drawing::Point(1179, 540);
			this->lbltime->Name = L"lbltime";
			this->lbltime->Size = System::Drawing::Size(57, 20);
			this->lbltime->TabIndex = 3;
			this->lbltime->Text = L"label1";
			// 
			// lbldate
			// 
			this->lbldate->AutoSize = true;
			this->lbldate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbldate->Location = System::Drawing::Point(1179, 562);
			this->lbldate->Name = L"lbldate";
			this->lbldate->Size = System::Drawing::Size(57, 20);
			this->lbldate->TabIndex = 3;
			this->lbldate->Text = L"label1";
			this->lbldate->Click += gcnew System::EventHandler(this, &Mygridview::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1975, 784);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label1";
			// 
			// bntdisplay
			// 
			this->bntdisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bntdisplay->Location = System::Drawing::Point(99, 541);
			this->bntdisplay->Name = L"bntdisplay";
			this->bntdisplay->Size = System::Drawing::Size(471, 60);
			this->bntdisplay->TabIndex = 1;
			this->bntdisplay->Text = L"DISPLAY";
			this->bntdisplay->UseVisualStyleBackColor = true;
			this->bntdisplay->Click += gcnew System::EventHandler(this, &Mygridview::bntdisplay_Click);
			// 
			// btnexit
			// 
			this->btnexit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnexit->Location = System::Drawing::Point(601, 541);
			this->btnexit->Name = L"btnexit";
			this->btnexit->Size = System::Drawing::Size(471, 60);
			this->btnexit->TabIndex = 1;
			this->btnexit->Text = L"EXIT";
			this->btnexit->UseVisualStyleBackColor = true;
			this->btnexit->Click += gcnew System::EventHandler(this, &Mygridview::btnexit_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Mygridview::timer1_Tick);
			// 
			// Mygridview
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbldate);
			this->Controls->Add(this->lbltime);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtsearch);
			this->Controls->Add(this->btnexit);
			this->Controls->Add(this->bntdisplay);
			this->Controls->Add(this->btnsearch);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Mygridview";
			this->Text = L"Mygridview";
			this->Load += gcnew System::EventHandler(this, &Mygridview::Mygridview_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		DateTime dt = DateTime::Now;
		lbltime->Text = dt.Now.ToLongTimeString();

	}
	private: System::Void Mygridview_Load(System::Object^ sender, System::EventArgs^ e) {

		DateTime dt = DateTime::Now;
		lbldate->Text = dt.Now.ToLongDateString();

		timer1->Start();

		sqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; \
									password = azerty007; database = projet";

		sqlconn->Open();
		sqlcmd->Connection = sqlconn;
		sqlcmd->CommandText = "SELECT * FROM projet";
		sqlrd = sqlcmd->ExecuteReader();
		sqldt->Load(sqlrd);
		sqlrd->Close();
		sqlconn->Close();
		dataGridView1->DataSource = sqldt;

	}
	private: System::Void btnexit_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult iExit;
		iExit = MessageBox::Show("Confirm if you want to exit", "CPP Connect", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		if (iExit == System::Windows::Forms::DialogResult::Yes)
		{
			Application::Exit();
		}
	}
	private: System::Void txtsearch_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		try
		{
			if (e->KeyChar == (Char)13)
			{
				DataView^ dv = sqldt->DefaultView;
				dv->RowFilter = String::Format("Firstname like '%{0}%'", txtsearch->Text);
				dataGridView1->DataSource = dv->ToTable();
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
private: System::Void btnsearch_Click(System::Object^ sender, System::EventArgs^ e) {

	try
	{
		
			DataView^ dv = sqldt->DefaultView;
			dv->RowFilter = String::Format("Firstname like '%{0}%'", txtsearch->Text);
			dataGridView1->DataSource = dv->ToTable();
		
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}
private: System::Void btnsearch_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	try
	{
		if (e->KeyChar == (Char)13)
		{
			DataView^ dv = sqldt->DefaultView;
			dv->RowFilter = String::Format("Firstname like '%{0}%'", txtsearch->Text);
			dataGridView1->DataSource = dv->ToTable();
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}

}
private: System::Void bntdisplay_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Hide();
	Mygridview^ main = gcnew Mygridview();
	main->Show();
}
};
}
