#pragma once

namespace OracleSqlTest
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Linq;
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace std;

	/// <summary>
    /// Base class for Person.
    /// </summary>
	ref class Person
	{
		#pragma region Fields

		// The id field of the Person class.
		private: int^ id;

        // The name field of the Person class.
		private: String^ name;

        // The mothername field of the Person class.
		private: String^ mothername;

        // The location field of the Person class.
		private: String^ location;

        // The birthdate field of the Person class.
		private: DateTime^ birthdate;

        // The isDeleted field of the Person class.
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
		/// Gets the name.
		/// </summary>
		/// <returns>
		/// The name.
		/// </returns>
		public: String^ getName()
		{
			return name;
		}

		/// <summary>
		/// Sets the name.
		/// </summary>
		/// <value>
		/// The name.
		/// </value>
		public: void setName(String^ value)
		{
			name = value;
		}

		/// <summary>
		/// Gets the mothername.
		/// </summary>
		/// <returns>
		/// The mothername.
		/// </returns>
		public: String^ getMothername()
		{
			return mothername;
		}

		/// <summary>
		/// Sets the mothername.
		/// </summary>
		/// <value>
		/// The mothername.
		/// </value>
		public: void setMothername(String^ value)
		{
			mothername = value;
		}

		/// <summary>
		/// Gets the location.
		/// </summary>
		/// <returns>
		/// The location.
		/// </returns>
		public: String^ getLocation()
		{
			return location;
		}

		/// <summary>
		/// Sets the location.
		/// </summary>
		/// <value>
		/// The location.
		/// </value>
		public: void setLocation(String^ value)
		{
			location = value;
		}

		/// <summary>
		/// Gets the birthdate.
		/// </summary>
		/// <returns>
		/// The birthdate.
		/// </returns>
		public: DateTime^ getBirthdate()
		{
			return birthdate;
		}

		/// <summary>
		/// Sets the birthdate.
		/// </summary>
		/// <value>
		/// The birthdate.
		/// </value>
		public: void setBirthdate(DateTime^ value)
		{
			birthdate = value;
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
        /// Initializes a new instance of the <see cref="Person"/> class.
        /// </summary>
		public: Person()
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
		public: Person(int^ id, String^ name, String^ mothername, String^ location, DateTime^ birthdate, bool^ isdeleted)
        {
            this->id = id;
            this->name = name;
            this->mothername = mothername;
            this->location = location;
            this->birthdate = birthdate;
            this->isDeleted = isdeleted;
        }

		#pragma endregion

		#pragma region Methods

		#pragma endregion
	};
}