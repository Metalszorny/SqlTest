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
    /// Interaction logic for Form3.
    /// </summary>
    public partial class Form3 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = @"..\..\..\Database\Relationships.xml";

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
                // The field must not be empty.
                if (!string.IsNullOrEmpty(name))
                {
                    bool matchFound = false;
                    bool deletedFound = false;
                    id = 0;

                    // Open a connection to the database.
                    XDocument settingsFromXml = XDocument.Load(url);
                    var readDataFromXml = settingsFromXml.Descendants("Relationship");

                    // Get the items from the Relationships table.
                    var fromXml = from x in readDataFromXml
                                  select x;

                    // Get the number of the existing items.
                    foreach (var oneElement in fromXml)
                    {
                        id++;

                        // Check if the new item already exists.
                        if (!matchFound &&
                            (string)oneElement.Element("Name") == name &&
                            (bool)oneElement.Element("IsDeleted") == true)
                        {
                            matchFound = true;

                            break;
                        }

                        // Check if the new item already exists.
                        if (!matchFound &&
                            (string)oneElement.Element("Name") == name &&
                            (bool)oneElement.Element("IsDeleted") == false)
                        {
                            deletedFound = true;
                            id = (int)oneElement.Attribute("Id");

                            break;
                        }
                    }

                    // If no match was found among the active items.
                    if (!matchFound)
                    {
                        // Add a record if no deleted item found else restore the deleted item.
                        if (!deletedFound)
                        {
                            // Open a connection to the database.
                            XDocument newDocument2 = XDocument.Load(url);

                            // Fill the values of the command.
                            XElement nameElement2 = new XElement("Name", name);
                            XElement isDeletedElement2 = new XElement("IsDeleted", "False");
                            XAttribute newAttribute2 = new XAttribute("Id", id + 1);
                            XElement newElements2 = new XElement("Relationship", newAttribute2, nameElement2, isDeletedElement2);

                            // Add new item to the Relationships table.
                            newDocument2.Element("Relationships").Add(newElements2);

                            // Update the values in the Relationships table.
                            newDocument2.Save(url);
                        }
                        else
                        {
                            // Open a connection to the database.
                            XDocument settingsFromXml3 = XDocument.Load(url);
                            var readDataFromXml3 = settingsFromXml3.Descendants("Relationship");

                            // Get the items from the Relationships table.
                            var fromXml3 = from x in readDataFromXml3
                                           where (int)x.Attribute("Id") == id
                                           select x;

                            // Fill the values.
                            fromXml3.Single().Element("IsDeleted").Value = "True";

                            // Update the values in the Relationships table.
                            settingsFromXml3.Save(url);
                        }
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
                // The field must not be empty.
                if (!string.IsNullOrEmpty(name))
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1.CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                        // Open a connection to the database.
                        XDocument settingsFromXml = XDocument.Load(url);
                        var readDataFromXml = settingsFromXml.Descendants("Relationship");

                        // Get the items from the Relationships table.
                        var fromXml = from x in readDataFromXml
                                      where (int)x.Attribute("Id") == id
                                      select x;

                        // Fill the values.
                        fromXml.Single().Element("Name").Value = name;

                        // Update the values in the Relationships table.
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
                    var readDataFromXml = settingsFromXml.Descendants("Relationship");

                    // Get the items from the Relationships table.
                    var fromXml = from x in readDataFromXml
                                  where (int)x.Attribute("Id") == id
                                  select x;

                    // Fill the values.
                    fromXml.Single().Element("IsDeleted").Value = "True";

                    // Update the values in the Relationships table.
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
            // Give the filed the textBox Text.
            name = textBox1.Text;
        }

        /// <summary>
        /// Handles the Load event of the Form3 control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="EventArgs"/> instance containing the event data.</param>
        private void Form3_Load(object sender, EventArgs e)
        {
            // Preset values.

            #region Create

            try
            {
                if (!File.Exists(url))
                {
                    XElement nameElement1 = new XElement("Name", "Father");
                    XElement isDeletedElement1 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute1 = new XAttribute("Id", 1);
                    XElement newElements1 = new XElement("Relationship", newAttribute1, nameElement1, isDeletedElement1);
                    XElement newRelationship1 = new XElement("Relationships", newElements1);
                    XDocument newDocument1 = new XDocument(newRelationship1);
                    newDocument1.Save(url);

                    XDocument newDocument2 = XDocument.Load(url);
                    XElement nameElement2 = new XElement("Name", "Mother");
                    XElement isDeletedElement2 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute2 = new XAttribute("Id", 2);
                    XElement newElements2 = new XElement("Relationship", newAttribute2, nameElement2, isDeletedElement2);
                    newDocument2.Element("Relationships").Add(newElements2);
                    newDocument2.Save(url);

                    XDocument newDocument3 = XDocument.Load(url);
                    XElement nameElement3 = new XElement("Name", "Husband");
                    XElement isDeletedElement3 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute3 = new XAttribute("Id", 3);
                    XElement newElements3 = new XElement("Relationship", newAttribute3, nameElement3, isDeletedElement3);
                    newDocument3.Element("Relationships").Add(newElements3);
                    newDocument3.Save(url);

                    XDocument newDocument4 = XDocument.Load(url);
                    XElement nameElement4 = new XElement("Name", "Wife");
                    XElement isDeletedElement4 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute4 = new XAttribute("Id", 4);
                    XElement newElements4 = new XElement("Relationship", newAttribute4, nameElement4, isDeletedElement4);
                    newDocument4.Element("Relationships").Add(newElements4);
                    newDocument4.Save(url);

                    XDocument newDocument5 = XDocument.Load(url);
                    XElement nameElement5 = new XElement("Name", "Sister");
                    XElement isDeletedElement5 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute5 = new XAttribute("Id", 5);
                    XElement newElements5 = new XElement("Relationship", newAttribute5, nameElement5, isDeletedElement5);
                    newDocument5.Element("Relationships").Add(newElements5);
                    newDocument5.Save(url);

                    XDocument newDocument6 = XDocument.Load(url);
                    XElement nameElement6 = new XElement("Name", "Brother");
                    XElement isDeletedElement6 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute6 = new XAttribute("Id", 6);
                    XElement newElements6 = new XElement("Relationship", newAttribute6, nameElement6, isDeletedElement6);
                    newDocument6.Element("Relationships").Add(newElements6);
                    newDocument6.Save(url);

                    XDocument newDocument7 = XDocument.Load(url);
                    XElement nameElement7 = new XElement("Name", "Son");
                    XElement isDeletedElement7 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute7 = new XAttribute("Id", 7);
                    XElement newElements7 = new XElement("Relationship", newAttribute7, nameElement7, isDeletedElement7);
                    newDocument7.Element("Relationships").Add(newElements7);
                    newDocument7.Save(url);

                    XDocument newDocument8 = XDocument.Load(url);
                    XElement nameElement8 = new XElement("Name", "Daughter");
                    XElement isDeletedElement8 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute8 = new XAttribute("Id", 8);
                    XElement newElements8 = new XElement("Relationship", newAttribute8, nameElement8, isDeletedElement8);
                    newDocument8.Element("Relationships").Add(newElements8);
                    newDocument8.Save(url);

                    XDocument newDocument9 = XDocument.Load(url);
                    XElement nameElement9 = new XElement("Name", "Grandmother");
                    XElement isDeletedElement9 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute9 = new XAttribute("Id", 9);
                    XElement newElements9 = new XElement("Relationship", newAttribute9, nameElement9, isDeletedElement9);
                    newDocument9.Element("Relationships").Add(newElements9);
                    newDocument9.Save(url);

                    XDocument newDocument10 = XDocument.Load(url);
                    XElement nameElement10 = new XElement("Name", "Grandfather");
                    XElement isDeletedElement10 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute10 = new XAttribute("Id", 10);
                    XElement newElements10 = new XElement("Relationship", newAttribute10, nameElement10, isDeletedElement10);
                    newDocument10.Element("Relationships").Add(newElements10);
                    newDocument10.Save(url);

                    XDocument newDocument11 = XDocument.Load(url);
                    XElement nameElement11 = new XElement("Name", "Grandson");
                    XElement isDeletedElement11 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute11 = new XAttribute("Id", 11);
                    XElement newElements11 = new XElement("Relationship", newAttribute11, nameElement11, isDeletedElement11);
                    newDocument11.Element("Relationships").Add(newElements11);
                    newDocument11.Save(url);

                    XDocument newDocument12 = XDocument.Load(url);
                    XElement nameElement12 = new XElement("Name", "Granddaughter");
                    XElement isDeletedElement12 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute12 = new XAttribute("Id", 12);
                    XElement newElements12 = new XElement("Relationship", newAttribute12, nameElement12, isDeletedElement12);
                    newDocument12.Element("Relationships").Add(newElements12);
                    newDocument12.Save(url);
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
                var readDataFromXml = settingsFromXml.Descendants("Relationship");

                // Get the items from the Relationships table.
                List<Relationship> relationships = new List<Relationship>();
                var fromXml = from x in readDataFromXml
                              where (bool)x.Element("IsDeleted") == false
                              select x;

                // Store the items in a Relationship list.
                foreach (var oneElement in fromXml)
                {
                    relationships.Add(new Relationship((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (bool)oneElement.Element("IsDeleted")));
                }

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

        #endregion Methods
    }
}
