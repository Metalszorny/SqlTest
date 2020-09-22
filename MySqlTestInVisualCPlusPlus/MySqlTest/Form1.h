#pragma once
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"

namespace MySqlTest
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
    /// Interaction logic for Form1.
    /// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		#pragma region Constructors

		/// <summary>
        /// Initializes a new instance of the Form1 class.
        /// </summary>
		public: Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

		#pragma endregion

		#pragma region GUI

		private: System::Windows::Forms::Button^  button1;
		protected: 
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button4;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		private: System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(63, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"People";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(63, 87);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Relationships";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(63, 144);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(96, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Relations";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(63, 198);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(96, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Exit";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(214, 262);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Menu";
			this->ResumeLayout(false);
		}

		#pragma endregion

		#pragma endregion

		#pragma region Methods

		/// <summary>
		/// Handles the Click event of the button1 control.
		/// </summary>
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Open the People form.
			Form2^ people = gcnew Form2();
			people->Show();
		}

		/// <summary>
		/// Handles the Click event of the button2 control.
		/// </summary>
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Open the Relationships form.
			Form3^ relationships = gcnew Form3();
			relationships->Show();
		}

		/// <summary>
		/// Handles the Click event of the button3 control.
		/// </summary>
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Open the Relations form.
			Form4^ relations = gcnew Form4();
			relations->Show();
		}

		/// <summary>
		/// Handles the Click event of the button4 control.
		/// </summary>
		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Exit the program.
			this->Close();
		}

		#pragma endregion
	};
}

