// Handles the OnChange event of the select1 control.
function select1OnChange() {
	// An item must be selected in the grid.
	if (!isNaN(document.getElementById("MyPage1SelectSelect").value) && document.getElementById("MyPage1SelectSelect").value > 0) {
		// Get the selected index.
		$id = document.getElementById("MyPage1SelectSelect").value;
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1GetPersonName.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage1NameTextBox").value = result;
			}
		});
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1GetPersonMothername.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage1MothernameTextBox").value = result;
			}
		});
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1GetPersonLocation.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage1LocationTextBox").value = result;
			}
		});
		
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1GetPersonBirthdate.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage1BirthdateTextBox").value = result;
			}
		});
	}
	else {
		// Empty the TextBox Values.
		document.getElementById("MyPage1NameTextBox").value = "";
		document.getElementById("MyPage1MothernameTextBox").value = "";
		document.getElementById("MyPage1LocationTextBox").value = "";
		document.getElementById("MyPage1BirthdateTextBox").value = "";
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
	if (document.getElementById("MyPage1NameTextBox").value !== "" && document.getElementById("MyPage1MothernameTextBox").value !== "" && 
		document.getElementById("MyPage1LocationTextBox").value !== "" && document.getElementById("MyPage1BirthdateTextBox").value !== "") {
		// Add a record.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1AddPerson.php",
			async: true,
			data: {
				name: document.getElementById("MyPage1NameTextBox").value, 
				mothername: document.getElementById("MyPage1MothernameTextBox").value, 
				location: document.getElementById("MyPage1LocationTextBox").value, 
				birthdate: document.getElementById("MyPage1BirthdateTextBox").value
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
	if (document.getElementById("MyPage1NameTextBox").value !== "" && document.getElementById("MyPage1MothernameTextBox").value !== "" && 
		document.getElementById("MyPage1LocationTextBox").value !== "" && document.getElementById("MyPage1BirthdateTextBox").value !== "") {
		// An item must be selected.
		if (!isNaN(document.getElementById("MyPage1SelectSelect").value) && document.getElementById("MyPage1SelectSelect").value > 0) {
			// Edit a record.
			$.ajax({
				type: "POST",
				url: "Pages/Ajax/MyPage1EditPerson.php",
				async: true,
				data: {
					id: document.getElementById("MyPage1SelectSelect").value, 
					name: document.getElementById("MyPage1NameTextBox").value, 
					mothername: document.getElementById("MyPage1MothernameTextBox").value, 
					location: document.getElementById("MyPage1LocationTextBox").value, 
					birthdate: document.getElementById("MyPage1BirthdateTextBox").value
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
	if (!isNaN(document.getElementById("MyPage1SelectSelect").value) && document.getElementById("MyPage1SelectSelect").value > 0) {
		// Delete a record.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage1DeletePerson.php",
			async: true,
			data: {
				id: document.getElementById("MyPage1SelectSelect").value
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
