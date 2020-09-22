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
	/// Base class for Relationship.
	/// </summary>
	ref class Relationship
	{
		#pragma region Fields

		// The id field of the Relationship class.
		private: int^ id;

		// The name field of the Relationship class.
		private: String^ name;

		// The isDeleted field of the Relationship class.
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
        /// Initializes a new instance of the <see cref="Relationship"/> class.
        /// </summary>
		public: Relationship()
		{ }

		/// <summary>
        /// Initializes a new instance of the <see cref="Relationship"/> class.
        /// </summary>
        /// <param name="id">The input value of the id field.</param>
        /// <param name="name">The input value of the name field.</param>
        /// <param name="isdeleted">The input value of the isDeleted field.</param>
		public: Relationship(int^ id, String^ name, bool^ isdeleted)
		{
			this->id = id;
			this->name = name;
			this->isDeleted = isdeleted;
		}

		#pragma endregion

		#pragma region Methods

		#pragma endregion
	};
}