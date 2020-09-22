using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalXmlTest
{
    /// <summary>
    /// Base class for Relation.
    /// </summary>
    class Relation
    {
        #region Fields

        // The id field of the Relation class.
        private int id;

        // The person1 field of the Relation class.
        private int person1;

        // The relationship field of the Relation class.
        private int relationship;

        // The person2 field of the Relation class.
        private int person2;

        // The isDeleted field of the Relation class.
        private bool isDeleted;

        #endregion Fields

        #region Properties

        /// <summary>
        /// Gets or sets the id field of the Relation class.
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
        /// Gets or sets the person1 field of the Relation class.
        /// </summary>
        /// <value>
        /// The person1.
        /// </value>
        public int Person1
        {
            get { return person1; }
            set { person1 = value; }
        }

        /// <summary>
        /// Gets or sets the relationship field of the Relation class.
        /// </summary>
        /// <value>
        /// The relationship.
        /// </value>
        public int Relationship
        {
            get { return relationship; }
            set { relationship = value; }
        }

        /// <summary>
        /// Gets or sets the Person2 field of the Relation class.
        /// </summary>
        /// <value>
        /// The person2.
        /// </value>
        public int Person2
        {
            get { return person2; }
            set { person2 = value; }
        }

        /// <summary>
        /// Gets or sets the isDeleted field of the Relation class.
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
        /// Initializes a new instance of the <see cref="Relation"/> class.
        /// </summary>
        public Relation()
        { }

        /// <summary>
        /// Initializes a new instance of the <see cref="Relation"/> class.
        /// </summary>
        /// <param name="id">The input value of the id field.</param>
        /// <param name="person1">The input value of the person1 field.</param>
        /// <param name="relationship">The input value of the relationship field.</param>
        /// <param name="person2">The input value of the person2 field.</param>
        /// <param name="isdeleted">The input value of the isDeleted field.</param>
        public Relation(int id, int person1, int relationship, int person2, bool isdeleted)
        {
            this.id = id;
            this.person1 = person1;
            this.relationship = relationship;
            this.person2 = person2;
            this.isDeleted = isdeleted;
        }
		
		/// <summary>
        /// Destroys the instance of the <see cref="Relation"/> class.
        /// </summary>
        ~Relation()
        { }

        #endregion Constructors

        #region Methods

        #endregion Methods
    }
}
