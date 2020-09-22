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
    /// Interaction logic for Form2.
    /// </summary>
    public partial class Form2 : Form
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

                // Get the items from the People table.
                List<Person> people = new List<Person>();
                OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.People WHERE IsDeleted = 0", oracleSqlConnection);

                // Execute.
                OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                // Store the items in a Person list.
                while (oracleSqlDataReader.Read())
                {
                    people.Add(new Person(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetString(2), oracleSqlDataReader.GetString(3),
                        oracleSqlDataReader.GetDateTime(4), oracleSqlDataReader.GetInt32(5) == 1 ? true : false));
                }

                // Close the datareader and the connection.
                oracleSqlDataReader.Close();
                oracleSqlConnection.Close();

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
                    OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.People SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection);

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
                        OracleConnection oracleSqlConnection = new OracleConnection(url);
                        oracleSqlConnection.Open();

                        // Update the values in the People table.
                        OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.People SET Name = :param2, Mothername = :param3, Location = :param4, BirthDate = :param5 WHERE Id = :param1", oracleSqlConnection);

                        // Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", id);
                        oracleSqlCommand.Parameters.AddWithValue(":param2", name);
                        oracleSqlCommand.Parameters.AddWithValue(":param3", mothername);
                        oracleSqlCommand.Parameters.AddWithValue(":param4", location);
                        oracleSqlCommand.Parameters.AddWithValue(":param5", DateTime.Parse(birthdate));

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
                if (!string.IsNullOrEmpty(name) && !string.IsNullOrEmpty(mothername) && !string.IsNullOrEmpty(location) && !string.IsNullOrEmpty(birthdate.ToString()))
                {
                    id = 0;
                    bool matchFound = false;

                    // Open a connection to the database.
                    OracleConnection oracleSqlConnection = new OracleConnection(url);
                    oracleSqlConnection.Open();

                    // Get the items from the People table.
                    OracleCommand oracleSqlCommand1 = new OracleCommand("SELECT * FROM root.People", oracleSqlConnection);

                    // Execute.
                    OracleDataReader oracleSqlDataReader1 = oracleSqlCommand1.ExecuteReader();

                    // Get the number of the existing items.
                    while (oracleSqlDataReader1.Read())
                    {
                        id++;

                        // Search for deleted matches.
                        if (!matchFound &&
                            oracleSqlDataReader1.GetString(1) == name &&
                            oracleSqlDataReader1.GetString(2) == mothername &&
                            oracleSqlDataReader1.GetString(3) == location &&
                            oracleSqlDataReader1.GetDateTime(4) == DateTime.Parse(birthdate) &&
                            oracleSqlDataReader1.GetInt32(5) == 1)
                        {
                            matchFound = true;
                            id = oracleSqlDataReader1.GetInt32(0);

                            break;
                        }
                    }

                    // Close the dataReader.
                    oracleSqlDataReader1.Close();

                    // Add a new item if no match exists or restore the deleted item.
                    if (!matchFound)
                    {
                        // Add new item to the People table.
                        OracleCommand oracleSqlCommand = new OracleCommand("INSERT INTO root.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5, :param6)", oracleSqlConnection);

                        // Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", id + 1);
                        oracleSqlCommand.Parameters.AddWithValue(":param2", name);
                        oracleSqlCommand.Parameters.AddWithValue(":param3", mothername);
                        oracleSqlCommand.Parameters.AddWithValue(":param4", location);
                        oracleSqlCommand.Parameters.AddWithValue(":param5", DateTime.Parse(birthdate));
                        oracleSqlCommand.Parameters.AddWithValue(":param6", 0);

                        // Execute.
                        oracleSqlCommand.ExecuteNonQuery();
                    }
                    else
                    {
                        // Edit the IsDeleted value to false.
                        OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.People SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection);

                        // Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", id);
                        oracleSqlCommand.Parameters.AddWithValue(":param2", 0);

                        // Execute.
                        oracleSqlCommand.ExecuteNonQuery();
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
