#pragma once
#include <exception>
#include "Relationship.h"

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
	/// Interaction logic for Form3.
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
		#pragma region Fields

		// The database connectionString.
		private: String^ url;

        // The id value.
		private: int id;

        // The name value.
		private: String^ name;

		#pragma endregion

		#pragma region Constructors

		/// <summary>
        /// Initializes a new instance of the <see cref="Form3"/> class.
        /// </summary>
		public: Form3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~Form3()
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
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(621, 547);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Close";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form3::button5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(441, 547);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"List";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(441, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 190);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modify:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(78, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form3::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Type:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(168, 161);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form3::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(87, 161);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Edit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form3::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form3::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Location = System::Drawing::Point(2, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(433, 567);
			this->dataGridView1->TabIndex = 8;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form3::dataGridView1_CellClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Type";
			this->Column2->Name = L"Column2";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 572);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form3";
			this->Text = L"Relationships";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
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
                // The field must not be empty.
                if (!String::IsNullOrEmpty(name))
                {
                    bool^ matchFound = false;
                    bool^ deletedFound = false;
                    id = 0;

                    // Open a connection to the database.
                    SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                    msSqlConnection->Open();

                    // Get the items from the Relationships table.
                    SqlCommand^ msSqlCommand1 = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships]", msSqlConnection);

                    // Execute.
                    SqlDataReader^ msSqlDataReader1 = msSqlCommand1->ExecuteReader();

                    // Get the number of the existing items.
                    while (msSqlDataReader1->Read())
                    {
                        id += 1;

                        // Check if the new item already exists.
                        if (msSqlDataReader1->GetString(1) == name && !matchFound && msSqlDataReader1->GetBoolean(3) == false)
                        {
                            matchFound = true;

                            break;
                        }

                        // Check if the new item already exists.
                        if (msSqlDataReader1->GetString(1) == name && !deletedFound && msSqlDataReader1->GetBoolean(3) == true)
                        {
                            deletedFound = true;
                            id = msSqlDataReader1->GetInt32(0);

                            break;
                        }
                    }

                    // Close the dataReader.
                    msSqlDataReader1->Close();

                    // If no match was found among the active items.
                    if (matchFound->ToString()->ToLower() == "false")
                    {
                        // Add a record if no deleted item found else restore the deleted item.
                        if (deletedFound->ToString()->ToLower() == "false")
                        {
                            // Add new item to the Relationship table.
                            SqlCommand^ msSqlCommand = gcnew SqlCommand("INSERT INTO [MsSqlTestDatabase].[dbo].[Relationships] (Id, Name, IsDeleted) VALUES (@param1, @param2, @param3)", msSqlConnection);

                            // Fill the values of the command.
                            msSqlCommand->Parameters->AddWithValue("@param1", id + 1);
                            msSqlCommand->Parameters->AddWithValue("@param2", name);
                            msSqlCommand->Parameters->AddWithValue("@param3", false);

                            // Execute.
                            msSqlCommand->ExecuteNonQuery();
                        }
                        else
                        {
                            // Edit the IsDeleted value to false.
                            SqlCommand^ msSqlCommand = gcnew SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET IsDeleted = @param2 WHERE Id = @param1", msSqlConnection);

                            // Fill the values of the command.
                            msSqlCommand->Parameters->AddWithValue("@param1", id);
                            msSqlCommand->Parameters->AddWithValue("@param2", false);

                            // Execute.
                            msSqlCommand->ExecuteNonQuery();
                        }
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
                // The field must not be empty.
                if (!String::IsNullOrEmpty(name))
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1->CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int::Parse(dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex]->Cells["Column1"]->Value->ToString());

                        // Open a connection to the database.
                        SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                        msSqlConnection->Open();

                        // Update the values in the Relationships table.
                        SqlCommand^ msSqlCommand = gcnew SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET Name = @param2 WHERE Id = @param1", msSqlConnection);

                        // Fill the values of the command.
                        msSqlCommand->Parameters->AddWithValue("@param1", id);
                        msSqlCommand->Parameters->AddWithValue("@param2", name);

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
                    SqlCommand^ msSqlCommand = gcnew SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET IsDeleted = @param2 WHERE Id = @param1", msSqlConnection);

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
		/// Handles the TextChanged event of the textBox1 control.
		/// </summary>
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			// Give the field the textBox Text.
			name = textBox1->Text;
		}

		/// <summary>
		/// Handles the Load event of the Form3 control.
		/// </summary>
		private: System::Void Form3_Load(System::Object^  sender, System::EventArgs^  e)
		{
			// Preset values.
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
                    // Get the selected row.
                    DataGridViewRow^ selectedRow = dataGridView1->Rows[dataGridView1->SelectedCells[0]->RowIndex];

                    // Give the textBox Text the selected value.
                    textBox1->Text = selectedRow->Cells["Column2"]->Value->ToString();
                }
                catch (exception& e)
                {
                    // Empty the textBox Text.
                    textBox1->Text = "";
                }
            }
            else
            {
                // Empty the textBox Text.
                textBox1->Text = "";
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
                SqlConnection^ msSqlConnection = gcnew SqlConnection(url);
                msSqlConnection->Open();

                // Get the items from the Relationships table.
                List<Relationship^>^ relationships = gcnew List<Relationship^>();
                SqlCommand^ msSqlCommand = gcnew SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships] WHERE IsDeleted = 0", msSqlConnection);

                // Execute.
                SqlDataReader^ msSqlDataReader = msSqlCommand->ExecuteReader();

                // Store the items in a Relationship list.
                while (msSqlDataReader->Read())
                {
                    relationships->Add(gcnew Relationship(msSqlDataReader->GetInt32(0), msSqlDataReader->GetString(1), msSqlDataReader->GetBoolean(2)));
                }

                // Close the dataReader and the connection.
                msSqlDataReader->Close();
                msSqlConnection->Close();

                // Fill the dataGridView rows with the values of the Relationships table.
                for each (Relationship^ oneItem in relationships)
                {
                    DataGridViewRow^ row = gcnew DataGridViewRow();
                    DataGridViewCell^ cell1 = gcnew DataGridViewTextBoxCell();
                    DataGridViewCell^ cell2 = gcnew DataGridViewTextBoxCell();

                    cell1->Value = oneItem->getId()->ToString();
                    cell2->Value = oneItem->getName();

                    row->Cells->Add(cell1);
                    row->Cells->Add(cell2);

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
