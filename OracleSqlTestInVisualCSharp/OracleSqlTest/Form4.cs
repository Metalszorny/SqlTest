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
    /// Interaction logic for Form4.
    /// </summary>
    public partial class Form4 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = "Data Source=(DESCRIPTION=(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)" +
                             "(HOST=localhost)(PORT=1521)))" +
                             "(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=orcl)));" +
                             "User Id=root;Password=root;";

        // The id value.
        private int id;

        // The person1 value.
        private int name1;

        // The relationship value.
        private int relationship;

        // The person2 value.
        private int name2;

        #endregion Fields

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="Form4"/> class.
        /// </summary>
        public Form4()
        {
            InitializeComponent();
        }
		
		/// <summary>
        /// Destroys the instance of the <see cref="Form4"/> class.
        /// </summary>
        ~Form4()
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
                // Clear the existing items.
                dataGridView1.Rows.Clear();
                comboBox1.Items.Clear();
                comboBox2.Items.Clear();
                comboBox3.Items.Clear();

                // Open a connection to the database.
                OracleConnection oracleSqlConnection = new OracleConnection(url);
                oracleSqlConnection.Open();

                // Get the items from the People table.
                List<Person> people = new List<Person>();
                OracleCommand oracleSqlCommand1 = new OracleCommand("SELECT * FROM root.People", oracleSqlConnection);

                // Execute.
                OracleDataReader oracleSqlDataReader1 = oracleSqlCommand1.ExecuteReader();

                // Store the items in a Person list.
                while (oracleSqlDataReader1.Read())
                {
                    people.Add(new Person(oracleSqlDataReader1.GetInt32(0), oracleSqlDataReader1.GetString(1), oracleSqlDataReader1.GetString(2),
                        oracleSqlDataReader1.GetString(3), oracleSqlDataReader1.GetDateTime(4), oracleSqlDataReader1.GetInt32(5) == 1 ? true : false));
                }

                // Close the dataReader.
                oracleSqlDataReader1.Close();

                // Get the items from the Relationships table.
                List<Relationship> relationships = new List<Relationship>();
                OracleCommand oracleSqlCommand2 = new OracleCommand("SELECT * FROM root.Relationships", oracleSqlConnection);

                // Execute.
                OracleDataReader oracleSqlDataReader2 = oracleSqlCommand2.ExecuteReader();

                // Store the items in a Relationship list.
                while (oracleSqlDataReader2.Read())
                {
                    relationships.Add(new Relationship(oracleSqlDataReader2.GetInt32(0), oracleSqlDataReader2.GetString(1), oracleSqlDataReader2.GetInt32(2) == 1 ? true : false));
                }

                // Close the dataReader.
                oracleSqlDataReader2.Close();

                // Get items from the Relations table.
                List<Relation> relations = new List<Relation>();
                OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.Relations WHERE IsDeleted = 0", oracleSqlConnection);

                // Execute.
                OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                // Store the items in a Relation list.
                while (oracleSqlDataReader.Read())
                {
                    relations.Add(new Relation(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetInt32(1), oracleSqlDataReader.GetInt32(2),
                        oracleSqlDataReader.GetInt32(3), oracleSqlDataReader.GetInt32(4) == 1 ? true : false));
                }

                // Close the dataReader and the connection.
                oracleSqlDataReader.Close();
                oracleSqlConnection.Close();

                // Fill the dataGridView rows with the values of the Relations table.
                foreach (var oneItem in relations)
                {
                    DataGridViewRow row = new DataGridViewRow();
                    DataGridViewCell cell1 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell2 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell3 = new DataGridViewTextBoxCell();
                    DataGridViewCell cell4 = new DataGridViewTextBoxCell();

                    cell1.Value = oneItem.Id.ToString();

                    // Substitute the Person1 and Person2 ids with their names.
                    foreach (var onePerson in people)
                    {
                        if (oneItem.Person1 == onePerson.Id)
                        {
                            cell2.Value = onePerson.Name;
                        }

                        if (oneItem.Person2 == onePerson.Id)
                        {
                            cell4.Value = onePerson.Name;
                        }
                    }

                    // Substitute the Relationship ids with their names.
                    foreach (var oneRelationship in relationships)
                    {
                        if (oneItem.Relationship == oneRelationship.Id)
                        {
                            cell3.Value = oneRelationship.Name;
                        }
                    }

                    row.Cells.Add(cell1);
                    row.Cells.Add(cell2);
                    row.Cells.Add(cell3);
                    row.Cells.Add(cell4);

                    dataGridView1.Rows.Add(row);
                }

                // Fill the comboBox items with the values of the People table.
                foreach (var oneItem in people)
                {
                    if (!oneItem.IsDeleted)
                    {
                        comboBox1.Items.Add(oneItem.Id);
                        comboBox3.Items.Add(oneItem.Id);
                    }
                }

                // Fill the comboBox items with the values of the Relationships table.
                foreach (var oneItem in relationships)
                {
                    if (!oneItem.IsDeleted)
                    {
                        comboBox2.Items.Add(oneItem.Id);
                    }
                }
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the Load event of the Form4 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void Form4_Load(object sender, EventArgs e)
        {
            // Preset values.
            label7.Text = "";
            label8.Text = "";
            label9.Text = "";

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
        /// Handles the Click event of the button2 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button2_Click(object sender, EventArgs e)
        {
            // Add a record.
            try
            {
                // The fileds must not be empty and the names must not match.
                if (name1 != 0 && name2 != 0 && relationship != 0 && name1 != name2)
                {
                    id = 0;
                    bool matchFound = false;

                    // Open a connection to the database.
                    OracleConnection oracleSqlConnection = new OracleConnection(url);
                    oracleSqlConnection.Open();

                    // Get the items of the Relations table.
                    OracleCommand oracleSqlCommand1 = new OracleCommand("SELECT * FROM root.Relations", oracleSqlConnection);

                    // Execute.
                    OracleDataReader oracleSqlDataReader1 = oracleSqlCommand1.ExecuteReader();

                    // Get the number of the existing items.
                    while (oracleSqlDataReader1.Read())
                    {
                        id++;

                        // Search for a deleted mathing item.
                        if (!matchFound &&
                            oracleSqlDataReader1.GetInt32(1) == name1 &&
                            oracleSqlDataReader1.GetInt32(2) == relationship &&
                            oracleSqlDataReader1.GetInt32(3) == name2 &&
                            oracleSqlDataReader1.GetInt32(4) == 1)
                        {
                            matchFound = true;
                            id = oracleSqlDataReader1.GetInt32(0);

                            break;
                        }
                    }

                    // Close the dataReader.
                    oracleSqlDataReader1.Close();

                    // Add an item if no deleted found else restore the item.
                    if (!matchFound)
                    {
                        // Add a new item into the Relations table.
                        OracleCommand oracleSqlCommand = new OracleCommand("INSERT INTO root.Relations (Id, Person1, Relationship, Person2, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5)", oracleSqlConnection);

                        // Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", id + 1);
                        oracleSqlCommand.Parameters.AddWithValue(":param2", name1);
                        oracleSqlCommand.Parameters.AddWithValue(":param3", relationship);
                        oracleSqlCommand.Parameters.AddWithValue(":param4", name2);
                        oracleSqlCommand.Parameters.AddWithValue(":param5", 0);

                        // Execute.
                        oracleSqlCommand.ExecuteNonQuery();
                    }
                    else
                    {
                        // Edit the IsDeleted value to true.
                        OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.Relations SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection);

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
        /// Handles the Click event of the button3 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button3_Click(object sender, EventArgs e)
        {
            // Edit a record.
            try
            {
                // The fileds must not be empty and the names must not match.
                if (name1 != 0 && name2 != 0 && relationship != 0 && name1 != name2)
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1.CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                        // Open a connection to the database.
                        OracleConnection oracleSqlConnection = new OracleConnection(url);
                        oracleSqlConnection.Open();

                        // Update the values of the selected item.
                        OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.Relations SET Person1 = :param2, Relationship = :param3, Person2 = :param4 WHERE Id = :param1", oracleSqlConnection);

                        // Fill the values of the command.
                        oracleSqlCommand.Parameters.AddWithValue(":param1", id);
                        oracleSqlCommand.Parameters.AddWithValue(":param2", name1);
                        oracleSqlCommand.Parameters.AddWithValue(":param3", relationship);
                        oracleSqlCommand.Parameters.AddWithValue(":param4", name2);

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
        /// Handles the Click event of the button4 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void button4_Click(object sender, EventArgs e)
        {
            // Delete
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
                    OracleCommand oracleSqlCommand = new OracleCommand("UPDATE root.Relations SET IsDeleted = :param2 WHERE Id = :param1", oracleSqlConnection);

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
                    // Get the Id value of the selected item.
                    int id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                    // Open a connection to the database.
                    OracleConnection oracleSqlConnection = new OracleConnection(url);
                    oracleSqlConnection.Open();

                    // Get the item from the Relations table.
                    Relation relation = new Relation();
                    OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.Relations WHERE Id = :param1", oracleSqlConnection);

                    // Fill the values of the command.
                    oracleSqlCommand.Parameters.AddWithValue(":param1", id);

                    // Execute.
                    OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                    // Store it in a Relation object.
                    while (oracleSqlDataReader.Read())
                    {
                        relation = new Relation(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetInt32(1), oracleSqlDataReader.GetInt32(2),
                            oracleSqlDataReader.GetInt32(3), oracleSqlDataReader.GetInt32(4) == 1 ? true : false);
                    }

                    // Give the comboBox SelectedItems the selected values.
                    comboBox1.SelectedItem = relation.Person1;
                    comboBox2.SelectedItem = relation.Relationship;
                    comboBox3.SelectedItem = relation.Person2;

                    // Close the connection.
                    oracleSqlConnection.Close();
                }
                catch
                {
                    // Empty the SelectedItems value.
                    comboBox1.SelectedItem = null;
                    comboBox2.SelectedItem = null;
                    comboBox3.SelectedItem = null;
                }
            }
            else
            {
                // Empty the SelectedItems value.
                comboBox1.SelectedItem = null;
                comboBox2.SelectedItem = null;
                comboBox3.SelectedItem = null;
            }
        }

        /// <summary>
        /// Handles the SelectedIndexChanged event of the comboBox1 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                // Store the comboBox SelectedItem.
                name1 = int.Parse(comboBox1.SelectedItem.ToString());

                // Open a connection to the database.
                OracleConnection oracleSqlConnection = new OracleConnection(url);
                oracleSqlConnection.Open();

                // Get the item from the People table.
                Person retVal = new Person();
                OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.People WHERE Id = :param1", oracleSqlConnection);

                // Fill the values of the command.
                oracleSqlCommand.Parameters.AddWithValue(":param1", name1);

                // Execute.
                OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                // Store the item in a Person object.
                while (oracleSqlDataReader.Read())
                {
                    retVal = new Person(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetString(2),
                        oracleSqlDataReader.GetString(3), oracleSqlDataReader.GetDateTime(4), oracleSqlDataReader.GetInt32(5) == 1 ? true : false);
                }

                // Give the helper label the selected value.
                label7.Text = retVal.Name;

                // Close the connection.
                oracleSqlConnection.Close();
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the SelectedIndexChanged event of the comboBox2 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                // Store the comboBox SelectedItem.
                relationship = int.Parse(comboBox2.SelectedItem.ToString());

                // Open a connection to the database.
                OracleConnection oracleSqlConnection = new OracleConnection(url);
                oracleSqlConnection.Open();

                // Get the item from the Relationships table.
                Relationship retVal = new Relationship();
                OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.Relationships WHERE Id = :param1", oracleSqlConnection);

                // Fill the values of the command.
                oracleSqlCommand.Parameters.AddWithValue(":param1", relationship);

                // Execute.
                OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                // Store the item in a Relationship object.
                while (oracleSqlDataReader.Read())
                {
                    retVal = new Relationship(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetInt32(2) == 1 ? true : false);
                }

                // Give the helper label the selected value.
                label8.Text = retVal.Name;

                // Close the connection.
                oracleSqlConnection.Close();
            }
            catch
            {

            }
        }

        /// <summary>
        /// Handles the SelectedIndexChanged event of the comboBox3 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                // Store the comboBox SelectedItem.
                name2 = int.Parse(comboBox3.SelectedItem.ToString());

                // Open a connection to the database.
                OracleConnection oracleSqlConnection = new OracleConnection(url);
                oracleSqlConnection.Open();

                // Get the item from the People table.
                Person retVal = new Person();
                OracleCommand oracleSqlCommand = new OracleCommand("SELECT * FROM root.People WHERE Id = :param1", oracleSqlConnection);

                // Fill the values of the command.
                oracleSqlCommand.Parameters.AddWithValue(":param1", name2);

                // Execute.
                OracleDataReader oracleSqlDataReader = oracleSqlCommand.ExecuteReader();

                // Store the item in a Person object.
                while (oracleSqlDataReader.Read())
                {
                    retVal = new Person(oracleSqlDataReader.GetInt32(0), oracleSqlDataReader.GetString(1), oracleSqlDataReader.GetString(2), oracleSqlDataReader.GetString(3),
                        oracleSqlDataReader.GetDateTime(4), oracleSqlDataReader.GetInt32(5) == 1 ? true : false);
                }

                // Give the helper label the selected value.
                label9.Text = retVal.Name;

                // Close the connection.
                oracleSqlConnection.Close();
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

        #endregion Methods
    }
}
