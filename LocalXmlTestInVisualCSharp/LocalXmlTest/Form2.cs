using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace LocalXmlTest
{
    /// <summary>
    /// Interaction logic for Form2.
    /// </summary>
    public partial class Form2 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = @"..\..\..\Database\People.xml";

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
                    XDocument settingsFromXml = XDocument.Load(url);
                    var readDataFromXml = settingsFromXml.Descendants("Person");

                    // Get the items from the People table.
                    var fromXml = from x in readDataFromXml
                                  select x;

                    // Get the number of the existing items.
                    foreach (var oneElement in fromXml)
                    {
                        id++;

                        // Search for deleted matches.
                        if (!matchFound &&
                            (string)oneElement.Element("Name") == name &&
                            (string)oneElement.Element("Mothername") == mothername &&
                            (string)oneElement.Element("Location") == location &&
                            (DateTime)oneElement.Element("Birthdate") == DateTime.Parse(birthdate) &&
                            (bool)oneElement.Element("IsDeleted") == true)
                        {
                            matchFound = true;
                            id = (int)oneElement.Attribute("Id");

                            break;
                        }
                    }

                    // Add a new item if no match exists or restore the deleted item.
                    if (!matchFound)
                    {
                        // Open a connection to the database.
                        XDocument newDocument2 = XDocument.Load(url);

                        // Fill the values.
                        XElement nameElement2 = new XElement("Name", name);
                        XElement mothernameElement2 = new XElement("Mothername", mothername);
                        XElement locationElement2 = new XElement("Location", location);
                        XElement birthdateElement2 = new XElement("Birthdate", birthdate);
                        XElement isDeletedElement2 = new XElement("IsDeleted", "False");
                        XAttribute newAttribute2 = new XAttribute("Id", id + 1);
                        XElement newElements2 = new XElement("Person", newAttribute2, nameElement2, mothernameElement2, locationElement2, birthdateElement2, isDeletedElement2);

                        // Add new item to the People table.
                        newDocument2.Element("People").Add(newElements2);

                        // Update the values in the People table.
                        newDocument2.Save(url);
                    }
                    else
                    {
                        // Open a connection to the database.
                        XDocument settingsFromXml3 = XDocument.Load(url);
                        var readDataFromXml3 = settingsFromXml3.Descendants("Person");

                        // Get the items from the People table.
                        var fromXml3 = from x in readDataFromXml3
                                      where (int)x.Attribute("Id") == id
                                      select x;

                        // Fill the values.
                        fromXml3.Single().Element("IsDeleted").Value = "True";

                        // Update the values in the People table.
                        settingsFromXml3.Save(url);
                    }

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
                        XDocument settingsFromXml = XDocument.Load(url);
                        var readDataFromXml = settingsFromXml.Descendants("Person");

                        // Get the items from the People table.
                        var fromXml = from x in readDataFromXml
                                      where (int)x.Attribute("Id") == id
                                      select x;

                        // Fill the values.
                        fromXml.Single().Element("Name").Value = name;
                        fromXml.Single().Element("Mothername").Value = mothername;
                        fromXml.Single().Element("Location").Value = location;
                        fromXml.Single().Element("Birthdate").Value = birthdate;

                        // Update the values in the People table.
                        settingsFromXml.Save(url);

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
                    XDocument settingsFromXml = XDocument.Load(url);
                    var readDataFromXml = settingsFromXml.Descendants("Person");

                    // Get the items from the People table.
                    var fromXml = from x in readDataFromXml
                                  where (int)x.Attribute("Id") == id
                                  select x;

                    // Fill the values.
                    fromXml.Single().Element("IsDeleted").Value = "True";

                    // Update the values in the People table.
                    settingsFromXml.Save(url);

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

            #region Create

            try
            {
                if (!File.Exists(url))
                {
                    XElement nameElement1 = new XElement("Name", "John Smith");
                    XElement mothernameElement1 = new XElement("Mothername", "Lisa Simmons");
                    XElement locationElement1 = new XElement("Location", "London");
                    XElement birthdateElement1 = new XElement("Birthdate", "1971.01.01");
                    XElement isDeletedElement1 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute1 = new XAttribute("Id", 1);
                    XElement newElements1 = new XElement("Person", newAttribute1, nameElement1, mothernameElement1, locationElement1, birthdateElement1, isDeletedElement1);
                    XElement newPerson1 = new XElement("People", newElements1);
                    XDocument newDocument1 = new XDocument(newPerson1);
                    newDocument1.Save(url);

                    XDocument newDocument2 = XDocument.Load(url);
                    XElement nameElement2 = new XElement("Name", "Ann Davis");
                    XElement mothernameElement2 = new XElement("Mothername", "Mary Reed");
                    XElement locationElement2 = new XElement("Location", "London");
                    XElement birthdateElement2 = new XElement("Birthdate", "1972.02.02");
                    XElement isDeletedElement2 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute2 = new XAttribute("Id", 2);
                    XElement newElements2 = new XElement("Person", newAttribute2, nameElement2, mothernameElement2, locationElement2, birthdateElement2, isDeletedElement2);
                    newDocument2.Element("People").Add(newElements2);
                    newDocument2.Save(url);
                }
            }
            catch
            {

            }

            #endregion Create

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
                XDocument settingsFromXml = XDocument.Load(url);
                var readDataFromXml = settingsFromXml.Descendants("Person");

                // Get the items from the People table.
                List<Person> people = new List<Person>();
                var fromXml = from x in readDataFromXml
                              where (bool)x.Element("IsDeleted") == false
                              select x;

                // Store the items in a Person list.
                foreach (var oneElement in fromXml)
                {
                    people.Add(new Person((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (string)oneElement.Element("Mothername"), 
                        (string)oneElement.Element("Location"), (DateTime)oneElement.Element("Birthdate"), (bool)oneElement.Element("IsDeleted")));
                }

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
