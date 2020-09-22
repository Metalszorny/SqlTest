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
    /// Interaction logic for Form4.
    /// </summary>
    public partial class Form4 : Form
    {
        #region Fields

        // The database connectionString.
        private string url = @"..\..\..\Database\Relations.xml";

        // The database connectionString.
        private string url1 = @"..\..\..\Database\People.xml";

        // The database connectionString.
        private string url2 = @"..\..\..\Database\Relationships.xml";

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
                    XDocument settingsFromXml = XDocument.Load(url);
                    var readDataFromXml = settingsFromXml.Descendants("Relation");

                    // Get the items of the Relations table.
                    var fromXml = from x in readDataFromXml
                                  select x;

                    // Get the number of the existing items.
                    foreach (var oneElement in fromXml)
                    {
                        id++;

                        // Search for a deleted mathing item.
                        if (!matchFound &&
                            (int)oneElement.Element("Person1") == name1 &&
                            (int)oneElement.Element("Relationship") == relationship &&
                            (int)oneElement.Element("Person2") == name2 &&
                            (bool)oneElement.Element("IsDeleted") == true)
                        {
                            matchFound = true;
                            id = (int)oneElement.Attribute("Id");

                            break;
                        }
                    }

                    // Add an item if no deleted found else restore the item.
                    if (!matchFound)
                    {
                        // Open a connection to the database.
                        XDocument newDocument2 = XDocument.Load(url);

                        // Fill the values.
                        XElement person1Element2 = new XElement("Person1", name1);
                        XElement relationshipElement2 = new XElement("Relationship", relationship);
                        XElement person2Element2 = new XElement("Person2", name2);
                        XElement isDeletedElement2 = new XElement("IsDeleted", "False");
                        XAttribute newAttribute2 = new XAttribute("Id", id + 1);
                        XElement newElements2 = new XElement("Relation", newAttribute2, person1Element2, relationshipElement2, person2Element2, isDeletedElement2);

                        // Add new item to the Relations table.
                        newDocument2.Element("Relations").Add(newElements2);

                        // Update the values in the Relations table.
                        newDocument2.Save(url);
                    }
                    else
                    {
                        // Open a connection to the database.
                        XDocument settingsFromXml3 = XDocument.Load(url);
                        var readDataFromXml3 = settingsFromXml3.Descendants("Relation");

                        // Get the items from the Relations table.
                        var fromXml3 = from x in readDataFromXml3
                                       where (int)x.Attribute("Id") == id
                                       select x;

                        // Fill the values.
                        fromXml3.Single().Element("IsDeleted").Value = "True";

                        // Update the values in the Relations table.
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
                // The fileds must not be empty and the names must not match.
                if (name1 != 0 && name2 != 0 && relationship != 0 && name1 != name2)
                {
                    // An item must be selected in the dataGridView.
                    if (dataGridView1.CurrentCellAddress.X >= 0)
                    {
                        // Get the Id value of the selected item.
                        id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                        // Open a connection to the database.
                        XDocument settingsFromXml = XDocument.Load(url);
                        var readDataFromXml = settingsFromXml.Descendants("Relation");

                        // Get the items from the Relations table.
                        var fromXml = from x in readDataFromXml
                                      where (int)x.Attribute("Id") == id
                                      select x;

                        // Fill the values.
                        fromXml.Single().Element("Person1").Value = name1.ToString();
                        fromXml.Single().Element("Relationship").Value = relationship.ToString();
                        fromXml.Single().Element("Person2").Value = name2.ToString();

                        // Update the values in the Relations table.
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
                    var readDataFromXml = settingsFromXml.Descendants("Relation");

                    // Get the items from the Relations table.
                    var fromXml = from x in readDataFromXml
                                  where (int)x.Attribute("Id") == id
                                  select x;

                    // Fill the values.
                    fromXml.Single().Element("IsDeleted").Value = "True";

                    // Update the values in the Relations table.
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
                XDocument settingsFromXml = XDocument.Load(url1);
                var readDataFromXml = settingsFromXml.Descendants("Person");

                // Get the items from the People table.
                Person retVal = new Person();
                var fromXml = from x in readDataFromXml
                              where (int)x.Attribute("Id") == name1
                              select x;

                // Store the items in a Person list.
                foreach (var oneElement in fromXml)
                {
                    retVal = new Person((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (string)oneElement.Element("Mothername"),
                        (string)oneElement.Element("Location"), (DateTime)oneElement.Element("Birthdate"), (bool)oneElement.Element("IsDeleted"));
                }

                // Give the helper label the selected value.
                label7.Text = retVal.Name;
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
                XDocument settingsFromXml = XDocument.Load(url2);
                var readDataFromXml = settingsFromXml.Descendants("Relationship");

                // Get the items from the Relationships table.
                Relationship retVal = new Relationship();
                var fromXml = from x in readDataFromXml
                              where (int)x.Attribute("Id") == relationship
                               select x;

                // Store the items in a Relationship list.
                foreach (var oneElement in fromXml)
                {
                    retVal = new Relationship((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (bool)oneElement.Element("IsDeleted"));
                }

                // Give the helper label the selected value.
                label8.Text = retVal.Name;
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
                XDocument settingsFromXml = XDocument.Load(url1);
                var readDataFromXml = settingsFromXml.Descendants("Person");

                // Get the items from the People table.
                Person retVal = new Person();
                var fromXml = from x in readDataFromXml
                              where (int)x.Attribute("Id") == name2
                               select x;

                // Store the items in a Person list.
                foreach (var oneElement in fromXml)
                {
                    retVal = new Person((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (string)oneElement.Element("Mothername"),
                        (string)oneElement.Element("Location"), (DateTime)oneElement.Element("Birthdate"), (bool)oneElement.Element("IsDeleted"));
                }

                // Give the helper label the selected value.
                label9.Text = retVal.Name;
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
            label8.Text = "";
            label7.Text = "";
            label9.Text = "";

            #region Create

            try
            {
                if (!File.Exists(url))
                {
                    XElement person1Element1 = new XElement("Person1", "1");
                    XElement relationshipElement1 = new XElement("Relationship", "3");
                    XElement person2Element1 = new XElement("Person2", "2");
                    XElement isDeletedElement1 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute1 = new XAttribute("Id", 1);
                    XElement newElements1 = new XElement("Relation", newAttribute1, person1Element1, relationshipElement1, person2Element1, isDeletedElement1);
                    XElement newRelation1 = new XElement("Relations", newElements1);
                    XDocument newDocument1 = new XDocument(newRelation1);
                    newDocument1.Save(url);

                    XDocument newDocument2 = XDocument.Load(url);
                    XElement person1Element2 = new XElement("Person1", "2");
                    XElement relationshipElement2 = new XElement("Relationship", "4");
                    XElement person2Element2 = new XElement("Person2", "1");
                    XElement isDeletedElement2 = new XElement("IsDeleted", "False");
                    XAttribute newAttribute2 = new XAttribute("Id", 2);
                    XElement newElements2 = new XElement("Relation", newAttribute2, person1Element2, relationshipElement2, person2Element2, isDeletedElement2);
                    newDocument2.Element("Relations").Add(newElements2);
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
                    // Get the Id value of the selected item.
                    int id = int.Parse(dataGridView1.Rows[dataGridView1.SelectedCells[0].RowIndex].Cells["Column1"].Value.ToString());

                    // Open a connection to the database.
                    XDocument settingsFromXml = XDocument.Load(url);
                    var readDataFromXml = settingsFromXml.Descendants("Relation");

                    // Get items from the Relations table.
                    Relation relation = new Relation();
                    var fromXml = from x in readDataFromXml
                                   where (int)x.Attribute("Id") == id
                                   select x;

                    // Store the items in a Relation list.
                    foreach (var oneElement in fromXml)
                    {
                        relation = new Relation((int)oneElement.Attribute("Id"), (int)oneElement.Element("Person1"), (int)oneElement.Element("Relationship"),
                            (int)oneElement.Element("Person2"), (bool)oneElement.Element("IsDeleted"));
                    }

                    // Give the comboBox SelectedItems the selected values.
                    comboBox1.SelectedItem = relation.Person1;
                    comboBox2.SelectedItem = relation.Relationship;
                    comboBox3.SelectedItem = relation.Person2;
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
                XDocument settingsFromXml1 = XDocument.Load(url1);
                var readDataFromXml1 = settingsFromXml1.Descendants("Person");

                // Get the items from the People table.
                List<Person> people = new List<Person>();
                var fromXml1 = from x1 in readDataFromXml1
                              select x1;

                // Store the items in a Person list.
                foreach (var oneElement in fromXml1)
                {
                    people.Add(new Person((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (string)oneElement.Element("Mothername"),
                        (string)oneElement.Element("Location"), (DateTime)oneElement.Element("Birthdate"), (bool)oneElement.Element("IsDeleted")));
                }

                // Open a connection to the database.
                XDocument settingsFromXml2 = XDocument.Load(url2);
                var readDataFromXml2 = settingsFromXml2.Descendants("Relationship");

                // Get the items from the Relationships table.
                List<Relationship> relationships = new List<Relationship>();
                var fromXml2 = from x2 in readDataFromXml2
                               select x2;

                // Store the items in a Relationship list.
                foreach (var oneElement in fromXml2)
                {
                    relationships.Add(new Relationship((int)oneElement.Attribute("Id"), (string)oneElement.Element("Name"), (bool)oneElement.Element("IsDeleted")));
                }

                // Open a connection to the database.
                XDocument settingsFromXml3 = XDocument.Load(url);
                var readDataFromXml3 = settingsFromXml3.Descendants("Relation");

                // Get items from the Relations table.
                List<Relation> relations = new List<Relation>();
                var fromXml3 = from x3 in readDataFromXml3
                               where (bool)x3.Element("IsDeleted") == false
                               select x3;

                // Store the items in a Relation list.
                foreach (var oneElement in fromXml3)
                {
                    relations.Add(new Relation((int)oneElement.Attribute("Id"), (int)oneElement.Element("Person1"), (int)oneElement.Element("Relationship"),
                        (int)oneElement.Element("Person2"), (bool)oneElement.Element("IsDeleted")));
                }

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

        #endregion Methods
    }
}
