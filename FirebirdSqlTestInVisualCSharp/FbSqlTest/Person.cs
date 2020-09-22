using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FbSqlTest
{
    /// <summary>
    /// Base class for Person.
    /// </summary>
    class Person
    {
        #region Fields

        // The id field of the Person class.
        private int id;

        // The name field of the Person class.
        private string name;

        // The mothername field of the Person class.
        private string mothername;

        // The location field of the Person class.
        private string location;

        // The birthdate field of the Person class.
        private DateTime birthdate;

        // The isDeleted field of the Person class.
        private bool isDeleted;

        #endregion Fields

        #region Properties

        /// <summary>
        /// Gets or sets the id field of the Person class.
        /// </summary>
        /// <value>
        /// The id.
        /// </value>
        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        /// <summary>
        /// Gets or sets the name field of the Person class.
        /// </summary>
        /// <value>
        /// The name.
        /// </value>
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        /// <summary>
        /// Gets or sets the mothername field of the Person class.
        /// </summary>
        /// <value>
        /// The mothername.
        /// </value>
        public string Mothername
        {
            get { return mothername; }
            set { mothername = value; }
        }

        /// <summary>
        /// Gets or sets the location field of the Person class.
        /// </summary>
        /// <value>
        /// The location.
        /// </value>
        public string Location
        {
            get { return location; }
            set { location = value; }
        }

        /// <summary>
        /// Gets or sets the birthdate field of the Person class.
        /// </summary>
        /// <value>
        /// The birthdate.
        /// </value>
        public DateTime Birthdate
        {
            get { return birthdate; }
            set { birthdate = DateTime.Parse(value.ToString("yyyy.MM.dd")); }
        }

        /// <summary>
        /// Gets or sets the isDeleted field of the Person class.
        /// </summary>
        /// <value>
        /// The isDeleted.
        /// </value>
        public bool IsDeleted
        {
            get { return isDeleted; }
            set { isDeleted = value; }
        }

        #endregion Properties

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="Person"/> class.
        /// </summary>
        public Person()
        { }

        /// <summary>
        /// Initializes a new instance of the <see cref="Person"/> class.
        /// </summary>
        /// <param name="id">The input value of the id field.</param>
        /// <param name="name">The input value of the name field.</param>
        /// <param name="mothername">The input value of the mothername field.</param>
        /// <param name="location">The input value of the location field.</param>
        /// <param name="birthdate">The input value of the birthdate field.</param>
        /// <param name="isdeleted">The input value of the isDeleted field.</param>
        public Person(int id, string name, string mothername, string location, DateTime birthdate, bool isdeleted)
        {
            this.id = id;
            this.name = name;
            this.mothername = mothername;
            this.location = location;
            this.birthdate = birthdate;
            this.isDeleted = isdeleted;
        }
		
		/// <summary>
        /// Destroys the instance of the <see cref="Person"/> class.
        /// </summary>
        ~Person()
        { }

        #endregion Constructors

        #region Methods

        #endregion Methods
    }
}
