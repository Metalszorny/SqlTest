#pragma once
#include <exception>
#include "Person.h"

namespace MySqlTest
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Linq;
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace System::Windows::Forms;
	using namespace MySql::Data;
	using namespace MySql::Data::MySqlClient;
	using namespace std;

	/// <summary>
	/// Interaction logic for Form2.
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
		#pragma region Fields

		// The database connectionString.
		private: String^ url;

        // The id value.
		private: int id;

        // The name value.
		private: String^ name;

        // The mothername value.
		private: String^ mothername;

        // The location value.
		private: String^ location;

        // The birthdate value.
		private: String^ birthdate;

		#pragma endregion

		#pragma region Constructors

		/// <summary>
        /// Initializes a new instance of the <see cref="Form2"/> class.
        /// </summary>
		public: Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~Form2()
		{
			if (components)
			{
				delete components;
			}
		}

		#pragma endregion

		#pragma region GUI

		private: System::Windows::Forms::Button^  button5;
		protected: 
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::GroupBox^  groupBox1;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::TextBox^  textBox4;
		private: System::Windows::Forms::TextBox^  textBox3;
		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;

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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(621, 547);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Close";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form2::button5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(441, 547);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"List";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(441, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 190);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modify:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Birthdate:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Location:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Mothername:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(78, 97);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(165, 20);
			this->textBox4->TabIndex = 8;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form2::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(78, 71);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(165, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form2::textBox3_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(78, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(165, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form2::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(78, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form2::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Name:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(168, 161);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(87, 161);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Edit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5});
			this->dataGridView1->Location = System::Drawing::Point(2, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(433, 567);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form2::dataGridView1_CellClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Name";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Mothername";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Location";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Birthdate";
			this->Column5->Name = L"Column5";
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 572);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form2";
			this->Text = L"People";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
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
				// The fields must not be empty.
				if (!String::IsNullOrEmpty(name) && !String::IsNullOrEmpty(mothername) && !String::IsNullOrEmpty(location) && !String::IsNullOrEmpty(birthdate))
                {
					id = 0;
                    bool^ matchFound = false;

					// Open a connection to the database.
                    MySqlConnection^ mySqlConnection = gcnew MySqlConnection(url);
                    mySqlConnection->Open();

                    // Get the items from the People table.
                    MySqlCommand^ mySqlCommand1 = gcnew MySqlCommand("SELECT * FROM MySqlTestDatabase.People", mySqlConnection);

                    // Execute.
                    MySqlDataReader^ mySqlDataReader1 = mySqlCommand1->ExecuteReader();

                    // Get the number of the existing items.
                    while (mySqlDataReader1->Read())
                    {
                        id += 1;

						// Search for deleted matches.
                        if (!matchFound &&
                            mySqlDataReader1->GetString("Name") == name &&
                            mySqlDataReader1->GetString("Mothername") == mothername &&
                            mySqlDataReader1->GetString("Location") == location &&
                            mySqlDataReader1->GetDateTime("Birthdate") == DateTime::Parse(birthdate) &&
                            mySqlDataReader1->GetBoolean("IsDeleted") == true)
                        {
                            matchFound = true;
                            id = mySqlDataReader1->GetInt32("Id");

                            break;
                        }
					}

					// Close the dataReader.
                    mySqlDataReader1->Close();

                    // Add a new item if no match exists or restore the deleted item.
                    if (matchFound->ToString()->ToLower() == "false")
                    {
						// Add new item to the People table.
                        MySqlCommand^ mySqlCommand = gcnew MySqlCommand("INSERT INTO MySqlTestDatabase.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (@param1, @param2, @param3, @param4, @param5, @param6)", mySqlConnection);

                        // Fill the values of the command.
                        mySqlCommand->Parameters->AddWithValue("@param1", id + 1);
                        mySqlCommand->Parameters->AddWithValue("@param2", name);
                        mySqlCommand->Parameters->AddWithValue("@param3", mothername);
                        mySqlCommand->Parameters->AddWithValue("@param4", location);
                        mySqlCommand->Parameters->AddWithValue("@param5", DateTime::Parse(birthdate));
                        mySqlCommand->Parameters->AddWithValue("@param6", false);

                        // Execute.
                        mySqlCommand->ExecuteNonQuery();
					}
					else
                    {
                        // Edit the IsDeleted value to false.
                        MySqlCommand^ mySqlCommand = gcnew MySqlCommand("UPDATE MySqlTestDatabase.People SET IsDeleted = @param2 WHERE Id = @param1", mySqlConnection);

                        // Fill the values of the command.
                        mySqlCommand->Parameters->AddWithValue("@param1", id);
                        mySqlCommand->Parameters->AddWithValue("@param2", false);

                        // Execute.
                        mySqlCommand->ExecuteNonQuery();
                    }

                    // Close the connection.
                    mySqlConnection->Close();

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
				// The fields must not be empty.
                if (!String::IsNullOrEmpty(name) && !String::IsNullOrEmpty(mothername) && !String::IsNullOrEmpty(location) && !String::IsNullOrEmpty(birthdate))
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1->CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int::Parse(dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex]->Cells["Column1"]->Value->ToString());

                        // Open a connection to the database.
                        MySqlConnection^ mySqlConnection = gcnew MySqlConnection(url);
                        mySqlConnection->Open();

                        // Update the values in the People table.
                        MySqlCommand^ mySqlCommand = gcnew MySqlCommand("UPDATE MySqlTestDatabase.People SET Name = @param2, Mothername = @param3, Location = @param4, BirthDate = @param5 WHERE Id = @param1", mySqlConnection);

                        // Fill the values of the command.
                        mySqlCommand->Parameters->AddWithValue("@param1", id);
                        mySqlCommand->Parameters->AddWithValue("@param2", name);
                        mySqlCommand->Parameters->AddWithValue("@param3", mothername);
                        mySqlCommand->Parameters->AddWithValue("@param4", location);
                        mySqlCommand->Parameters->AddWithValue("@param5", DateTime::Parse(birthdate));

                        // Execute.
                        mySqlCommand->ExecuteNonQuery();

                        // Close the connection.
                        mySqlConnection->Close();

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
                    MySqlConnection^ mySqlConnection = gcnew MySqlConnection(url);
                    mySqlConnection->Open();

                    // Edit the IsDeleted value to true.
                    MySqlCommand^ mySqlCommand = gcnew MySqlCommand("UPDATE MySqlTestDatabase.People SET IsDeleted = @param2 WHERE Id = @param1", mySqlConnection);

                    // Fill the values of the command.
                    mySqlCommand->Parameters->AddWithValue("@param1", id);
                    mySqlCommand->Parameters->AddWithValue("@param2", true);

                    // Execute.
                    mySqlCommand->ExecuteNonQuery();

                    // Close the connection.
                    mySqlConnection->Close();

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
		/// Handles the TextChanged event of the textBox1 control.
		/// </summary>
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the textBox Text.
            name = textBox1->Text;
		}

		/// <summary>
		/// Handles the TextChanged event of the textBox2 control.
		/// </summary>
		private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the textBox Text.
            mothername = textBox2->Text;
		}

		/// <summary>
		/// Handles the TextChanged event of the textBox3 control.
		/// </summary>
		private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the textBox Text.
            location = textBox3->Text;
		}

		/// <summary>
		/// Handles the TextChanged event of the textBox4 control.
		/// </summary>
		private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the textBox Text.
            birthdate = textBox4->Text;
		}

		/// <summary>
		/// Handles the Load event of the Form2 control.
		/// </summary>
		private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e)
		{
			// Preset values.
			url = "SERVER=localhost;DATABASE=MySqlTestDatabase;UID=root;PASSWORD=root;";
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
                    // Get the selected row.
                    DataGridViewRow^ selectedRow = dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex];

                    // Give the textBox Texts the selected values.
                    textBox1->Text = selectedRow->Cells["Column2"]->Value->ToString();
                    textBox2->Text = selectedRow->Cells["Column3"]->Value->ToString();
                    textBox3->Text = selectedRow->Cells["Column4"]->Value->ToString();
                    textBox4->Text = selectedRow->Cells["Column5"]->Value->ToString()->Split(' ')[0];
                }
                catch (exception& e)
                {
                    // Empty the textBox Texts.
                    textBox1->Text = "";
                    textBox2->Text = "";
                    textBox3->Text = "";
                    textBox4->Text = "";
                }
            }
            else
            {
                // Empty the textBox Texts.
                textBox1->Text = "";
                textBox2->Text = "";
                textBox3->Text = "";
                textBox4->Text = "";
            }
		}

		/// <summary>
		/// Gets the data.
		/// </summary>
		private: System::Void GetData()
		{
			try
			{
				// Clear existing items.
				dataGridView1->Rows->Clear();

				// Open a connection to the database.
                MySqlConnection^ mySqlConnection = gcnew MySqlConnection(url);
				mySqlConnection->Open();

				// Get the items from the People table.
				List<Person^>^ people = gcnew List<Person^>();
                MySqlCommand^ mySqlCommand = gcnew MySqlCommand("SELECT * FROM MySqlTestDatabase.People WHERE IsDeleted = 0", mySqlConnection);

				// Execute.
				MySqlDataReader^ mySqlDataReader = mySqlCommand->ExecuteReader();

				// Store the items in a Person list.
				while (mySqlDataReader->Read())
                {
					people->Add(gcnew Person(mySqlDataReader->GetInt32("Id"), mySqlDataReader->GetString("Name"), mySqlDataReader->GetString("Mothername"), 
						mySqlDataReader->GetString("Location"), mySqlDataReader->GetDateTime("Birthdate"), mySqlDataReader->GetBoolean("IsDeleted")));
				}

				// Close the datareader and the connection.
				mySqlDataReader->Close();
                mySqlConnection->Close();

				// Fill the dataGridView rows with the values of the People table.
				for each (Person^ oneItem in people)
                {
                    DataGridViewRow^ row = gcnew DataGridViewRow();
                    DataGridViewCell^ cell1 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell2 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell3 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell4 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell5 = gcnew DataGridViewTextBoxCell();

                    cell1->Value = oneItem->getId()->ToString();
                    cell2->Value = oneItem->getName();
                    cell3->Value = oneItem->getMothername();
                    cell4->Value = oneItem->getLocation();
                    cell5->Value = oneItem->getBirthdate()->ToString();

                    row->Cells->Add(cell1);
                    row->Cells->Add(cell2);
                    row->Cells->Add(cell3);
                    row->Cells->Add(cell4);
                    row->Cells->Add(cell5);

                    dataGridView1->Rows->Add(row);
                }
			}
			catch (exception& e)
			{

			}
		}

		#pragma endregion
	};
}
