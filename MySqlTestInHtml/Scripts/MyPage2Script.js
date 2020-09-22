// Handles the OnChange event of the select1 control.
function select1OnChange() {
	// An item must be selected in the grid.
	if (!isNaN(document.getElementById("MyPage2SelectSelect").value) && document.getElementById("MyPage2SelectSelect").value > 0) {
		// Get the selected index.
		$id = document.getElementById("MyPage2SelectSelect").value;
	
		// Give the TextBox Value the selected value.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage2GetRelationshipType.php",
			async: true,
			data: {id: $id},
			success: function(result) {
				document.getElementById("MyPage2TypeTextBox").value = result;
			}
		});
	}
	else {
		// Empty the TextBox Value.
		document.getElementById("MyPage2NameTextBox").value = "";
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
	if (document.getElementById("MyPage2TypeTextBox").value !== "") {
		// Add a record.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage2AddRelationship.php",
			async: true,
			data: {
				name: document.getElementById("MyPage2TypeTextBox").value
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
	if (document.getElementById("MyPage2TypeTextBox").value !== "") {
		// An item must be selected.
		if (!isNaN(document.getElementById("MyPage2SelectSelect").value) && document.getElementById("MyPage2SelectSelect").value > 0) {
			// Edit a record.
			$.ajax({
				type: "POST",
				url: "Pages/Ajax/MyPage2EditRelationship.php",
				async: true,
				data: {
					id: document.getElementById("MyPage2SelectSelect").value, 
					name: document.getElementById("MyPage2TypeTextBox").value
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
	if (!isNaN(document.getElementById("MyPage2SelectSelect").value) && document.getElementById("MyPage2SelectSelect").value > 0) {
		// Delete a record.
		$.ajax({
			type: "POST",
			url: "Pages/Ajax/MyPage2DeleteRelationship.php",
			async: true,
			data: {
				id: document.getElementById("MyPage2SelectSelect").value
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
