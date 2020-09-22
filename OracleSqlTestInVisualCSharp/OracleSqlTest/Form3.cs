using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OracleClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OracleSqlTest
{
    /// <summary>
    /// Interaction logic for Form3.
    /// </summary>
    public partial class Form3 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = "Data Source=(DESCRIPTION=(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)" +
                             "(HOST=localhost)(PORT=1521)))" +
                             "(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=orcl)));" +
                             "User Id=root;Password=root;";

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
                OracleConnection oracleSqlConnection = new OracleConnection(url);
                oracleSqlConnection.Open();

                // Get the items from the Relationships table.
                List<Relationship> relationships = new List<Relationship>();
                OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.Relationships WHERE IsDeleted = 0", oracleSqlConnection);

                // Execute.
                OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                // Store the items in a Relationship list.
                while (oracleSqlDataReader.Read())
                {
                    relationships.Add(new Relationship(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetInt32(2) == 1 ? true : false));
                }

                // Close the dataReader and the connection.
                oracleSqlDataReader.Close();
                oracleSqlConnection.Close();

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
                    OracleConnection oracleSqlConnection = new OracleConnection(url);
                    oracleSqlConnection.Open();

                    // Get the items from the Relationships table.
                    OracleCommand oracleSqlCommand1 = new OracleCommand("SELECT * FROM root.Relationships", oracleSqlConnection);

                    // Execute.
                    OracleDataReader oracleSqlDataReader1 = oracleSqlCommand1.ExecuteReader();

                    // Get the number of the existing items.
                    while (oracleSqlDataReader1.Read())
                    {
                        id++;

                        // Check if the new item already exists.
                        if (oracleSqlDataReader1.GetString(1) == name && !matchFound && oracleSqlDataReader1.GetInt32(3) == 0)
                        {
                            matchFound = true;

                            break;
                        }

                        // Check if the new item already exists.
                        if (oracleSqlDataReader1.GetString(1) == name && !deletedFound && oracleSqlDataReader1.GetInt32(3) == 1)
                        {
                            deletedFound = true;
                            id = oracleSqlDataReader1.GetInt32(0);

                            break;
                        }
                    }

                    // Close the dataReader.
                    oracleSqlDataReader1.Close();

                    // If no match was found among the active items.
                    if (!matchFound)
                    {
                        // Add a record if no deleted item found else restore the deleted item.
                        if (!deletedFound)
                        {
                            // Add new item to the Relationship table.
                            OracleCommand oracleSqlCommand = new OracleCommand("INSERT INTO root.Relationships (Id, Name, IsDeleted) VALUES (:param1, :param2, :param3)", oracleSqlConnection);

                            // Fill the values of the command.
                            oracleSqlCommand.Parameters.AddWithValue(":param1", id + 1);
                            oracleSqlCommand.Parameters.AddWithValue(":param2", name);
                            oracleSqlCommand.Parameters.AddWithValue(":param3", 0);

                            // Execute.
                            oracleSqlCommand.ExecuteNonQuery();
                        }
                        else
                        {
                            // Edit the IsDeleted value to false.
                            OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.Relationships SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection);

                            // Fill the values of the command.
                            oracleSqlCommand.Parameters.AddWithValue(":param1", id);
                            oracleSqlCommand.Parameters.AddWithValue(":param2", 0);

                            // Execute.
                            oracleSqlCommand.ExecuteNonQuery();
                        }
                    }

                    // Close the connection.
                    oracleSqlConnection.Close();

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
                    OracleConnection oracleSqlConnection = new OracleConnection(url);
                    oracleSqlConnection.Open();

                    // Edit the IsDeleted value to true.
                    OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.Relationships SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection);

                    // Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", id);
                    oracleSqlCommand.Parameters.AddWithValue(":param2", 1);

                    // Execute.
                    oracleSqlCommand.ExecuteNonQuery();

                    // Close the connection.
                    oracleSqlConnection.Close();

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
                        OracleConnection oracleSqlConnection = new OracleConnection(url);
                        oracleSqlConnection.Open();

                        // Update the values in the Relationships table.
                        OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.Relationships SET Name = :param2 WHERE Id = :param1", oracleSqlConnection);

                        // Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", id);
                        oracleSqlCommand.Parameters.AddWithValue(":param2", name);

                        // Execute.
                        oracleSqlCommand.ExecuteNonQuery();

                        // Close the connection.
                        oracleSqlConnection.Close();

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
