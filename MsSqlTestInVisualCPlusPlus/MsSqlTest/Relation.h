#pragma once

namespace MsSqlTest
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Linq;
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace std;

	/// <summary>
    /// Base class for Relation.
    /// </summary>
	ref class Relation
	{
		#pragma region Fields

		// The id field of the Relation class.
		private: int^ id;

        // The person1 field of the Relation class.
		private: int^ person1;

        // The relationship field of the Relation class.
		private: int^ relationship;

        // The person2 field of the Relation class.
		private: int^ person2;

        // The isDeleted field of the Relation class.
		private: bool^ isDeleted;

		#pragma endregion

		#pragma region Properties

		/// <summary>
		/// Gets the id.
		/// </summary>
		/// <returns>
		/// The id.
		/// </returns>
		public: int^ getId()
		{
			return id;
		}

		/// <summary>
		/// Sets the id.
		/// </summary>
		/// <value>
		/// The id.
		/// </value>
		public: void setId(int^ value)
		{
			id = value;
		}

		/// <summary>
		/// Gets the person1.
		/// </summary>
		/// <returns>
		/// The person1.
		/// </returns>
		public: int^ getPerson1()
		{
			return person1;
		}

		/// <summary>
		/// Sets the person1.
		/// </summary>
		/// <value>
		/// The person1.
		/// </value>
		public: void setPerson1(int^ value)
		{
			person1 = value;
		}

		/// <summary>
		/// Gets the relationship.
		/// </summary>
		/// <returns>
		/// The relationship.
		/// </returns>
		public: int^ getRelationship()
		{
			return relationship;
		}

		/// <summary>
		/// Sets the relationship.
		/// </summary>
		/// <value>
		/// The relationship.
		/// </value>
		public: void setRelationship(int^ value)
		{
			relationship = value;
		}

		/// <summary>
		/// Gets the person2.
		/// </summary>
		/// <returns>
		/// The person2.
		/// </returns>
		public: int^ getPerson2()
		{
			return person2;
		}

		/// <summary>
		/// Sets the person2.
		/// </summary>
		/// <value>
		/// The person2.
		/// </value>
		public: void setPerson2(int^ value)
		{
			person2 = value;
		}

		/// <summary>
		/// Gets the isDeleted.
		/// </summary>
		/// <returns>
		/// The isDeleted.
		/// </returns>
		public: bool^ getIsDeleted()
		{
			return isDeleted;
		}

		/// <summary>
		/// Sets the isDeleted.
		/// </summary>
		/// <value>
		/// The isDeleted.
		/// </value>
		public: void setIsDeleted(bool^ value)
		{
			isDeleted = value;
		}

		#pragma endregion

		#pragma region Constructors

		/// <summary>
        /// Initializes a new instance of the <see cref="Relation"/> class.
        /// </summary>
		public: Relation()
        { }

        /// <summary>
        /// Initializes a new instance of the <see cref="Relation"/> class.
        /// </summary>
        /// <param name="id">The input value of the id field.</param>
        /// <param name="person1">The input value of the person1 field.</param>
        /// <param name="relationship">The input value of the relationship field.</param>
        /// <param name="person2">The input value of the person2 field.</param>
        /// <param name="isdeleted">The input value of the isDeleted field.</param>
		public: Relation(int^ id, int^ person1, int^ relationship, int^ person2, bool^ isdeleted)
        {
            this->id = id;
            this->person1 = person1;
            this->relationship = relationship;
            this->person2 = person2;
            this->isDeleted = isdeleted;
        }

		#pragma endregion

		#pragma region Methods

		#pragma endregion
	};
}