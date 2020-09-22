using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SQLiteTest
{
    /// <summary>
    /// Base class for Relationship.
    /// </summary>
    class Relationship
    {
        #region Fields

        // The id field of the Relationship class.
        private int id;

        // The name field of the Relationship class.
        private string name;

        // The isDeleted field of the Relationship class.
        private bool isDeleted;

        #endregion Fields

        #region Properties

        /// <summary>
        /// Gets or sets the id field of the Relationship class.
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
        /// Gets or sets the name field of the Relationship class.
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
        /// Gets or sets the isDeleted field of the Relationship class.
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
        /// Initializes a new instance of the <see cref="Relationship"/> class.
        /// </summary>
        public Relationship()
        { }

        /// <summary>
        /// Initializes a new instance of the <see cref="Relationship"/> class.
        /// </summary>
        /// <param name="id">The input value of the id field.</param>
        /// <param name="name">The input value of the name field.</param>
        /// <param name="isdeleted">The input value of the isDeleted field.</param>
        public Relationship(int id, string name, bool isdeleted)
        {
            this.id = id;
            this.name = name;
            this.isDeleted = isdeleted;
        }
		
		/// <summary>
        /// Destroys the instance of the <see cref="Relationship"/> class.
        /// </summary>
        ~Relationship()
        { }

        #endregion Constructors

        #region Methods

        #endregion Methods
    }
}
