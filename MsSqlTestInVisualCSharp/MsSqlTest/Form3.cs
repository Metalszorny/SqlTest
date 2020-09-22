using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MsSqlTest
{
    /// <summary>
    /// Interaction logic for Form3.
    /// </summary>
    public partial class Form3 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = "Server=localhost; Database=MsSqlTestDatabase; User id=root; Password=RootUser0123456789;";

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
                SqlConnection msSqlConnection = new SqlConnection(url);
                msSqlConnection.Open();

                // Get the items from the Relationships table.
                List<Relationship> relationships = new List<Relationship>();
                SqlCommand msSqlCommand = new SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships] WHERE IsDeleted = 0", msSqlConnection);

                // Execute.
                SqlDataReader msSqlDataReader = msSqlCommand.ExecuteReader();

                // Store the items in a Relationship list.
                while (msSqlDataReader.Read())
                {
                    relationships.Add(new Relationship(msSqlDataReader.GetInt32(0), msSqlDataReader.GetString(1), msSqlDataReader.GetBoolean(2)));
                }

                // Close the dataReader and the connection.
                msSqlDataReader.Close();
                msSqlConnection.Close();

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
            // Preset values.
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
                    bool matchFound = false;
                    bool deletedFound = false;
                    id = 0;

                    // Open a connection to the database.
                    SqlConnection msSqlConnection = new SqlConnection(url);
                    msSqlConnection.Open();

                    // Get the items from the Relationships table.
                    SqlCommand msSqlCommand1 = new SqlCommand("SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships]", msSqlConnection);

                    // Execute.
                    SqlDataReader msSqlDataReader1 = msSqlCommand1.ExecuteReader();

                    // Get the number of the existing items.
                    while (msSqlDataReader1.Read())
                    {
                        id++;

                        // Check if the new item already exists.
                        if (msSqlDataReader1.GetString(1) == name && !matchFound && msSqlDataReader1.GetBoolean(3) == false)
                        {
                            matchFound = true;

                            break;
                        }

                        // Check if the new item already exists.
                        if (msSqlDataReader1.GetString(1) == name && !deletedFound && msSqlDataReader1.GetBoolean(3) == true)
                        {
                            deletedFound = true;
                            id = msSqlDataReader1.GetInt32(0);

                            break;
                        }
                    }

                    // Close the dataReader.
                    msSqlDataReader1.Close();

                    // If no match was found among the active items.
                    if (!matchFound)
                    {
                        // Add a record if no deleted item found else restore the deleted item.
                        if (!deletedFound)
                        {
                            // Add new item to the Relationship table.
                            SqlCommand msSqlCommand = new SqlCommand("INSERT INTO [MsSqlTestDatabase].[dbo].[Relationships] (Id, Name, IsDeleted) VALUES (@param1, @param2, @param3)", msSqlConnection);

                            // Fill the values of the command.
                            msSqlCommand.Parameters.AddWithValue("@param1", id + 1);
                            msSqlCommand.Parameters.AddWithValue("@param2", name);
                            msSqlCommand.Parameters.AddWithValue("@param3", false);

                            // Execute.
                            msSqlCommand.ExecuteNonQuery();
                        }
                        else
                        {
                            // Edit the IsDeleted value to false.
                            SqlCommand msSqlCommand = new SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET IsDeleted = @param2 WHERE Id = @param1", msSqlConnection);

                            // Fill the values of the command.
                            msSqlCommand.Parameters.AddWithValue("@param1", id);
                            msSqlCommand.Parameters.AddWithValue("@param2", false);

                            // Execute.
                            msSqlCommand.ExecuteNonQuery();
                        }
                    }

                    // Close the connection.
                    msSqlConnection.Close();

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
                    SqlConnection msSqlConnection = new SqlConnection(url);
                    msSqlConnection.Open();

                    // Edit the IsDeleted value to true.
                    SqlCommand msSqlCommand = new SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET IsDeleted = @param2 WHERE Id = @param1", msSqlConnection);

                    // Fill the values of the command.
                    msSqlCommand.Parameters.AddWithValue("@param1", id);
                    msSqlCommand.Parameters.AddWithValue("@param2", true);

                    // Execute.
                    msSqlCommand.ExecuteNonQuery();

                    // Close the connection.
                    msSqlConnection.Close();

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
                        SqlConnection msSqlConnection = new SqlConnection(url);
                        msSqlConnection.Open();

                        // Update the values in the Relationships table.
                        SqlCommand msSqlCommand = new SqlCommand("UPDATE [MsSqlTestDatabase].[dbo].[Relationships] SET Name = @param2 WHERE Id = @param1", msSqlConnection);

                        // Fill the values of the command.
                        msSqlCommand.Parameters.AddWithValue("@param1", id);
                        msSqlCommand.Parameters.AddWithValue("@param2", name);

                        // Execute.
                        msSqlCommand.ExecuteNonQuery();

                        // Close the connection.
                        msSqlConnection.Close();

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
