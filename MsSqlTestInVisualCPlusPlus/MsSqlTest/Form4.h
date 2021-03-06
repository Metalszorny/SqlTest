#pragma once
#include <exception>
#include "Person.h"
#include "Relationship.h"
#include "Relation.h"

namespace MsSqlTest
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;
	using namespace System::Linq;
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace System::Windows::Forms;
	using namespace std;

	/// <summary>
	/// Interaction logic for Form4.
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
		#pragma region Fields

		// The database connectionString.
		private: String^ url;

        // The id value.
		private: int id;

        // The person1 value.
		private: int name1;

        // The relationship value.
		private: int relationship;

        // The person2 value.
		private: int name2;

		#pragma endregion

		#pragma region Constructors

		/// <summary>
        /// Initializes a new instance of the <see cref="Form4"/> class.
        /// </summary>
		public: Form4(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~Form4()
		{
			if (components)
			{
				delete components;
			}
		}

		#pragma endregion

		#pragma region GUI

		private: System::Windows::Forms::GroupBox^  groupBox2;
		protected: 
		private: System::Windows::Forms::Label^  label9;
		private: System::Windows::Forms::Label^  label8;
		private: System::Windows::Forms::Label^  label7;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Button^  button5;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::GroupBox^  groupBox1;
		private: System::Windows::Forms::ComboBox^  comboBox3;
		private: System::Windows::Forms::ComboBox^  comboBox2;
		private: System::Windows::Forms::ComboBox^  comboBox1;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;

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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(441, 199);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(255, 118);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Helper:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(80, 83);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"label9";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(80, 55);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"label8";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(80, 28);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"label7";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Person2:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Relationship:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Person1:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(621, 547);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 12;
			this->button5->Text = L"Close";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form4::button5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(441, 547);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"List";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form4::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox3);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(441, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 190);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modify:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(80, 71);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(163, 21);
			this->comboBox3->TabIndex = 13;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form4::comboBox3_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(80, 45);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(163, 21);
			this->comboBox2->TabIndex = 12;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form4::comboBox2_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(80, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(163, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form4::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Person2:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Relationship:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Person1:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(168, 161);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form4::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(87, 161);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Edit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form4::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form4::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column3, this->Column4});
			this->dataGridView1->Location = System::Drawing::Point(2, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(433, 567);
			this->dataGridView1->TabIndex = 9;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form4::dataGridView1_CellClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Person1";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Relationship";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Person2";
			this->Column4->Name = L"Column4";
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 572);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form4";
			this->Text = L"Relations";
			this->Load += gcnew System::EventHandler(this, &Form4::Form4_Load);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
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
			// List the records.
			GetData();
		}

		/// <summary>
		/// Handles the Click event of the button2 control.
		/// </summary>
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Add a record.
			try
            {
                // The fileds must not be empty and the names must not match.
                if (name1 != 0 && name2 != 0 && relationship != 0 && name1 != name2)
                {
                    id = 0;
                    bool^ matchFound = false;

                    // Open a connection to the database.
                    SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                    msSqlConnection->Open();

                    // Get the items of the Relations table.
                    SqlCommand^ msSqlCommand1 = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations]", msSqlConnection);

                    // Execute.
                    SqlDataReader^ msSqlDataReader1 = msSqlCommand1->ExecuteReader();

                    // Get the number of the existing items.
                    while (msSqlDataReader1->Read())
                    {
                        id += 1;

                        // Search for a deleted mathing item.
                        if (!matchFound &&
                            msSqlDataReader1->GetInt32(1) == name1 &&
                            msSqlDataReader1->GetInt32(2) == relationship &&
                            msSqlDataReader1->GetInt32(3) == name2 &&
                            msSqlDataReader1->GetBoolean(4) == true)
                        {
                            matchFound = true;
                            id = msSqlDataReader1->GetInt32(0);

                            break;
                        }
                    }

                    // Close the dataReader.
                    msSqlDataReader1->Close();

                    // Add an item if no deleted found else restore the item.
                    if (matchFound->ToString()->ToLower() == "false")
                    {
                        // Add a new item into the Relations table.
                        SqlCommand^ msSqlCommand = gcnew SqlCommand("INSERT INTO [MsSqlTestDatabase].[dbo].[Relations] (Id, Person1, Relationship, Person2, IsDeleted) VALUES (@param1, @param2, @param3, @param4, @param5)", msSqlConnection);

                        // Fill the values of the command.
                        msSqlCommand->Parameters->AddWithValue("@param1", id + 1);
                        msSqlCommand->Parameters->AddWithValue("@param2", name1);
                        msSqlCommand->Parameters->AddWithValue("@param3", relationship);
                        msSqlCommand->Parameters->AddWithValue("@param4", name2);
                        msSqlCommand->Parameters->AddWithValue("@param5", false);

                        // Execute.
                        msSqlCommand->ExecuteNonQuery();
                    }
                    else
                    {
                        // Edit the IsDeleted value to true.
                        SqlCommand^ msSqlCommand = gcnew SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET IsDeleted = @param2 WHERE Id = @param1", msSqlConnection);

                        // Fill the values of the command.
                        msSqlCommand->Parameters->AddWithValue("@param1", id);
                        msSqlCommand->Parameters->AddWithValue("@param2", false);

                        // Execute.
                        msSqlCommand->ExecuteNonQuery();
                    }

                    // Close the connection.
                    msSqlConnection->Close();

                    // Refresh.
                    GetData();
                }
            }
            catch (exception& e)
            {

            }
		}

		/// <summary>
		/// Handles the Click event of the button3 control.
		/// </summary>
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Edit a record.
			try
            {
                // The fileds must not be empty and the names must not match.
                if (name1 != 0 && name2 != 0 && relationship != 0 && name1 != name2)
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1->CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int::Parse(dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex]->Cells["Column1"]->Value->ToString());

                        // Open a connection to the database.
                        SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                        msSqlConnection->Open();

                        // Update the values of the selected item.
                        SqlCommand^ msSqlCommand = gcnew SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET Person1 = @param2, Relationship = @param3, Person2 = @param4 WHERE Id = @param1", msSqlConnection);

                        // Fill the values of the command.
                        msSqlCommand->Parameters->AddWithValue("@param1", id);
                        msSqlCommand->Parameters->AddWithValue("@param2", name1);
                        msSqlCommand->Parameters->AddWithValue("@param3", relationship);
                        msSqlCommand->Parameters->AddWithValue("@param4", name2);

                        // Execute.
                        msSqlCommand->ExecuteNonQuery();

                        // Close the connection.
                        msSqlConnection->Close();

                        // Refresh.
                        GetData();
                    }
                }
            }
            catch (exception& e)
            {

            }
		}

		/// <summary>
		/// Handles the Click event of the button4 control.
		/// </summary>
		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Delete a record.
			try
            {
                // An item must be selected in the dataGridView.
                if (dataGridView1->CurrentCellAddress.X >= 0)
                {
                    /* Logical Delete */
                    // Get the Id value of the selected item.
                    id = int::Parse(dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex]->Cells["Column1"]->Value->ToString());

                    // Open a connection to the database.
                    SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                    msSqlConnection->Open();

                    // Edit the IsDeleted value to true.
                    SqlCommand^ msSqlCommand = gcnew SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET IsDeleted = @param2 WHERE Id = @param1", msSqlConnection);

                    // Fill the values of the command.
                    msSqlCommand->Parameters->AddWithValue("@param1", id);
                    msSqlCommand->Parameters->AddWithValue("@param2", true);

                    // Execute.
                    msSqlCommand->ExecuteNonQuery();

                    // Close the connection.
                    msSqlConnection->Close();

                    // Refresh.
                    GetData();
                }
            }
			 catch (exception& e)
            {

            }
		}

		/// <summary>
		/// Handles the Click event of the button5 control.
		/// </summary>
		private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Close the Form.
			Close();
		}

		/// <summary>
		/// Handles the SelectedIndexChanged event of the comboBox1 control.
		/// </summary>
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the comboBox Text.
			try
            {
                // Store the comboBox SelectedItem.
                name1 = int::Parse(comboBox1->SelectedItem->ToString());

                // Open a connection to the database.
                SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                msSqlConnection->Open();

                // Get the item from the People table.
				Person^ retVal = gcnew Person();
                SqlCommand^ msSqlCommand = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = @param1", msSqlConnection);

                // Fill the values of the command.
                msSqlCommand->Parameters->AddWithValue("@param1", name1);

                // Execute.
                SqlDataReader^ msSqlDataReader = msSqlCommand->ExecuteReader();

                // Store the item in a Person object.
                while (msSqlDataReader->Read())
                {
                    retVal = gcnew Person(msSqlDataReader->GetInt32(0), msSqlDataReader->GetString(1), msSqlDataReader->GetString(2),
                        msSqlDataReader->GetString(3), msSqlDataReader->GetDateTime(4), msSqlDataReader->GetBoolean(5));
                }

                // Give the helper label the selected value.
                label7->Text = retVal->getName()->ToString();

                // Close the connection.
                msSqlConnection->Close();
            }
            catch (exception& e)
            {

            }
		}

		/// <summary>
		/// Handles the SelectedIndexChanged event of the comboBox2 control.
		/// </summary>
		private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the comboBox Text.
			try
            {
                // Store the comboBox SelectedItem.
                relationship = int::Parse(comboBox2->SelectedItem->ToString());

                // Open a connection to the database.
                SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                msSqlConnection->Open();

                // Get the item from the Relationships table.
				Relationship^ retVal = gcnew Relationship();
                SqlCommand^ msSqlCommand = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships] WHERE Id = @param1", msSqlConnection);

                // Fill the values of the command.
                msSqlCommand->Parameters->AddWithValue("@param1", relationship);

                // Execute.
                SqlDataReader^ msSqlDataReader = msSqlCommand->ExecuteReader();

                // Store the item in a Relationship object.
                while (msSqlDataReader->Read())
                {
                    retVal = gcnew Relationship(msSqlDataReader->GetInt32(0), msSqlDataReader->GetString(1), msSqlDataReader->GetBoolean(2));
                }

                // Give the helper label the selected value.
                label8->Text = retVal->getName()->ToString();

                // Close the connection.
                msSqlConnection->Close();
            }
            catch (exception& e)
            {

            }
		}

		/// <summary>
		/// Handles the SelectedIndexChanged event of the comboBox3 control.
		/// </summary>
		private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the comboBox Text.
			try
            {
                // Store the comboBox SelectedItem.
                name2 = int::Parse(comboBox3->SelectedItem->ToString());

                // Open a connection to the database.
                SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                msSqlConnection->Open();

                // Get the item from the People table.
				Person^ retVal = gcnew Person();
                SqlCommand^ msSqlCommand = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = @param1", msSqlConnection);

                // Fill the values of the command.
                msSqlCommand->Parameters->AddWithValue("@param1", name2);

                // Execute.
                SqlDataReader^ msSqlDataReader = msSqlCommand->ExecuteReader();

                // Store the item in a Person object.
                while (msSqlDataReader->Read())
                {
                    retVal = gcnew Person(msSqlDataReader->GetInt32(0), msSqlDataReader->GetString(1), msSqlDataReader->GetString(2), msSqlDataReader->GetString(3), 
						msSqlDataReader->GetDateTime(4), msSqlDataReader->GetBoolean(5));
                }

                // Give the helper label the selected value.
                label9->Text = retVal->getName()->ToString();

                // Close the connection.
                msSqlConnection->Close();
            }
            catch (exception& e)
            {

            }
		}

		/// <summary>
		/// Handles the Load event of the Form4 control.
		/// </summary>
		private: System::Void Form4_Load(System::Object^  sender, System::EventArgs^  e)
		{
			// Preset values.
			label7->Text = "";
			label8->Text = "";
			label9->Text = "";
			url = "Server=localhost; Database=MsSqlTestDatabase; User id=root; Password=RootUser0123456789;";

			GetData();
		}

		/// <summary>
		/// Handles the CellClick event of the dataGridView1 control.
		/// </summary>
		private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
		{
			// An item must be selected in the dataGridView.
			if (dataGridView1->CurrentCellAddress.X >= 0)
            {
                try
                {
                    // Get the Id value of the selected item.
                    int id = int::Parse(dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex]->Cells["Column1"]->Value->ToString());

                    // Open a connection to the database.
                    SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                    msSqlConnection->Open();

                    // Get the item from the Relations table.
					Relation^ relation = gcnew Relation();
                    SqlCommand^ msSqlCommand = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE Id = @param1", msSqlConnection);

                    // Fill the values of the command.
                    msSqlCommand->Parameters->AddWithValue("@param1", id);

                    // Execute.
                    SqlDataReader^ msSqlDataReader = msSqlCommand->ExecuteReader();

                    // Store it in a Relation object.
                    while (msSqlDataReader->Read())
                    {
                        relation = gcnew Relation(msSqlDataReader->GetInt32(0), msSqlDataReader->GetInt32(1), msSqlDataReader->GetInt32(2),
                            msSqlDataReader->GetInt32(3), msSqlDataReader->GetBoolean(4));
                    }

                    // Give the comboBox SelectedItems the selected values.
                    comboBox1->SelectedItem = relation->getPerson1()->ToString();
                    comboBox2->SelectedItem = relation->getRelationship()->ToString();
                    comboBox3->SelectedItem = relation->getPerson2()->ToString();

                    // Close the connection.
                    msSqlConnection->Close();
                }
                catch (exception& e)
                {
                    // Empty the SelectedItems value.
                    comboBox1->SelectedItem = nullptr;
                    comboBox2->SelectedItem = nullptr;
                    comboBox3->SelectedItem = nullptr;
                }
            }
            else
            {
                // Empty the SelectedItems value.
                comboBox1->SelectedItem = nullptr;
                comboBox2->SelectedItem = nullptr;
                comboBox3->SelectedItem = nullptr;
            }
		}

		/// <summary>
		/// Gets the data.
		/// </summary>
		private: System::Void GetData()
		{
			try
            {
                // Clear the existing items.
                dataGridView1->Rows->Clear();
                comboBox1->Items->Clear();
                comboBox2->Items->Clear();
                comboBox3->Items->Clear();

                // Open a connection to the database.
                SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                msSqlConnection->Open();

                // Get the items from the People table.
                List<Person^>^ people = gcnew List<Person^>();
                SqlCommand^ msSqlCommand1 = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[People]", msSqlConnection);

                // Execute.
                SqlDataReader^ msSqlDataReader1 = msSqlCommand1->ExecuteReader();

                // Store the items in a Person list.
                while (msSqlDataReader1->Read())
                {
                    people->Add(gcnew Person(msSqlDataReader1->GetInt32(0), msSqlDataReader1->GetString(1), msSqlDataReader1->GetString(2),
                        msSqlDataReader1->GetString(3), msSqlDataReader1->GetDateTime(4), msSqlDataReader1->GetBoolean(5)));
                }

                // Close the dataReader.
                msSqlDataReader1->Close();

                // Get the items from the Relationships table.
                List<Relationship^>^ relationships = gcnew List<Relationship^>();
                SqlCommand^ msSqlCommand2 = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships]", msSqlConnection);

                // Execute.
                SqlDataReader^ msSqlDataReader2 = msSqlCommand2->ExecuteReader();

                // Store the items in a Relationship list.
                while (msSqlDataReader2->Read())
                {
                    relationships->Add(gcnew Relationship(msSqlDataReader2->GetInt32(0), msSqlDataReader2->GetString(1), msSqlDataReader2->GetBoolean(2)));
                }

                // Close the dataReader.
                msSqlDataReader2->Close();

                // Get items from the Relations table.
                List<Relation^>^ relations = gcnew List<Relation^>();
                SqlCommand^ msSqlCommand = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE IsDeleted = 0", msSqlConnection);

                // Execute.
                SqlDataReader^ msSqlDataReader = msSqlCommand->ExecuteReader();

                // Store the items in a Relation list.
                while (msSqlDataReader->Read())
                {
                    relations->Add(gcnew Relation(msSqlDataReader->GetInt32(0), msSqlDataReader->GetInt32(1), msSqlDataReader->GetInt32(2),
                        msSqlDataReader->GetInt32(3), msSqlDataReader->GetBoolean(4)));
                }

                // Close the dataReader and the connection.
                msSqlDataReader->Close();
                msSqlConnection->Close();

                // Fill the dataGridView rows with the values of the Relations table.
                for each (Relation^ oneItem in relations)
                {
                    DataGridViewRow^ row = gcnew DataGridViewRow();
                    DataGridViewCell^ cell1 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell2 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell3 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell4 = gcnew DataGridViewTextBoxCell();

                    cell1->Value = oneItem->getId()->ToString();

                    // Substitute the Person1 and Person2 ids with their names.
                    for each (Person^ onePerson in people)
                    {
                        if (oneItem->getPerson1()->ToString() == onePerson->getId()->ToString())
                        {
                            cell2->Value = onePerson->getName()->ToString();
                        }

                        if (oneItem->getPerson2()->ToString() == onePerson->getId()->ToString())
                        {
                            cell4->Value = onePerson->getName()->ToString();
                        }
                    }

                    // Substitute the Relationship ids with their names.
                    for each (Relationship^ oneRelationship in relationships)
                    {
                        if (oneItem->getRelationship()->ToString() == oneRelationship->getId()->ToString())
                        {
                            cell3->Value = oneRelationship->getName()->ToString();
                        }
                    }

                    row->Cells->Add(cell1);
                    row->Cells->Add(cell2);
                    row->Cells->Add(cell3);
                    row->Cells->Add(cell4);

                    dataGridView1->Rows->Add(row);
                }

                // Fill the comboBox items with the values of the People table.
                for each (Person^ oneItem in people)
                {
                    if (oneItem->getIsDeleted()->ToString()->ToLower() == "false")
                    {
                        comboBox1->Items->Add(oneItem->getId()->ToString());
                        comboBox3->Items->Add(oneItem->getId()->ToString());
                    }
                }

                // Fill the comboBox items with the values of the Relationships table.
                for each (Relationship^ oneItem in relationships)
                {
                    if (oneItem->getIsDeleted()->ToString()->ToLower() == "false")
                    {
                        comboBox2->Items->Add(oneItem->getId()->ToString());
                    }
                }
            }
			catch (exception& e)
            {

            }
		}

		#pragma endregion
	};
}
