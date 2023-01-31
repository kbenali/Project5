#pragma once

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de requete
	/// </summary>
	public ref class requete : public System::Windows::Forms::Form
	{
	public:
		requete(void)
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
		~requete()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ btndb;
	protected:

	private: System::Windows::Forms::Button^ map;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ btnrd;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ btncmd;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btndb = (gcnew System::Windows::Forms::TextBox());
			this->map = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnrd = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btncmd = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(183, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(426, 35);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Saisir votre requete ici :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// btndb
			// 
			this->btndb->Location = System::Drawing::Point(22, 139);
			this->btndb->Multiline = true;
			this->btndb->Name = L"btndb";
			this->btndb->Size = System::Drawing::Size(318, 30);
			this->btndb->TabIndex = 1;
			this->btndb->TextChanged += gcnew System::EventHandler(this, &requete::textBox1_TextChanged);
			// 
			// map
			// 
			this->map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->map->Location = System::Drawing::Point(576, 424);
			this->map->Name = L"map";
			this->map->Size = System::Drawing::Size(212, 45);
			this->map->TabIndex = 2;
			this->map->Text = L"Mappping";
			this->map->UseVisualStyleBackColor = true;
			this->map->Click += gcnew System::EventHandler(this, &requete::map_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(26, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Database";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(26, 213);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(121, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Retreive Data";
			// 
			// btnrd
			// 
			this->btnrd->Location = System::Drawing::Point(22, 247);
			this->btnrd->Multiline = true;
			this->btnrd->Name = L"btnrd";
			this->btnrd->Size = System::Drawing::Size(318, 30);
			this->btnrd->TabIndex = 1;
			this->btnrd->TextChanged += gcnew System::EventHandler(this, &requete::textBox1_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(26, 323);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Condition";
			// 
			// btncmd
			// 
			this->btncmd->Location = System::Drawing::Point(22, 360);
			this->btncmd->Multiline = true;
			this->btncmd->Name = L"btncmd";
			this->btncmd->Size = System::Drawing::Size(318, 30);
			this->btncmd->TabIndex = 1;
			this->btncmd->TextChanged += gcnew System::EventHandler(this, &requete::textBox1_TextChanged);
			// 
			// requete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 503);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btncmd);
			this->Controls->Add(this->btnrd);
			this->Controls->Add(this->map);
			this->Controls->Add(this->btndb);
			this->Controls->Add(this->label1);
			this->Name = L"requete";
			this->Text = L"requete";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void map_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ database = this->btndb->Text;
		String^ retdata = this->btnrd->Text;
		String^ cond = this->btncmd->Text;

		if (database->Length == 0 || retdata->Length == 0 || cond->Length == 0)
		{
			MessageBox::Show("Please enter all thefields", "one or more are empty", MessageBoxButtons::OK);
			return;

		}


	}
};
}
