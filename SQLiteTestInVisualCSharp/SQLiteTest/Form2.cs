﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SQLite;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SQLiteTest
{
    /// <summary>
    /// Interaction logic for Form2.
    /// </summary>
    public partial class Form2 : Form
    {
        #region Fields

        // The database connectionString.
        string url = @"Data Source=..\..\..\Database\SQLiteTestDatabase.db";

        // The id value.
        private int id;

        // The name value.
        private string name;

        // The mothername value.
        private string mothername;

        // The location value.
        private string location;

        // The birthdate value.
        private string birthdate;

        #endregion Fields

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="Form2"/> class.
        /// </summary>
        public Form2()
        {
            InitializeComponent();
        }
		
		/// <summary>
        /// Destroys the instance of the <see cref="Form2"/> class.
        /// </summary>
        ~Form2()
        { }

        #endregion Constructors

        #region Methods

        /// <summary>
        /// Handles the Click event of the button1 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button1_Click(object sender, EventArgs e)
        {
            // List the records.
            GetData();
        }

        /// <summary>
        /// Handles the Click event of the button2 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button2_Click(object sender, EventArgs e)
        {
            // Add a record.
            try
            {
                // The fields must not be empty.
                if (!string.IsNullOrEmpty(name) && !string.IsNullOrEmpty(mothername) && !string.IsNullOrEmpty(location) && !string.IsNullOrEmpty(birthdate))
                {
                    id = 0;
                    bool matchFound = false;

                    // Open a connection to the database.
                    SQLiteConnection sqliteConnection = new SQLiteConnection(url);
                    sqliteConnection.Open();

                    // Get the items from the People table.
                    SQLiteCommand sqliteCommand1 = new SQLiteCommand("SELECT * FROM People", sqliteConnection);

                    // Execute.
                    SQLiteDataReader sqliteDataReader1 = sqliteCommand1.ExecuteReader();

                    // Store the items in a Person list.
                    while (sqliteDataReader1.Read())
                    {
                        id++;

                        // Search for a deleted maching item.
                        if (!matchFound &&
                            sqliteDataReader1.GetString(1) == name &&
                            sqliteDataReader1.GetString(2) == mothername &&
                            sqliteDataReader1.GetString(3) == location &&
                            sqliteDataReader1.GetDateTime(4) == DateTime.Parse(birthdate) &&
                            sqliteDataReader1.GetBoolean(5) == true)
                        {
                            matchFound = true;
                            id = sqliteDataReader1.GetInt32(0);

                            break;
                        }
                    }

                    // Close the datareader and the connection.
                    sqliteDataReader1.Close();

                    // Add a new item if no deleted was found else restore the deleted item.
                    if (!matchFound)
                    {
                        // Add new item to the People table.
                        SQLiteCommand sqliteCommand = new SQLiteCommand("INSERT INTO People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (@param1, @param2, @param3, @param4, @param5, @param6)", sqliteConnection);

                        // Fill the values of the command.
                        sqliteCommand.Parameters.AddWithValue("@param1", id + 1);
                        sqliteCommand.Parameters.AddWithValue("@param2", name);
                        sqliteCommand.Parameters.AddWithValue("@param3", mothername);
                        sqliteCommand.Parameters.AddWithValue("@param4", location);
                        sqliteCommand.Parameters.AddWithValue("@param5", birthdate.Split(' ')[0][birthdate.Split(' ')[0].Length - 1] != '.' ? birthdate.Split(' ')[0].Replace(".", "-") : birthdate.Split(' ')[0].Remove(birthdate.Split(' ')[0].Length - 1).Replace(".", "-"));
                        sqliteCommand.Parameters.AddWithValue("@param6", false);

                        // Execute.
                        sqliteCommand.ExecuteNonQuery();
                    }
                    else
                    {
                        // Edit the IsDeleted value to false.
                        SQLiteCommand sqliteCommand = new SQLiteCommand("UPDATE People SET IsDeleted = @param2 WHERE Id = @param1", sqliteConnection);

                        // Fill the values of the command.
                        sqliteCommand.Parameters.AddWithValue("@param1", id);
                        sqliteCommand.Parameters.AddWithValue("@param2", false);

                        // Execute.
                        sqliteCommand.ExecuteNonQuery();
                    }

                    // Close the connection.
                    sqliteConnection.Close();

                    // Refresh.
                    GetData();
                }
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the Click event of the button3 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button3_Click(object sender, EventArgs e)
        {
            // Edit a record.
            try
            {
                // The fields must not be empty.
                if (!string.IsNullOrEmpty(name) && !string.IsNullOrEmpty(mothername) && !string.IsNullOrEmpty(location) && !string.IsNullOrEmpty(birthdate))
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1.CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                        // Open a connection to the database.
                        SQLiteConnection sqliteConnection = new SQLiteConnection(url);
                        sqliteConnection.Open();

                        // Update the values in the People table.
                        SQLiteCommand sqliteCommand = new SQLiteCommand("UPDATE People SET Name = @param2, Mothername = @param3, Location = @param4, BirthDate = @param5 WHERE Id = @param1", sqliteConnection);

                        // Fill the values of the command.
                        sqliteCommand.Parameters.AddWithValue("@param1", id);
                        sqliteCommand.Parameters.AddWithValue("@param2", name);
                        sqliteCommand.Parameters.AddWithValue("@param3", mothername);
                        sqliteCommand.Parameters.AddWithValue("@param4", location);
                        sqliteCommand.Parameters.AddWithValue("@param5", birthdate.Split(' ')[0].Remove(birthdate.Split(' ')[0].Length - 1).Replace(".", "-"));

                        // Execute.
                        sqliteCommand.ExecuteNonQuery();

                        // Close the connection.
                        sqliteConnection.Close();

                        // Refresh.
                        GetData();
                    }
                }
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the Click event of the button4 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button4_Click(object sender, EventArgs e)
        {
            // Delete a record.
            try
            {
                // An item must be selected in the dataGridView.
                if (dataGridView1.CurrentCellAddress.X >= 0)
                {
                    /* Logical Delete */
                    // Get the Id value of the selected item.
                    id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                    // Open a connection to the database.
                    SQLiteConnection sqliteConnection = new SQLiteConnection(url);
                    sqliteConnection.Open();

                    // Edit the IsDeleted value to true.
                    SQLiteCommand sqliteCommand = new SQLiteCommand("UPDATE People SET IsDeleted = @param2 WHERE Id = @param1", sqliteConnection);

                    // Fill the values of the command.
                    sqliteCommand.Parameters.AddWithValue("@param1", id);
                    sqliteCommand.Parameters.AddWithValue("@param2", true);

                    // Execute.
                    sqliteCommand.ExecuteNonQuery();

                    // Close the connection.
                    sqliteConnection.Close();

                    // Refresh.
                    GetData();
                }
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the Click event of the button5 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button5_Click(object sender, EventArgs e)
        {
            // Close the Form.
            Close();
        }

        /// <summary>
        /// Handles the TextChanged event of the textBox1 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            // Give the field the textBox Text.
            name = textBox1.Text;
        }

        /// <summary>
        /// Handles the TextChanged event of the textBox2 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            // Give the field the textBox Text.
            mothername = textBox2.Text;
        }

        /// <summary>
        /// Handles the TextChanged event of the textBox3 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            // Give the field the textBox Text.
            location = textBox3.Text;
        }

        /// <summary>
        /// Handles the TextChanged event of the textBox4 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            // Give the field the textBox Text.
            birthdate = textBox4.Text;
        }

        /// <summary>
        /// Handles the Loaded event of the Form2 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void Form2_Load(object sender, EventArgs e)
        {
            // Preset values.
            GetData();
        }

        /// <summary>
        /// Handles the CellClick event of the dataGridView1 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="DataGridViewCellEventArgs"/> instance containing the event data.</param>
        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            // An item must be selected in the dataGridView.
            if (dataGridView1.CurrentCellAddress.X >= 0)
            {
                try
                {
                    // Get the selected row.
                    DataGridViewRow selectedRow = dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex];

                    // Give the textBox Texts the selected values.
                    textBox1.Text = selectedRow.Cells["Column2"].Value.ToString();
                    textBox2.Text = selectedRow.Cells["Column3"].Value.ToString();
                    textBox3.Text = selectedRow.Cells["Column4"].Value.ToString();
                    textBox4.Text = selectedRow.Cells["Column5"].Value.ToString().Split(' ')[0];
                }
                catch
                {
                    // Empty the textBox Texts.
                    textBox1.Text = "";
                    textBox2.Text = "";
                    textBox3.Text = "";
                    textBox4.Text = "";
                }
            }
            else
            {
                // Empty the textBox Texts.
                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
                textBox4.Text = "";
            }
        }

        /// <summary>
        /// Gets the Data.
        /// </summary>
        private void GetData()
        {
            try
            {
                // Clear existing items.
                dataGridView1.Rows.Clear();

                // Open a connection to the database.
                SQLiteConnection sqliteConnection = new SQLiteConnection(url);
                sqliteConnection.Open();

                // Get the items from the People table.
                List<Person> people = new List<Person>();
                SQLiteCommand sqliteCommand = new SQLiteCommand("SELECT * FROM People WHERE IsDeleted = 0", sqliteConnection);

                // Execute.
                SQLiteDataReader sqliteDataReader = sqliteCommand.ExecuteReader();

                // Store the items in a Person list.
                while (sqliteDataReader.Read())
                {
                    people.Add(new Person(sqliteDataReader.GetInt32(0), sqliteDataReader.GetString(1), sqliteDataReader.GetString(2), sqliteDataReader.GetString(3),
                        sqliteDataReader.GetDateTime(4), sqliteDataReader.GetBoolean(5)));
                }

                // Close the datareader and the connection.
                sqliteDataReader.Close();
                sqliteConnection.Close();

                // Fill the dataGridView rows with the values of the People table.
                foreach (var oneItem in people)
                {
                    DataGridViewRow row = new DataGridViewRow();
                    DataGridViewCell cell1 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell2 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell3 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell4 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell5 = new DataGridViewTextBoxCell();

                    cell1.Value = oneItem.Id.ToString();
                    cell2.Value = oneItem.Name;
                    cell3.Value = oneItem.Mothername;
                    cell4.Value = oneItem.Location;
                    cell5.Value = oneItem.Birthdate.ToString();

                    row.Cells.Add(cell1);
                    row.Cells.Add(cell2);
                    row.Cells.Add(cell3);
                    row.Cells.Add(cell4);
                    row.Cells.Add(cell5);

                    dataGridView1.Rows.Add(row);
                }
            }
            catch
            {

            }
        }

        #endregion Methods
    }
}
