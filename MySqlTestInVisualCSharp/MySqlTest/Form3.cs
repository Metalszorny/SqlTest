using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using MySql.Data.MySqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MySqlTest
{
    /// <summary>
    /// Interaction logic for Form3.
    /// </summary>
    public partial class Form3 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = "SERVER=localhost;DATABASE=MySqlTestDatabase;UID=root;PASSWORD=root;";

        // The id value.
        private int id;

        // The name value.
        private string name;

        #endregion Fields

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="Form3"/> class.
        /// </summary>
        public Form3()
        {
            InitializeComponent();
        }
		
		/// <summary>
        /// Destroys the instance of the <see cref="Form3"/> class.
        /// </summary>
        ~Form3()
        { }

        #endregion Constructors

        #region Methods

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
                MySqlConnection mySqlConnection = new MySqlConnection(url);
                mySqlConnection.Open();

                // Get the items from the Relationships table.
                List<Relationship> relationships = new List<Relationship>();
                MySqlCommand mySqlCommand = new MySqlCommand("SELECT * FROM MySqlTestDatabase.Relationships WHERE IsDeleted = 0", mySqlConnection);

                // Execute.
                MySqlDataReader mySqlDataReader = mySqlCommand.ExecuteReader();

                // Store the items in a Relationship list.
                while (mySqlDataReader.Read())
                {
                    relationships.Add(new Relationship(mySqlDataReader.GetInt32(0), mySqlDataReader.GetString(1), mySqlDataReader.GetBoolean(2)));
                }

                // Close the dataReader and the connection.
                mySqlDataReader.Close();
                mySqlConnection.Close();

                // Fill the dataGridView rows with the values of the Relationships table.
                foreach (var oneItem in relationships)
                {
                    DataGridViewRow row = new DataGridViewRow();
                    DataGridViewCell cell1 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell2 = new DataGridViewTextBoxCell();

                    cell1.Value = oneItem.Id.ToString();
                    cell2.Value = oneItem.Name;

                    row.Cells.Add(cell1);
                    row.Cells.Add(cell2);

                    dataGridView1.Rows.Add(row);
                }
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the Load event of the Form3 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void Form3_Load(object sender, EventArgs e)
        {
            //Preset values.
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
                // The field must not be empty.
                if (!string.IsNullOrEmpty(name))
                {
                    id = 0;
                    bool matchFound = false;
                    bool deletedFound = false;

                    // Open a connection to the database.
                    MySqlConnection mySqlConnection = new MySqlConnection(url);
                    mySqlConnection.Open();

                    // Get the items from the Relationships table.
                    MySqlCommand mySqlCommand1 = new MySqlCommand("SELECT * FROM MySqlTestDatabase.Relationships", mySqlConnection);

                    // Execute.
                    MySqlDataReader mySqlDataReader1 = mySqlCommand1.ExecuteReader();

                    // Get the number of the existing items.
                    while (mySqlDataReader1.Read())
                    {
                        id++;

                        // Check if the new item already exists.
                        if (mySqlDataReader1.GetString("Name") == name && !matchFound && mySqlDataReader1.GetBoolean("IsDeleted") == false)
                        {
                            matchFound = true;

                            break;
                        }

                        // Check if a deleted already exists.
                        if (mySqlDataReader1.GetString("Name") == name && !deletedFound && mySqlDataReader1.GetBoolean("IsDeleted") == true)
                        {
                            deletedFound = true;
                            id = mySqlDataReader1.GetInt32("Id");

                            break;
                        }
                    }

                    // Close the dataReader.
                    mySqlDataReader1.Close();

                    // If no match was found.
                    if (!matchFound)
                    {
                        // Add a new item if no deleted match found else restore the deleted item.
                        if (!deletedFound)
                        {
                            // Add new item to the Relationship table.
                            MySqlCommand mySqlCommand = new MySqlCommand("INSERT INTO MySqlTestDatabase.Relationships (Id, Name, IsDeleted) VALUES (@param1, @param2, @param3)", mySqlConnection);

                            // Fill the values of the command.
                            mySqlCommand.Parameters.AddWithValue("@param1", id + 1);
                            mySqlCommand.Parameters.AddWithValue("@param2", name);
                            mySqlCommand.Parameters.AddWithValue("@param3", false);

                            // Execute.
                            mySqlCommand.ExecuteNonQuery();
                        }
                        else
                        {
                            // Edit the IsDeleted value to false.
                            MySqlCommand mySqlCommand = new MySqlCommand("UPDATE MySqlTestDatabase.Relationships SET IsDeleted = @param2 WHERE Id = @param1", mySqlConnection);

                            // Fill the values of the command.
                            mySqlCommand.Parameters.AddWithValue("@param1", id);
                            mySqlCommand.Parameters.AddWithValue("@param2", false);

                            // Execute.
                            mySqlCommand.ExecuteNonQuery();
                        }
                    }

                    // Close the connection.
                    mySqlConnection.Close();

                    // Refresh.
                    GetData();
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
                    MySqlConnection mySqlConnection = new MySqlConnection(url);
                    mySqlConnection.Open();

                    // Edit the IsDeleted value to true.
                    MySqlCommand mySqlCommand = new MySqlCommand("UPDATE MySqlTestDatabase.Relationships SET IsDeleted = @param2 WHERE Id = @param1", mySqlConnection);

                    // Fill the values of the command.
                    mySqlCommand.Parameters.AddWithValue("@param1", id);
                    mySqlCommand.Parameters.AddWithValue("@param2", true);

                    // Execute.
                    mySqlCommand.ExecuteNonQuery();

                    // Close the connection.
                    mySqlConnection.Close();

                    // Refresh.
                    GetData();
                }
            }
            catch
            {

            }
        }

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
        /// Handles the CellClick event of the dataGridView1 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="DateGridViewCellEventArgs"/> instance containing the event data.</param>
        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            // An item must be selected in the dataGridView.
            if (dataGridView1.CurrentCellAddress.X >= 0)
            {
                try
                {
                    // Get the selected row.
                    DataGridViewRow selectedRow = dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex];

                    // Give the textBox Text the selected value.
                    textBox1.Text = selectedRow.Cells["Column2"].Value.ToString();
                }
                catch
                {
                    // Empty the textBox Text.
                    textBox1.Text = null;
                }
            }
            else
            {
                // Empty the textBox Text.
                textBox1.Text = null;
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
                // The field must not be empty.
                if (!string.IsNullOrEmpty(name))
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1.CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                        // Open a connection to the database.
                        MySqlConnection mySqlConnection = new MySqlConnection(url);
                        mySqlConnection.Open();

                        // Update the values in the Relationships table.
                        MySqlCommand mySqlCommand = new MySqlCommand("UPDATE MySqlTestDatabase.Relationships SET Name = @param2 WHERE Id = @param1", mySqlConnection);

                        // Fill the values of the command.
                        mySqlCommand.Parameters.AddWithValue("@param1", id);
                        mySqlCommand.Parameters.AddWithValue("@param2", name);

                        // Execute.
                        mySqlCommand.ExecuteNonQuery();

                        // Close the connection.
                        mySqlConnection.Close();

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
        /// Handles the TextChanged event of the textBox1 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            // Give the filed the textBox Text.
            name = textBox1.Text;
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

        #endregion Methods
    }
}
