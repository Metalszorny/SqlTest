// Handles the OnChange event of the select1 control.
function select1OnChange() {
	// An item must be selected in the grid.
	if (!isNaN(document.getElementById("MyPage3SelectSelect").value) && document.getElementById("MyPage3SelectSelect").value > 0) {
		// Get the selected index.
		$id = document.getElementById("MyPage3SelectSelect").value;
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage3GetRelationPerson1.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage3Person1ComboBox").value = result;
				
				// Invoke the Selected Index Change methods.
				select2OnChange();
				select3OnChange();
				select4OnChange();
			}
		});
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage3GetRelationRelationship.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage3RelationshipComboBox").value = result;
				
				// Invoke the Selected Index Change methods.
				select2OnChange();
				select3OnChange();
				select4OnChange();
			}
		});
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage3GetRelationPerson2.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage3Person2ComboBox").value = result;
				
				// Invoke the Selected Index Change methods.
				select2OnChange();
				select3OnChange();
				select4OnChange();
			}
		});
	}
	else {
		// Empty the ComboBox Values.
		document.getElementById("MyPage3Person1ComboBox").value = "0";
		document.getElementById("MyPage3RelationshipComboBox").value = "0";
		document.getElementById("MyPage3Person2ComboBox").value = "0";
		
		// Empty the TextBox Values.
		document.getElementById("MyPage3HelperPerson1TextBox").value = "";
		document.getElementById("MyPage3HelperRelationshipTextBox").value = "";
		document.getElementById("MyPage3HelperPerson2TextBox").value = "";
	}
}

// Handles the OnChange event of the select2 control.
function select2OnChange() {
	// The ComboBox value is valid.
	if (!isNaN(document.getElementById("MyPage3Person1ComboBox").value) && document.getElementById("MyPage3Person1ComboBox").value > 0) {
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1GetPersonName.php",
			async: true,
			data: {id: document.getElementById("MyPage3Person1ComboBox").value},
			success: function(result) {
				document.getElementById("MyPage3HelperPerson1TextBox").value = result;
			}
		});
	}
}

// Handles the OnChange event of the select3 control.
function select3OnChange() {
	// The ComboBox value is valid.
	if (!isNaN(document.getElementById("MyPage3RelationshipComboBox").value) && document.getElementById("MyPage3RelationshipComboBox").value > 0) {
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage2GetRelationshipType.php",
			async: true,
			data: {id: document.getElementById("MyPage3RelationshipComboBox").value},
			success: function(result) {
				document.getElementById("MyPage3HelperRelationshipTextBox").value = result;
			}
		});
	}
}

// Handles the OnChange event of the select4 control.
function select4OnChange() {
	// The ComboBox value is valid.
	if (!isNaN(document.getElementById("MyPage3Person2ComboBox").value) && document.getElementById("MyPage3Person2ComboBox").value > 0) {
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1GetPersonName.php",
			async: true,
			data: {id: document.getElementById("MyPage3Person2ComboBox").value},
			success: function(result) {
				document.getElementById("MyPage3HelperPerson2TextBox").value = result;
			}
		});
	}
}

// Handles the OnClick event of the button1 control.
function button1OnClick() {
	// Refresh the page, so the table get refreshed.
	window.location.reload(true);
}

// Handles the OnClick event of the button2 control.
function button2OnClick() {
	// The fields must not be empty.
	if (document.getElementById("MyPage3Person1ComboBox").value !== "" && document.getElementById("MyPage3RelationshipComboBox").value !== "" && 
		document.getElementById("MyPage3Person2ComboBox").value !== "") {
		// Add a record.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage3AddRelation.php",
			async: true,
			data: {
				person1: document.getElementById("MyPage3Person1ComboBox").value, 
				relationship: document.getElementById("MyPage3RelationshipComboBox").value, 
				person2: document.getElementById("MyPage3Person2ComboBox").value
			},
			success: function() {
				// Refresh the page.
				button1OnClick();
			}
		});
	}
}

// Handles the OnClick event of the button3 control.
function button3OnClick() {
	// The fields must not be empty.
	if (document.getElementById("MyPage3Person1ComboBox").value !== "" && document.getElementById("MyPage3RelationshipComboBox").value !== "" && 
		document.getElementById("MyPage3Person2ComboBox").value !== "") {
		// An item must be selected.
		if (!isNaN(document.getElementById("MyPage3SelectSelect").value) && document.getElementById("MyPage3SelectSelect").value > 0) {
			// Edit a record.
			$.ajax({
				type: "POST",
				url: "Pages/Ajax/MyPage3EditRelation.php",
				async: true,
				data: {
					id: document.getElementById("MyPage3SelectSelect").value, 
					person1: document.getElementById("MyPage3Person1ComboBox").value, 
					relationship: document.getElementById("MyPage3RelationshipComboBox").value, 
					person2: document.getElementById("MyPage3Person2ComboBox").value
				},
				success: function() {
					// Refresh the page.
					button1OnClick();
				}
			});
		}
	}
}

// Handles the OnClick event of the button4 control.
function button4OnClick() {
	// An item must be selected.
	if (!isNaN(document.getElementById("MyPage3SelectSelect").value) && document.getElementById("MyPage3SelectSelect").value > 0) {
		// Delete a record.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage3DeleteRelation.php",
			async: true,
			data: {
				id: document.getElementById("MyPage3SelectSelect").value
			},
			success: function() {
				// Refresh the page.
				button1OnClick();
			}
		});
	}
}

// Handles the OnClick event of the button5 control.
function button5OnClick() {
	// Close the page.
	document.location = 'index.html';
}
